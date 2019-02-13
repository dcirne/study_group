// Copyright 2019 Dalmo Cirne
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef Greedy_hpp
#define Greedy_hpp

#include <algorithm>
#include <assert.h>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

//
// GanttTask
//
struct GanttTask final {
    std::string title;
    unsigned int start;
    unsigned int end;

    GanttTask(const unsigned int start, const unsigned int end, const std::string &title) {
        assert(end > start);
        this->start = start;
        this->end = end;
        this->title = title;
    }

    bool operator==(const GanttTask &rhs) const {
        return start == rhs.start && end == rhs.end && title.compare(rhs.title) == 0;
    }

    bool operator!=(const GanttTask &rhs) const {
        return !(*this == rhs);
    }

    unsigned int duration() const {
        return end - start;
    }
};


//
// GreedyScheduling
//
class GreedyScheduling {
public:
    virtual std::vector<GanttTask> schedule() = 0;
};


//
// Project
//
class Project final : GreedyScheduling {
public:
    enum class SortMode : unsigned int {
        EndEarlier = 1,
        StartEarlier,
        LongestFirst,
        ShortestFirst
    };

private:
    std::vector<GanttTask> _tasks;
    std::string _title;
    Project::SortMode _sortMode;

public:
    Project(const std::string &title, Project::SortMode sortMode = Project::SortMode::EndEarlier) {
        assert(!title.empty());
        _title = title;
        _sortMode = sortMode;
    }

    void addTask(const GanttTask &task) {
        _tasks.push_back(task);
    }

    void addTask(GanttTask &&task) {
        _tasks.push_back(task);
    }

    void deleteTask(const GanttTask task) {
        auto tasksIterator = std::find_if(_tasks.cbegin(), _tasks.cend(), [&task](const GanttTask iTask) -> bool {
            return task == iTask;
        });

        if (tasksIterator == _tasks.cend()) {
            return;
        }

        _tasks.erase(tasksIterator);
    }

    void deleteTask(const unsigned int index) {
        if (index >= _tasks.size()) {
            return;
        }

        auto tasksIterator = _tasks.cbegin();
        std::advance(tasksIterator, index);

        if (tasksIterator == _tasks.cend()) {
            return;
        }

        _tasks.erase(tasksIterator);
    }

    void listTasks() const noexcept {
        std::cout << "Tasks for: " << _title << std::endl;

        for (const auto &task : _tasks) {
            std::cout << "  \x1B[0;32mStart: \x1B[0m" << task.start << ", \x1B[0;31mEnd: \x1B[0m" << task.end << ", \x1B[0;36mTitle: \x1B[0m" << task.title << std::endl;
        }

        std::cout << std::endl;
    }

    void listSchedule(const std::vector<GanttTask> &schedule) const noexcept {
        std::cout << "Sprint tasks for: " << _title << std::endl;

        for (const auto &task : schedule) {
            std::cout << "  \x1B[0;32mStart: \x1B[0m" << task.start << ", \x1B[0;31mEnd: \x1B[0m" << task.end << ", \x1B[0;36mTitle: \x1B[0m" << task.title << std::endl;
        }

        std::cout << std::endl;
    }

    std::vector<GanttTask> schedule() {
        assert(!_tasks.empty());

        std::vector<GanttTask> schedule;
        std::function<bool(const GanttTask, const GanttTask)> comparisonFunction;

        switch (_sortMode) {
            case Project::SortMode::EndEarlier:
                comparisonFunction = [](const GanttTask task1, const GanttTask task2) -> bool {
                    return task1.end < task2.end;
                };
                break;

            case Project::SortMode::StartEarlier:
                comparisonFunction = [](const GanttTask task1, const GanttTask task2) -> bool {
                    return task1.start < task2.start;
                };
                break;

            case Project::SortMode::LongestFirst:
                comparisonFunction = [](const GanttTask task1, const GanttTask task2) -> bool {
                    return task1.duration() > task2.duration();
                };
                break;

            case Project::SortMode::ShortestFirst:
                comparisonFunction = [](const GanttTask task1, const GanttTask task2) -> bool {
                    return task1.duration() < task2.duration();
                };
                break;
        }

        std::sort(_tasks.begin(), _tasks.end(), comparisonFunction);

        schedule.push_back(_tasks.front());
        size_t tail = 0;

        for (size_t i = 1; i < _tasks.size(); ++i) {
            if (_tasks[i].start > _tasks[tail].end) {
                schedule.push_back(_tasks[i]);
                tail = i;
            }
        }

        return schedule;
    }

    const std::vector<GanttTask> &tasks() const {
        return _tasks;
    }

    std::string title() const noexcept {
        return _title;
    }
};

#endif

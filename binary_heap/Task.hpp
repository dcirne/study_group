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

#ifndef Task_hpp
#define Task_hpp

#include <ostream>
#include <string>

struct Task {
    enum Priority : unsigned int {
        Highest = 0,
        High,
        Normal,
        Low,
        Lowest,
    };

    Priority priority;
    std::string title;

    Task(const Priority priority = Priority::Lowest) {
        this->priority = priority;
    }

    Task(const std::string &title, const Priority priority = Priority::Normal) {
        this->title = title;
        this->priority = priority;
    }
};

bool operator<(const Task &taskLeft, const Task &taskRight) {
    return taskLeft.priority < taskRight.priority;
}

bool operator>(const Task &taskLeft, const Task &taskRight) {
    return taskLeft.priority > taskRight.priority;
}

std::ostream &operator<<(std::ostream &ostr, const Task &task) {
    std::string priorityName;
    switch (task.priority) {
        case Task::Priority::Highest:
            priorityName = "Highest";
            break;

        case Task::Priority::High:
            priorityName = "High";
            break;

        case Task::Priority::Normal:
            priorityName = "Normal";
            break;

        case Task::Priority::Low:
            priorityName = "Low";
            break;

        case Task::Priority::Lowest:
            priorityName = "Lowest";
            break;
    }

    ostr << priorityName << " - " << task.title;
    return ostr;
}

#endif

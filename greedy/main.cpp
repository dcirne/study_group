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

#include "Greedy.hpp"

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    Project::SortMode sortMode = Project::SortMode::EndEarlier;

    if (argc > 1) {
        const unsigned int sortChoice = atoi(argv[1]);
        assert(sortChoice > 0 && sortChoice < 5);
        sortMode = static_cast<Project::SortMode>(sortChoice);
    }

    std::system("clear");

    GanttTask trailer(9, 120, "Trailer");
    GanttTask casting(20, 63, "Casting");
    GanttTask storyboard(71, 98, "Storyboard");
    GanttTask filming(90, 110, "Filming");
    GanttTask editing(52, 158, "Editing");
    GanttTask extras(37, 68, "Extras");
    GanttTask specialEffects(81, 178, "Special Effects");
    GanttTask release(48, 206, "Release");

    Project wallStreet("Wall Street", sortMode);

    wallStreet.addTask(trailer);
    wallStreet.addTask(casting);
    wallStreet.addTask(storyboard);
    wallStreet.addTask(filming);
    wallStreet.addTask(editing);
    wallStreet.addTask(extras);
    wallStreet.addTask(specialEffects);
    wallStreet.addTask(release);

    wallStreet.addTask(GanttTask(104, 173, "Posters"));
    wallStreet.addTask(GanttTask(123, 163, "Script"));
    wallStreet.addTask(GanttTask(142, 243, "Press"));
    wallStreet.addTask(GanttTask(166, 191, "Budget"));
    wallStreet.addTask(GanttTask(186, 220, "Subtitles"));
    wallStreet.addTask(GanttTask(195, 230, "Illumination"));
    wallStreet.addTask(GanttTask(204, 258, "Sound Effects"));
    wallStreet.addTask(GanttTask(180, 267, "Animation"));

    wallStreet.listTasks();

    while (!wallStreet.tasks().empty()) {
        const auto sprint = wallStreet.schedule();
        wallStreet.listSchedule(sprint);

        for (const auto &task : sprint) {
            wallStreet.deleteTask(task);
        }
    }

    return 0;
}

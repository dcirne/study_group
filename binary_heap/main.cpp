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

#include "BinaryHeap.hpp"
#include "Task.hpp"

#include <iostream>
#include <string>

//
// Forward declarations
//
void simpleExample(const int numberOfItems);
void laborsOfHercules();

//
// main
//
int main(int argc, char *argv[]) {
    int numberOfItems = 5;

    if (argc > 1) {
        numberOfItems = atoi(argv[1]);
    }

    simpleExample(numberOfItems);

    laborsOfHercules();
}

//
// Simple example
//
void simpleExample(const int numberOfItems) {
    BinaryHeap<int> binaryHeap;
    for (int i = numberOfItems - 1; i >= 0; --i) {
        std::cout << std::endl << "\x1B[0;32m" << "Pushed item: " << "\x1B[0m" << i << std::endl;
        binaryHeap.push(i);
    }

    std::cout << std::endl << "----------------" << std::endl << std::endl;

    for (int i = 0; i < numberOfItems - 1; ++i) {
        auto item = binaryHeap.pop();
        std::cout << "\x1B[0;32m" << "Popped item: " << "\x1B[0m" << item << std::endl << std::endl;
    }
}

//
// Labors of Hercules
//
void laborsOfHercules() {
    std::cout << std::endl << "\x1B[0;36m" << "The Twelve Labors of Hercules" << "\x1B[0m" << std::endl;

    BinaryHeap<Task> binaryHeap;
    binaryHeap.displayLog = false;

    Task l1("Slay the Nemean lion.", Task::Priority::Highest);
    binaryHeap.push(l1);

    Task l2("Slay the nine-headed Lernaean Hydra.", Task::Priority::High);
    binaryHeap.push(l2);

    Task l3("Capture the Ceryneian Hind.", Task::Priority::Low);
    binaryHeap.push(l3);

    Task l4("Capture the Erymanthian Boar.", Task::Priority::Low);
    binaryHeap.push(l4);

    Task l5("Clean the Augean stables in a single day.", Task::Priority::Highest);
    binaryHeap.push(l5);

    Task l6("Slay the Stymphalian birds.", Task::Priority::Normal);
    binaryHeap.push(l6);

    binaryHeap.push(Task("Capture the Cretan Bull."));

    binaryHeap.push(Task("Steal the Mares of Diomedes.", Task::Priority::High));

    binaryHeap.push(Task("Obtain the girdle of Hippolyta.", Task::Priority::Normal));

    binaryHeap.push(Task("Obtain the cattle of the monster Geryon.", Task::Priority::Normal));

    binaryHeap.push(Task("Steal the apples of the Hesperides.", Task::Priority::Lowest));

    binaryHeap.push(Task("Capture and bring back Cerberus.", Task::Priority::Normal));

    while (!binaryHeap.empty()) {
        Task labor = binaryHeap.pop();
        std::cout << "\x1B[0;32m" << "  Labor: " << "\x1B[0m" << labor << std::endl;
    }
}

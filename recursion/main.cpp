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

#include "Fibonacci.hpp"
#include "Iterate.hpp"
#include "TowerOfHanoi.hpp"

#include <iostream>
#include <string>

//
// main
//
int main(int argc, char *argv[]) {
    unsigned int numberOfTerms = 6;
    unsigned int numberOfDisks = 3;

    if (argc > 1) {
        numberOfTerms = atoi(argv[1]);
    }

    if (argc > 2) {
        numberOfDisks = atoi(argv[2]);
    }

    // Computes the value of the n^th Fibonacci's term
    Fibonacci fibonacci;
    auto value = fibonacci(numberOfTerms);
    std::cout << "\x1B[0;33mFibonacci: \x1B[0m" << value << std::endl;
    std::cin.get(); // Waits for enter/return to be pressed

    // Uses the cached value of the n^th Fibonacci's term
    value = fibonacci(numberOfTerms);
    std::cout << "\x1B[0;36mFibonacci: \x1B[0m" << value << std::endl;
    std::cin.get(); // Waits for enter/return to be pressed

    // Iterate, recursively, over a string
    printMessage("Open the pod bay doors, please, HAL.");

    std::cin.get(); // Waits for enter/return to be pressed

    // Solves the Tower of Hanoi puzzle
    std::cout << "\x1B[0;31mTower \x1B[0;32mof \x1B[0;34mHanoi\x1B[0m" << std::endl;
    TowerOfHanoi towerOfHanoi(numberOfDisks);
    towerOfHanoi.printState();
    towerOfHanoi.solve();
}

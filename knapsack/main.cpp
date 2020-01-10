// Copyright 2020 Dalmo Cirne
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

#include "Knapsack.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

void printMatrix(const Knapsack &knapsack);

int main() {
    std::vector<unsigned int> weights = {1, 3, 4, 5};
    std::vector<unsigned int> values = {1, 4, 5, 7};
    const size_t capacity = 7;
    Knapsack knapsack(capacity);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
    std::system("clear");
#pragma GCC diagnostic pop
    
    const auto [maxValue, selectedItems] = knapsack(weights, values);

    std::cout << "Max value: " << std::to_string(maxValue) << std::endl;

    std::cout << "Selected items: ";
    for (const auto &item : selectedItems) {
        std::cout << std::to_string(item) << ", ";
    }
    std::cout << std::endl << std::endl;

    printMatrix(knapsack);

    return 0;
}

void printMatrix(const Knapsack &knapsack) {
    const auto numCols = knapsack.matrix().front().size();
    const std::string itemStr("Item");
    const int colWidth = itemStr.size();

    // Header
    std::cout << "|"
              << std::setw(colWidth)
              << std::setfill(' ')
              << std::setiosflags(std::ios::right)
              << itemStr << "|";
    for (size_t i = 0; i < numCols; ++i) {
        std::cout << std::setw(colWidth)
                  << std::setfill(' ')
                  << std::setiosflags(std::ios::right)
                  << std::to_string(i)
                  << "|";
    }
    std::cout << std::endl;

    // Separator line
    std::cout << "|"
              << std::setw(colWidth)
              << std::setfill('-')
              << "-"
              << "|";
    for (size_t i = 0; i < numCols; ++i) {
        std::cout << std::string(colWidth, '-')
                  << "|";
    }
    std::cout << std::endl;

    // Values
    int rowIdx = 0;
    for (const auto &row : knapsack.matrix()) {
        std::cout << "|"
                  << std::setw(colWidth)
                  << std::setfill(' ')
                  << std::setiosflags(std::ios::right)
                  << std::to_string(rowIdx++)
                  << "|";

        for (const auto &col : row) {
            std::cout << std::setw(colWidth)
                      << std::setfill(' ')
                      << std::setiosflags(std::ios::right)
                      << std::to_string(col)
                      << "|";
        }

        std::cout << std::endl;
    }
}

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

#include "IslandCounter.hpp"

#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<Cell>> grid = {
        {Cell(Type::W), Cell(Type::W), Cell(Type::W), Cell(Type::L), Cell(Type::L), Cell(Type::W)}, 
        {Cell(Type::W), Cell(Type::W), Cell(Type::W), Cell(Type::W), Cell(Type::L), Cell(Type::W)}, 
        {Cell(Type::W), Cell(Type::W), Cell(Type::W), Cell(Type::L), Cell(Type::L), Cell(Type::W)}, 
        {Cell(Type::W), Cell(Type::W), Cell(Type::W), Cell(Type::W), Cell(Type::W), Cell(Type::W)}, 
        {Cell(Type::L), Cell(Type::L), Cell(Type::L), Cell(Type::W), Cell(Type::W), Cell(Type::W)}, 
    };

    IslandCounter islandCounter;

    const auto numIslands = islandCounter.count(grid);

    std::cout << "Number of islands: " << numIslands << std::endl;
}

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
#include <string>
#include <vector>

int main() {
    std::vector<std::string> grid = {
        "WWWLLW",
        "WWWWLW",
        "WWWLLW",
        "WWWWWW",
        "LLLWWW",
    };

    IslandCounter islandCounter;

    auto numIslands = islandCounter.count(grid);

    std::cout << "Number of islands (Case 1): " << numIslands << std::endl;
    
    grid = {
        "WWWLLWWLWWWLL",
        "WWWWLWWWLLLWW",
        "WWWLLWLWWWWWW",
        "WWWWWWWLLWWWW",
        "LLLWWWWWWLLLL",
    };

    numIslands = islandCounter.count(grid);

    std::cout << "Number of islands (Case 2): " << numIslands << std::endl;
}

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

#include <iostream>
#include <string>
#include <vector>

const std::string Land = "L";
const std::string Water = "W";
const std::string Visited = "V";

class IslandCounter {
public:
    std::vector<std::string> grid;

    unsigned int count(std::vector<std::string> islandGrid) noexcept {
        grid = islandGrid;
        numRows = grid.size();
        numCols = grid.front().size();
        _numIslands = 0;

        for (size_t i = 0; i < numRows; ++i) {
            for (size_t j = 0; j < numCols; ++j) {
                auto cell = grid.at(i).substr(j, 1);
                if (cell.compare(Visited) == 0) {
                    continue;
                }

                if (cell == Land) {
                    visitAnnexes(i, j);
                    ++_numIslands;
                } else {
                    grid.at(i).replace(j, 1, Visited);
                }
            }
        }

        return _numIslands;
    }

    unsigned int numIslands() const noexcept {
        return _numIslands;
    }

private:
    size_t numRows;
    size_t numCols;
    unsigned int _numIslands;

    void visitAnnexes(const int i, const int j) noexcept {
        if (!validateCoordinates(i, j)) {
            return;
        }

        auto cell = grid.at(i).substr(j, 1);
        if (cell.compare(Visited) == 0 || cell != Land) {
            return;
        }

        grid.at(i).replace(j, 1, Visited);
        std::cout << "Land visited: " << i << ", " << j << std::endl;
        
        for (int row = i - 1; row <= i + 1; ++row) {
            for (int col = j - 1; col <= j + 1; ++col) {
                visitAnnexes(row, col);
            }
        }
    }

    bool validateCoordinates(const int i, const int j) const noexcept {
        return i >= 0 &&
               i < static_cast<int>(numRows) &&
               j >= 0 &&
               j < static_cast<int>(numCols);
    }
};

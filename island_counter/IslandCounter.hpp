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
#include <vector>

enum class Type {
    W, // Water
    L, // Land
};

struct Cell {
    Type type;
    bool visited = false;

    Cell(const Type type) : type(type) {}
};

struct Coord {
    int i;
    int j;

    Coord(const int i, const int j) : i(i), j(j) {}
};

class IslandCounter {
public:
    std::vector<std::vector<Cell>> grid;

    unsigned int count(const std::vector<std::vector<Cell>> &islandGrid) noexcept {
        grid = islandGrid;
        numRows = grid.size();
        numCols = grid.front().size();
        _numIslands = 0;

        for (size_t i = 0; i < numRows; ++i) {
            for (size_t j = 0; j < numCols; ++j) {
                auto &cell = grid[i][j];
                if (cell.visited) {
                    continue;
                }

                if (cell.type == Type::L) {
                    visitAnnexes(Coord(i, j));
                    ++_numIslands;
                } else {
                    cell.visited = true;
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

    void visitAnnexes(Coord &&coord) noexcept {
        if (!validateCoordinates(coord)) {
            return;
        }

        auto &cell = grid[coord.i][coord.j];
        if (cell.visited || cell.type != Type::L) {
            return;
        }

        cell.visited = true;
        std::cout << "Land visited: " << coord.i << ", " << coord.j << std::endl;
        
        visitAnnexes(Coord(coord.i - 1, coord.j)); // North

        visitAnnexes(Coord(coord.i + 1, coord.j)); // South

        visitAnnexes(Coord(coord.i, coord.j + 1)); // East
        
        visitAnnexes(Coord(coord.i, coord.j - 1)); // West
    }

    bool validateCoordinates(const Coord &coord) const noexcept {
        return coord.i >= 0 &&
               coord.i < static_cast<int>(numRows) &&
               coord.j >= 0 &&
               coord.j < static_cast<int>(numCols);
    }
};

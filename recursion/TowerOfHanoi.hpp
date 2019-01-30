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

#ifndef TowerOfHanoi_hpp
#define TowerOfHanoi_hpp

#include <iostream>
#include <string>
#include <vector>

class TowerOfHanoi final {
    std::vector<std::string> leftPeg;
    std::vector<std::string> centerPeg;
    std::vector<std::string> rightPeg;

    unsigned int _numberOfDiscs;
    unsigned int _stepNumber;

    void solve(const unsigned int numerOfDiscs, std::vector<std::string> &sourcePeg, std::vector<std::string> &tempPeg, std::vector<std::string> &destinationPeg) noexcept {
        if (numerOfDiscs == 0) {
            return;
        }

        solve(numerOfDiscs - 1, sourcePeg, destinationPeg, tempPeg);

        destinationPeg.push_back(sourcePeg.back());
        sourcePeg.pop_back();

        ++_stepNumber;
        printState();

        solve(numerOfDiscs - 1, tempPeg, sourcePeg, destinationPeg);
    }

public:
    TowerOfHanoi(const unsigned int numberOfDisks) : _numberOfDiscs(numberOfDisks) {
        leftPeg.reserve(_numberOfDiscs);
        centerPeg.reserve(_numberOfDiscs);
        rightPeg.reserve(_numberOfDiscs);

        for (auto i = _numberOfDiscs; i > 0; --i) {
            leftPeg.push_back(std::to_string(i));
        }

        _stepNumber = 0;
    }

    unsigned int numberOfDiscs() const noexcept {
        return _numberOfDiscs;
    }

    unsigned int stepNumber() const noexcept {
        return _stepNumber;
    }

    void printState() const noexcept {
        std::cout << "Step #: " << _stepNumber << " – ";

        // Left peg
        std::cout << "\x1B[0;31m[ \x1B[0m";
        for (const auto &disc : leftPeg) {
            std::cout << disc << " ";
        }
        std::cout << "\x1B[0;31m]  \x1B[0m";

        // Center peg
        std::cout << "\x1B[0;32m[ \x1B[0m";
        for (const auto &disc : centerPeg) {
            std::cout << disc << " ";
        }
        std::cout << "\x1B[0;32m]  \x1B[0m";

        // Right peg
        std::cout << "\x1B[0;34m[ \x1B[0m";
        for (const auto &disc : rightPeg) {
            std::cout << disc << " ";
        }
        std::cout << "\x1B[0;34m] \x1B[0m" << std::endl;
    }

    void solve() noexcept {
        solve(_numberOfDiscs, leftPeg, centerPeg, rightPeg);
    }
};

#endif

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
#include "LongestSequence.hpp"

#include <iostream>
#include <string>
#include <vector>

void printSequence(const std::string label, const std::vector<std::string> &contiguousSequence) {
    std::cout << label << std::endl;

    if (!contiguousSequence.empty()) {
        for (const auto &item : contiguousSequence) {
            std::cout << '\t' << item << std::endl;
        }
    } else {
        std::cout << '\t' << "(empty)" << std::endl;
    }

    std::cout << std::endl;
}

int main() {
    const std::vector<std::string> sportsList0 = {"Football", "Baseball", "Ice Hockey", "Golf", "Skiing", "F1"};
    const std::vector<std::string> sportsList1 = {"Football", "IndyCar", "Lacrosse", "Baseball", "Ice Hockey", "Golf", "Basketball"};
    const std::vector<std::string> sportsList2 = {"F1", "Softball", "Curling"};
    const std::vector<std::string> sportsList3 = {
        "Skiing", "Golf", "Soccer", "IndyCar", "Lacrosse", "Rugby", "Swimming", "Tennis", "Badminton", "Handball"};
    const std::vector<std::string> sportsList4 = {"Skiing", "Golf", "Tennis", "Volleyball", "IndyCar", "Lacrosse",
        "Rugby", "Swimming", "Cricket", "Badminton", "Handball"};
    const std::vector<std::string> sportsList5 = {"F1"};

    auto contiguousSequence = findLongestSequence(sportsList0, sportsList1);
    printSequence("findLongestSequence(sportsList0, sportsList1)", contiguousSequence);

    contiguousSequence = findLongestSequence(sportsList1, sportsList2);
    printSequence("findLongestSequence(sportsList1, sportsList2)", contiguousSequence);

    contiguousSequence = findLongestSequence(sportsList2, sportsList0);
    printSequence("findLongestSequence(sportsList2, sportsList0)", contiguousSequence);

    contiguousSequence = findLongestSequence(sportsList5, sportsList2);
    printSequence("findLongestSequence(sportsList5, sportsList2)", contiguousSequence);

    contiguousSequence = findLongestSequence(sportsList3, sportsList4);
    printSequence("findLongestSequence(sportsList3, sportsList4)", contiguousSequence);

    contiguousSequence = findLongestSequence(sportsList4, sportsList3);
    printSequence("findLongestSequence(sportsList4, sportsList3)", contiguousSequence);

    return 0;
}

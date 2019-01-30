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
#include <optional>
#include <string>

struct Person {
    std::string firstName;
    std::optional<std::string> middleName;
    std::string lastName;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Not enough parameters" << std::endl;
        return 1;
    }

    Person person;
    person.firstName = argv[1];

    if (argc > 3) {
        person.middleName = argv[2];
        person.lastName = argv[3];
    } else {
        person.lastName = argv[2];
    }

    std::cout << "Hello " << person.firstName << " ";

    // if (person.middleName.has_value()) {
    //     std::cout << *(person.middleName) << " ";
    // }
    std::cout << person.middleName.value_or("(no middle name)") << " ";

    std::cout << person.lastName << " ";

    std::cout << std::endl;

    std::optional<int> i;
    i = 42;
    if (i) {
        std::cout << *i << std::endl;
    } else {
        std::cout << "i has no value." << std::endl;
    }

    return 0;
}

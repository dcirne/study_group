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

#ifndef Iterate_hpp
#define Iterate_hpp

#include <iostream>
#include <string>

void printMessage(const std::string &message, const unsigned int idx = 0) {
    if (idx == message.length()) {
        std::cout << "\x1B[0m" << std::endl;
        return;
    }

    const std::string character = message.substr(idx, 1);
    int color = idx % 7 + 31;
    printf("\x1B[0;%dm", color);
    std::cout << character;

    printMessage(message, idx + 1);
}

#endif
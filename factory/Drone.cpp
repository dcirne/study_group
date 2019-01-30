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

#ifndef Drone_cpp
#define Drone_cpp

#include <iostream>
#include <string>
#include <vector>

enum class Color {
    Black,
    DarkGray,
    VeryDarkGrey,
};

class Blade {
public:
    Blade() = default;
};

class Battery {
public:
    Battery() = default;
    double capacity = 314.15;
};

class Drone {
public:
    Drone() : model("1.6.1") {
        color = Color::Black;
        wingSpan = 28;
    }

    Color color;
    std::vector<Blade> blades;
    Battery battery;
    double wingSpan;
    std::string model;

    void printDescription() const noexcept {
        std::cout << std::endl << "Drone Description:" << std::endl;
        std::cout << "  Model: " << model << std::endl;
        std::cout << "  Color: " << static_cast<int>(color) << std::endl;
        std::cout << "  Number of blades: " << blades.size() << std::endl;
        std::cout << "  Battery capacity: " << battery.capacity << std::endl;
        std::cout << "  Wingspan: " << wingSpan << std::endl;
    }
};

#endif

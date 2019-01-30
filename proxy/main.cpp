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

#include "Image.hpp"
#include "ImageProxy.hpp"

#include <iostream>
#include <string>

// Bash colors
enum class Color : unsigned int {
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Purple = 35,
    Cyan = 36,
};

// Print color string
void print(const std::string message, const Color color) {
    printf("\e[0;%dm", static_cast<unsigned int>(color));
    std::cout << message << std::endl;
    printf("\e[0m");
}

//
// main
//
int main(int argc, char *argv[]) {
    print("Using Image", Color::Yellow);
    Image image("AT-AT_Walker.txt");
    print("Image dimensions: " + std::to_string(image.height()) + "x" + std::to_string(image.width()), Color::Cyan);
    image.draw("Drawing from Image");

    std::cout << std::endl;
    print("Using ImageProxy", Color::Yellow);
    ImageProxy imageProxy("AT-AT_Walker.txt");
    print("ImageProxy dimensions: " + std::to_string(imageProxy.height()) + "x" + std::to_string(imageProxy.width()), Color::Cyan);
    imageProxy.draw("Drawing from ImageProxy");
    imageProxy.draw("Drawing from ImageProxy, again");

    return 0;
}

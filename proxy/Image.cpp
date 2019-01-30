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

#include <chrono>
#include <iostream>
#include <fstream>
#include <future>
#include <stdio.h>
#include <thread>

Image::Image(const std::string fileName) : _fileName(fileName) {
    loadImage();
}

void Image::loadImage() {
    std::this_thread::sleep_for(std::chrono::seconds(3));

    _height = 0;
    _width = 0;
    std::string lineString;

    std::ifstream inputFile(_fileName, std::ios::in);
    if (inputFile.is_open()) {
        while (getline(inputFile, lineString)) {
            auto lineWidth = lineString.size();
            if (lineWidth > _width) {
                _width = lineWidth;
            }

            _imageBuffer.push_back(lineString);
        }

        inputFile.close();
        _height = _imageBuffer.size();
    }
}

void Image::draw(const std::string message) {
    auto drawingThread = std::async(std::launch::async, [this, &message]() {
        std::cout << message << std::endl;

        for (const auto &lineString : _imageBuffer) {
            std::cout << lineString << std::endl;
        }
    });

    drawingThread.get();
}

unsigned int Image::height() noexcept {
    return _height;
}

unsigned int Image::width() noexcept {
    return _width;
}

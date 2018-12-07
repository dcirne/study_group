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

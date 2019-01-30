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

#include "ImageProxy.hpp"

#include <iostream>

ImageProxy::ImageProxy(const std::string fileName) {
    _fileName = fileName;
}

Image *ImageProxy::image() {
    if (_image == nullptr) {
        _image = std::make_unique<Image>(_fileName);
    }

    return _image.get();
}

void ImageProxy::draw(const std::string message) {
    if (_image == nullptr) {
        std::cout << "Drawing placeholder frame" << std::endl;
        std::cout << "+--------------------------------------------+" << std::endl;
        for (auto i = 0; i < height() - 2; ++i) {
            std::cout << "|                                            |" << std::endl;
        }
        std::cout << "+--------------------------------------------+" << std::endl;
    }

    image()->draw(message);
}

unsigned int ImageProxy::height() noexcept {
    return _image == nullptr ? 21 : image()->height();
}

unsigned int ImageProxy::width() noexcept {
    return _image == nullptr ? 44 : image()->width();
}

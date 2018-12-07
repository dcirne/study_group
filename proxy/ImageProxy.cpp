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

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

#ifndef ImageProxy_hpp
#define ImageProxy_hpp

#include "Image.hpp"

#include <memory>
#include <string>

class ImageProxy : public Image {
    std::unique_ptr<Image> _image;

protected:
    Image *image();

public:
    ImageProxy(const std::string fileName);
    virtual ~ImageProxy() = default;

    virtual void draw(const std::string message) override;
    virtual unsigned int height() noexcept override;
    virtual unsigned int width() noexcept override;
};

#endif

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

#ifndef Image_hpp
#define Image_hpp

#include <string>
#include <vector>

class Image {
    unsigned int _height;
    unsigned int _width;

    void loadImage();

protected:
    std::vector<std::string> _imageBuffer;
    std::string _fileName;

public:
    Image() = default;
    Image(const std::string fileName);
    virtual ~Image() = default;

    virtual void draw(const std::string message);
    virtual unsigned int height() noexcept;
    virtual unsigned int width() noexcept;
};

#endif

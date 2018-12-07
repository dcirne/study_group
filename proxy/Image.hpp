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

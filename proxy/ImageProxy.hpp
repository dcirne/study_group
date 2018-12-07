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

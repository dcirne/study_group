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

#ifndef Drone_cpp
#define Drone_cpp

#include <iostream>
#include <string>
#include <vector>

enum class Color {
    Black,
    DarkGray,
    VeryDarkGrey,
};

class Blade {
public:
    Blade() = default;
};

class Battery {
public:
    Battery() = default;
    double capacity = 314.15;
};

class Drone {
public:
    Drone() : model("1.6.1") {
        color = Color::Black;
        wingSpan = 28;
    }

    Color color;
    std::vector<Blade> blades;
    Battery battery;
    double wingSpan;
    std::string model;

    void printDescription() const noexcept {
        std::cout << std::endl << "Drone Description:" << std::endl;
        std::cout << "  Model: " << model << std::endl;
        std::cout << "  Color: " << static_cast<int>(color) << std::endl;
        std::cout << "  Number of blades: " << blades.size() << std::endl;
        std::cout << "  Battery capacity: " << battery.capacity << std::endl;
        std::cout << "  Wingspan: " << wingSpan << std::endl;
    }
};

#endif

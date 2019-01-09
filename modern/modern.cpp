/*
    delete,
    noexcept
    override,
    default,
    scoped enum,
    const iterator
*/

#include <iostream>
#include <memory>
#include <string>
#include <vector>

template<class T>
class Operators {
public:
    int subtract(const T a, const T b) noexcept { return a - b; }
    int subtract(const char a, const char b) = delete;
    int subtract(const double a, const double b) = delete;
};

class Base {
public:
    virtual void mf1() const noexcept { std::cout << "Base mf1" << std::endl; }
    virtual void mf2(int x) noexcept { std::cout << "Base mf2" << std::endl; }
    virtual void mf3() & noexcept { std::cout << "Base mf3" << std::endl; }
    void mf4() const noexcept { std::cout << "Base mf4" << std::endl; }
};

class Derived: public Base {
public:
    virtual void mf1() noexcept { std::cout << "Derived mf1" << std::endl; }
    virtual void mf2(unsigned int x) noexcept { std::cout << "Derived mf2" << std::endl; }
    virtual void mf3() && noexcept { std::cout << "Derived mf3" << std::endl; }
    void mf4() const noexcept { std::cout << "Derived mf4" << std::endl; }
};

// class Base {
// public:
//     virtual ~Base() = default;

//     virtual void mf1() const noexcept { std::cout << "Base mf1" << std::endl; }
//     virtual void mf2(int x) noexcept { std::cout << "Base mf2" << std::endl; }
//     virtual void mf3() & noexcept { std::cout << "Base mf3" << std::endl; }
//     virtual void mf4() const noexcept { std::cout << "Base mf4" << std::endl; }
// };

// class Derived : public Base {
// public:
//     void mf1() const noexcept override { std::cout << "Derived mf1" << std::endl; }
//     void mf2(int x) noexcept override { std::cout << "Derived mf2" << std::endl; }
//     void mf3() & noexcept override { std::cout << "Derived mf3" << std::endl; }
//     void mf4() const noexcept override { std::cout << "Derived mf4" << std::endl; }
// };

int main(int argc, char *argv[]) {
    //
    // Enum and Scoped Enum
    //
    enum RGBEnum {
        ColorRed = 0,
        ColorGreen,
        ColorBlue,
    };

    enum class RGB : uint8_t {
        Red = 0,
        Green,
        Blue,
    };

    // float ColorBlue = 3.14;

    RGBEnum color = ColorRed;
    if (color == static_cast<int>(RGB::Red)) {
        std::cout << "Colors are equal" << std::endl;
    }

    RGB rgb = RGB::Green;
    // auto greenVal = static_cast<uint8_t>(rgb);
    auto greenVal = static_cast<int>(rgb);

    std::cout << "Green value: " << greenVal << std::endl;

    //
    // Delete
    //
    std::cout << std::endl;
    Operators<int> operators;
    std::cout << "Operators result: " << operators.subtract(42, 14) << std::endl;
    // std::cout << "Operators result: " << operators.subtract('B', 'A') << std::endl;
    // std::cout << "Operators result: " << operators.subtract(3.14, 1.608) << std::endl;

    //
    // Override
    //
    std::cout << std::endl;
    Derived d;
    Base &b = d;
    d.mf1();
    d.mf2(6);
    b.mf3(); // b?? What is going on here?
    // std::forward<Derived>(d).mf3();
    d.mf4();

    // std::unique_ptr<Base> ptrClass = std::make_unique<Derived>();
    // ptrClass->mf1();
    // ptrClass->mf2(28);
    // ptrClass->mf3();
    // ptrClass->mf4();

    //
    // Const iterator
    //
    std::cout << std::endl;
    std::vector<int> perfectNumbers {6, 28, 496, 8128};

    // for (auto iterator = perfectNumbers.begin(); iterator != perfectNumbers.end(); ++iterator) {
    for (auto iterator = perfectNumbers.cbegin(); iterator != perfectNumbers.cend(); ++iterator) {
        std::cout << *iterator << " is a perfect number." << std::endl;

        // *iterator = 42;
        // std::cout << *iterator << " ?" << std::endl;
    }

    return 0;
}

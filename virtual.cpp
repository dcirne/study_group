#include <iostream>
#include <string>

class Base {
private:
    std::string _val;

protected:
    Base(const std::string val) : _val(val) {}

public:
    std::string description() const { return "base class"; }
    virtual std::string name() const { return "base"; }
    std::string val() const { return _val; }
};

class Derived : public Base {
public:
    Derived(const std::string val) : Base(val) {}

    std::string description() const { return "derived class"; }
    std::string name() const override { return "derived"; }
};

void refFunc(const Base &b) {
    std::cout << "refFunc – Class description is: " << b.description() << std::endl;
    std::cout << "refFunc – Class name is: " << b.name() << std::endl;
    std::cout << "refFunc – Val is: " << b.val() << std::endl;
}

void ptrFunc(const Base *b) {
    if (b == nullptr) {
        return;
    }

    std::cout << "ptrFunc – Class description is: " << b->description() << std::endl;
    std::cout << "ptrFunc – Class name is: " << b->name() << std::endl;
    std::cout << "ptrFunc – Val is: " << b->val() << std::endl;
}

int main(int argc, char *argv[]) {
    Derived d("42");
    std::cout << "1. Class description is: " << d.description() << std::endl;

    Base &b1 = d;
    std::cout << "2. Class description is: " << b1.description() << std::endl;

    Base *b2 = &d;
    std::cout << "3. Class description is: " << b2->description() << std::endl;

    std::cout << "4. Class name is: " << b1.name() << std::endl;
    std::cout << "5. Class name is: " << b2->name() << std::endl;

    std::cout << "6. Val is: " << d.val() << std::endl;
    std::cout << "7. Val is: " << b1.val() << std::endl;
    std::cout << "8. Val is: " << b2->val() << std::endl;

    refFunc(d);

    ptrFunc(&d);

    return 0;
}

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

/*
    inheritance,
    polymorphism,
    virtual,
    noexcept,
    override,
    final
*/

#include <iostream>
#include <string>

class Base {
private:
    std::string _val;

protected:
    Base(const std::string val) : _val(val) {}

public:
    std::string description() const noexcept { return "base class"; }
    virtual std::string name() const noexcept { return "base"; }
    std::string val() const noexcept { return _val; }
};

class Derived final : public Base {
public:
    Derived(const std::string val) : Base(val) {}

    std::string description() const noexcept { return "derived class"; }
    std::string name() const noexcept override { return "derived"; }
};

// class SecondDerivation : public Derived {
// public:
//     SecondDerivation(const std::string val) : Derived(val) {}
// };

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

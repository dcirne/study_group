#ifndef Batmobile_hpp
#define Batmobile_hpp

#include "Command.hpp"

#include <assert.h>
#include <iostream>
#include <string>

//
// Batmobile (Receiver)
//
class Batmobile {
public:
    void atomicBatteriesToPower() {
        std::cout << "Vroom" << std::endl;
    }

    void helloThisIsBatman() {
        std::cout << "Hello Commissioner Gordon, this is Batman speaking." << std::endl;
    }

    void buckleUp() {
        std::cout << "Swish, grab" << std::endl;
    }
};

//
// IgnitionOn (Concrete command)
//
class IgnitionOn final : public Command {
    Batmobile *_batmobile;

public:
    IgnitionOn(Batmobile *batmobile) : _batmobile(batmobile) {
        assert(_batmobile != nullptr);
    }

    void execute() noexcept override {
        if (_batmobile == nullptr) {
            return;
        }

        _batmobile->atomicBatteriesToPower();
    }
};

//
// AnswerBatphone (Concrete command)
//
class AnswerBatphone final : public Command {
    Batmobile *_batmobile;

public:
    AnswerBatphone(Batmobile *batmobile) : _batmobile(batmobile) {
        assert(_batmobile != nullptr);
    }

    void execute() noexcept override {
        if (_batmobile == nullptr) {
            return;
        }

        _batmobile->helloThisIsBatman();
    }
};

//
// LaunchGrapple (Concrete command)
//
class LaunchGrapple final : public Command {
    Batmobile *_batmobile;

public:
    LaunchGrapple(Batmobile *batmobile) : _batmobile(batmobile) {
        assert(_batmobile != nullptr);
    }

    void execute() noexcept override {
        if (_batmobile == nullptr) {
            return;
        }

        _batmobile->buckleUp();
    }
};

#endif

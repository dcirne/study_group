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

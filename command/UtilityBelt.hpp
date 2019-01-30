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

#ifndef UtilityBelt_hpp
#define UtilityBelt_hpp

#include "Command.hpp"

#include <assert.h>
#include <iostream>
#include <string>

//
// UtilityBelt (Receiver)
//
class UtilityBelt {
public:
    void shootGrappleGun() {
        std::cout << "To infinity and beyond. (Oh, wait. That is a Buzz Lightyear line.)" << std::endl;
    }

    void dischargeEMP() {
        std::cout << "100%, Push, Zap!" << std::endl;
    }
};

//
// BatCommand (Concrete command)
//
template<class Batclass>
class BatCommand final : public Command {
public:
    typedef void (Batclass::* Action)();

    BatCommand(Batclass *batclass, Action action) : _batclass(batclass), _action(action) {
        assert(_batclass != nullptr);
        assert(_action != nullptr);
    }

    virtual void execute() noexcept override {
        if (_batclass == nullptr || _action == nullptr) {
            return;
        }

        (_batclass->*_action)();
    }

private:
    Batclass *_batclass;
    Action _action;
};

#endif

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

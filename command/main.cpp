#include "Batmobile.hpp"
#include "UtilityBelt.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

// Bash colors
enum class Color : unsigned int {
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Purple = 35,
    Cyan = 36,
    LightGray = 37,
};

// Prints a colored string
void print(const std::string message, const Color color) {
    printf("\x1B[0;%dm", static_cast<unsigned int>(color));
    std::cout << message << std::endl;
    printf("\x1B[0m");
}

//
// Function prototypes
//
void executeMovingUniquePointers(Batmobile &batmobile, UtilityBelt &utilityBelt);
void executeWithReferencesToPointers(Batmobile &batmobile, UtilityBelt &utilityBelt);

//
// main
//
int main(int argc, char *argv[]) {
    // Receivers
    Batmobile batmobile;
    UtilityBelt utilityBelt;

    executeMovingUniquePointers(batmobile, utilityBelt);

    executeWithReferencesToPointers(batmobile, utilityBelt);
}

// Code runs by moving unique pointers into a vector (thus transfering ownership)
void executeMovingUniquePointers(Batmobile &batmobile, UtilityBelt &utilityBelt) {
    std::cout << std::endl;
    print("executeMovingUniquePointers", Color::Yellow);
    print("===========================", Color::Cyan);

    // Concrete commands
    IgnitionOn ignitionOn(&batmobile);
    ignitionOn.execute();

    AnswerBatphone answerBatphone(&batmobile);
    answerBatphone.execute();

    print("------", Color::Cyan);

    // Vector of concrete commands
    std::vector<std::unique_ptr<Command>> commands;
    auto c1 = std::make_unique<IgnitionOn>(&batmobile);
    auto c2 = std::make_unique<AnswerBatphone>(&batmobile);
    auto c3 = std::make_unique<LaunchGrapple>(&batmobile);
    commands.push_back(std::move(c1));
    commands.push_back(std::move(c2));
    commands.push_back(std::move(c3));

    // More concrete commands
    auto bc1 = std::make_unique<BatCommand<UtilityBelt>>(&utilityBelt, &UtilityBelt::shootGrappleGun);
    auto bc2 = std::make_unique<BatCommand<UtilityBelt>>(&utilityBelt, &UtilityBelt::dischargeEMP);
    commands.push_back(std::move(bc1));
    commands.push_back(std::move(bc2));

    // Iterate and execute all commands in the vector
    for (auto &command : commands) {
        command->execute();
    }
}

// Code runs by adding references to unique pointers to a vector
void executeWithReferencesToPointers(Batmobile &batmobile, UtilityBelt &utilityBelt) {
    std::cout << std::endl;
    print("executeWithReferencesToPointers", Color::Yellow);
    print("===============================", Color::Cyan);

    // Concrete commands
    IgnitionOn ignitionOn(&batmobile);
    ignitionOn.execute();

    AnswerBatphone answerBatphone(&batmobile);
    answerBatphone.execute();

    print("------", Color::Cyan);

    // Vector of concrete commands
    std::vector<Command *> commands;
    auto c1 = std::make_unique<IgnitionOn>(&batmobile);
    auto c2 = std::make_unique<AnswerBatphone>(&batmobile);
    auto c3 = std::make_unique<LaunchGrapple>(&batmobile);
    commands.push_back(c1.get());
    commands.push_back(c2.get());
    commands.push_back(c3.get());

    // More concrete commands
    auto bc1 = std::make_unique<BatCommand<UtilityBelt>>(&utilityBelt, &UtilityBelt::shootGrappleGun);
    auto bc2 = std::make_unique<BatCommand<UtilityBelt>>(&utilityBelt, &UtilityBelt::dischargeEMP);
    commands.push_back(bc1.get());
    commands.push_back(bc2.get());

    // Iterate and execute all commands in the vector
    for (auto &command : commands) {
        command->execute();
    }
}

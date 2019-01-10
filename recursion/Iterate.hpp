#ifndef Iterate_hpp
#define Iterate_hpp

#include <iostream>
#include <string>

void printMessage(const std::string &message, const unsigned int idx = 0) {
    if (idx == message.length()) {
        std::cout << "\x1B[0m" << std::endl;
        return;
    }

    const std::string character = message.substr(idx, 1);
    int color = idx % 7 + 31;
    printf("\x1B[0;%dm", color);
    std::cout << character;

    printMessage(message, idx + 1);
}

#endif

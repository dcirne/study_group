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

#include "BalancedTree.hpp"

#include <iostream>
#include <string>
#include <vector>

//
// Forward declarations
//
void simpleExample();
void decodeMessage(const std::vector<std::string> &message);

//
// main
//
int main() {
    simpleExample();

    std::vector<std::string> message = {".", "-.", "..", "--.", "--", ".-"};
    decodeMessage(message);
}

//
// Simple example
//
void simpleExample() {
    BalancedTree<int> balancedTree;

    balancedTree.insert("49", 1);
    balancedTree.insert("51", 3);
    balancedTree.insert("53", 5);
    balancedTree.insert("55", 7);
    balancedTree.insert("57", 9);

    balancedTree.insert("50", 2);
    balancedTree.insert("52", 4);
    balancedTree.insert("54", 6);
    balancedTree.insert("56", 8);

    balancedTree.print();

    std::vector<std::string> asciis{"52", "50", "99"};

    std::cout << std::endl
              << "\x1B[0;32m"
              << "The answer: "
              << "\x1B[0m";
    for (const auto &code : asciis) {
        auto [value, success] = balancedTree.find(code);
        if (success) {
            std::cout << value;
        } else {
            std::cout << std::endl
                      << "\x1B[0;31m"
                      << "Not found: "
                      << "\x1B[0m" << code << std::endl;
        }
    }

    std::cout << std::endl;
}

//
// Morse code
//
void decodeMessage(const std::vector<std::string> &message) {
    BalancedTree<std::string> morseTable;

    morseTable.insert(".", "E");
    morseTable.insert("-", "T");
    morseTable.insert("..", "I");
    morseTable.insert(".-", "A");
    morseTable.insert("-.", "N");
    morseTable.insert("--", "M");
    morseTable.insert("...", "S");
    morseTable.insert("..-", "U");
    morseTable.insert(".-.", "R");
    morseTable.insert(".--", "W");
    morseTable.insert("-..", "D");
    morseTable.insert("-.-", "K");
    morseTable.insert("--.", "G");
    morseTable.insert("---", "O");
    morseTable.insert("....", "H");
    morseTable.insert("...-", "V");
    morseTable.insert("..-.", "F");
    morseTable.insert(".-..", "L");
    morseTable.insert(".--.", "P");
    morseTable.insert(".---", "J");
    morseTable.insert("-...", "B");
    morseTable.insert("-..-", "X");
    morseTable.insert("-.-.", "C");
    morseTable.insert("-.--", "Y");
    morseTable.insert("--..", "Z");
    morseTable.insert("--.-", "Q");
    morseTable.insert(".....", "5");
    morseTable.insert("....-", "4");
    morseTable.insert("...--", "3");
    morseTable.insert("..---", "2");
    morseTable.insert(".----", "1");
    morseTable.insert("-....", "6");
    morseTable.insert("--...", "7");
    morseTable.insert("---..", "8");
    morseTable.insert("----.", "9");
    morseTable.insert("-----", "0");

    morseTable.print();

    std::cout << std::endl
              << "\x1B[0;32m"
              << "Decoded message: "
              << "\x1B[0m";
    for (const auto &code : message) {
        auto [value, success] = morseTable.find(code);
        if (success) {
            std::cout << value;
        }
    }

    std::cout << std::endl << std::endl;
}

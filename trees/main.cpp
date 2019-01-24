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

#include "Algorithms.hpp"
#include "TreeNode.hpp"

#include <iostream>
#include <string>

//
// Forward declarations (function prototypes)
//
void numbers();
void avengersAssemble();

//
// main
//
int main(int argc, char *argv[]) {
    std::string option("numbers");

    if (argc > 1) {
        option = argv[1];
    }

    if (option.compare("numbers") == 0) {
        numbers();
    } else if (option.compare("avengers") == 0) {
        avengersAssemble();
    } else {
        std::cout << "\x1B[0;31mNot an option.\x1B[0m" << std::endl;
        return 1;
    }

    return 0;
}

//
// Numbers
//
void numbers() {
    BinaryTreeNode<int> one(1);
    BinaryTreeNode<int> two(2);
    BinaryTreeNode<int> three(3);
    BinaryTreeNode<int> four(4);
    BinaryTreeNode<int> five(5);
    BinaryTreeNode<int> six(6);
    BinaryTreeNode<int> seven(7);
    BinaryTreeNode<int> eight(8);
    BinaryTreeNode<int> nine(9);
    BinaryTreeNode<int> ten(10);
    BinaryTreeNode<int> eleven(11);
    BinaryTreeNode<int> twelve(12);
    BinaryTreeNode<int> thirteen(13);

    one.left = &two;
    one.right = &three;
    two.left = &four;
    two.right = &five;
    three.left = &six;
    three.right = &seven;
    four.left = &eight;
    four.right = &nine;
    five.left = &ten;
    five.right = &eleven;
    six.left = &twelve;
    six.right = &thirteen;

    std::cout << "\x1B[0;32mTree size: \x1B[0m";
    std::cout << treeSize(&one);
    std::cout << std::endl;

    std::cout << "\x1B[0;35mHeight of node 'three': \x1B[0m";
    std::cout << heightOfNode(&three);
    std::cout << std::endl;

    std::cout << "\x1B[0;36mDepth-First: \x1B[0m" << std::endl;
    depthFirstTraverse<int>(&one);

    std::cout << "\x1B[0;33mBreadth-First: \x1B[0m" << std::endl;
    breadthFirstTraverse<int>(&one);
}

//
// Avengers assemble
//
void avengersAssemble() {
    // Avengers
    BinaryTreeNode<std::string> winterSoldier("Winter Soldier");
    BinaryTreeNode<std::string> captainAmerica("+ Captain America");
    BinaryTreeNode<std::string> hawkeye("+ Hawkeye");
    BinaryTreeNode<std::string> falcon("+ Falcon");
    BinaryTreeNode<std::string> antMan("+ Ant-Man");
    BinaryTreeNode<std::string> scarlet("+ Scarlet Witch");

    std::string superHeroName("– Iron Man");
    BinaryTreeNode<std::string> ironMan(superHeroName);
    superHeroName = "– War Machine";
    BinaryTreeNode<std::string> warMachine(superHeroName);
    superHeroName = "– Black Widow";
    BinaryTreeNode<std::string> blackWidow(superHeroName);
    superHeroName = "– Black Panther";
    BinaryTreeNode<std::string> blackPanther(superHeroName);
    superHeroName = "– Vision";
    BinaryTreeNode<std::string> vision(superHeroName);
    superHeroName = "– Spider-Man";
    BinaryTreeNode<std::string> spiderMan(superHeroName);

    // Root node
    winterSoldier.left = &ironMan;
    winterSoldier.right = &captainAmerica;

    // Team Captain America
    captainAmerica.left = &hawkeye;
    captainAmerica.right = &falcon;
    hawkeye.left = &scarlet;
    falcon.left = &antMan;

    // Team Iron Man
    ironMan.left = &blackWidow;
    ironMan.right = &warMachine;
    blackWidow.left = &blackPanther;
    blackWidow.right = &spiderMan;
    warMachine.left = &vision;

    std::cout << "\x1B[0;32mTree size: \x1B[0m";
    std::cout << treeSize(&winterSoldier);
    std::cout << std::endl;

    std::cout << "\x1B[0;35mHeight of node 'Iron Man': \x1B[0m";
    std::cout << heightOfNode(&ironMan);
    std::cout << std::endl;

    std::cout << "\x1B[0;36mDepth-First: \x1B[0m" << std::endl;
    depthFirstTraverse<std::string>(&winterSoldier);

    std::cout << "\x1B[0;33mBreadth-First: \x1B[0m" << std::endl;
    breadthFirstTraverse<std::string>(&winterSoldier);
}

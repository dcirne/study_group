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

#ifndef Algorithms_hpp
#define Algorithms_hpp

#include "TreeNode.hpp"

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

//
// Tree size
//
template<typename T>
unsigned int treeSize(BinaryTreeNode<T> *node) {
    if (node == nullptr) {
        return 0;
    }

    return 1 + treeSize(node->left) + treeSize(node->right);
}

//
// Height of node
//
template<typename T>
int heightOfNode(BinaryTreeNode<T> *node) {
    if (node == nullptr) {
        return -1;
    }

    return 1 + std::max(heightOfNode(node->left), heightOfNode(node->right));
}

//
// Depth First Traverse
//
template<typename T>
void depthFirstTraverse(BinaryTreeNode<T> *node) {
    if (node == nullptr) {
        return;
    }

    std::cout << '\t' << node->value << std::endl;
    depthFirstTraverse(node->left);
    depthFirstTraverse(node->right);
}

//
// Breadth First Traverse
//
template<typename T>
void breadthFirstTraverse(BinaryTreeNode<T> *node) {
    if (node == nullptr) {
        std::cout << "Empty tree" << std::endl;
        return;
    }

    std::queue<BinaryTreeNode<T> *> traverseQueue;
    traverseQueue.push(node);

    while (!traverseQueue.empty()) {
        BinaryTreeNode<T> *btn = traverseQueue.front();
        traverseQueue.pop();
        std::cout << '\t' << btn->value << std::endl;

        if (btn->left != nullptr) {
            traverseQueue.push(btn->left);
        }

        if (btn->right != nullptr) {
            traverseQueue.push(btn->right);
        }
    }
}

#endif

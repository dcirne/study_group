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

#ifndef BalancedTree_hpp
#define BalancedTree_hpp

#include "Node.hpp"

#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <tuple>

template<class T>
class BalancedTree {
    Node<T> *_root = nullptr;

    int balance(const Node<T> *node) const noexcept {
        return height(node->right) - height(node->left);
    }

    void deleteNodeAndChildren(Node<T> *node) {
        if (node == nullptr) {
            return;
        }

        if (node->left != nullptr) {
            deleteNodeAndChildren(node->left);
            delete node->left;
            node->left = nullptr;
        }

        if (node->right != nullptr) {
            deleteNodeAndChildren(node->right);
            delete node->right;
            node->right = nullptr;
        }

        node = nullptr;
    }

    std::tuple<T, bool> find(const std::string &key, const Node<T> *node) const noexcept {
        if (node == nullptr) {
            return std::make_tuple(T{}, false);
        }

        const auto keyComparison = key.compare(node->key);

        if (keyComparison == 0) {
            return std::make_tuple(node->value, true);
        } else {
            Node<T> *nextNode = keyComparison < 0 ? node->left : node->right;
            return find(key, nextNode);
        }
    }

    int height(const Node<T> *node) const noexcept {
        return node != nullptr ? node->height : -1;
    }

    Node<T> *insert(const std::string &key, const T value, Node<T> *node) {
        if (node == nullptr) {
            node = new Node<T>(key, value);
        } else {
            const auto keyComparison = key.compare(node->key);

            if (keyComparison < 0) {
                node->left = insert(key, value, node->left);

                if (balance(node) == -2) {
                    node = key.compare(node->left->key) < 0 ? rotateLeft(node) : doubleRotateLeft(node);
                }
            } else if (keyComparison > 0) {
                node->right = insert(key, value, node->right);

                if (balance(node) == 2) {
                    node = key.compare(node->right->key) > 0 ? rotateRight(node) : doubleRotateRight(node);
                }
            } else {
                node->value = value;
            }
        }

        node->height = std::max(height(node->left), height(node->right)) + 1;

        return node;
    }

    void print(const Node<T> *node, const std::string &prefix, const unsigned int indentation) const noexcept {
        if (node == nullptr) {
            return;
        }

        std::string spaces(2 * indentation, ' ');
        std::cout << spaces << "\x1B[0;32m"
                  << "["
                  << "\x1B[0;34m" << prefix << "\x1B[0;32m"
                  << "]"
                  << "\x1B[0m" << *node << std::endl;
        print(node->left, "L", indentation + 1);
        print(node->right, "R", indentation + 1);
    }

    Node<T> *rotateLeft(Node<T> *node) {
        Node<T> *t = node->left;
        node->left = t->right;
        t->right = node;

        node->height = std::max(height(node->left), height(node->right)) + 1;
        t->height = std::max(height(t->left), node->height) + 1;

        return t;
    }

    Node<T> *rotateRight(Node<T> *node) {
        Node<T> *t = node->right;
        node->right = t->left;
        t->left = node;

        node->height = std::max(height(node->left), height(node->right)) + 1;
        t->height = std::max(height(t->right), node->height) + 1;

        return t;
    }

    Node<T> *doubleRotateLeft(Node<T> *node) {
        node->left = rotateRight(node->left);
        return rotateLeft(node);
    }

    Node<T> *doubleRotateRight(Node<T> *node) {
        node->right = rotateLeft(node->right);
        return rotateRight(node);
    }

    public:
    virtual ~BalancedTree() {
        deleteNodeAndChildren(_root);
    }

    std::tuple<T, bool> find(const std::string &key) const noexcept {
        return find(key, _root);
    }

    void insert(const std::string &key, const T value) {
        _root = insert(key, value, _root);
    }

    void print() const noexcept {
        print(_root, "Root", 0);
    }
};

#endif

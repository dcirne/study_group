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

#ifndef Node_hpp
#define Node_hpp

#include <ostream>
#include <string>

template<class T>
struct Node {
    Node *left = nullptr;
    Node *right = nullptr;
    std::string key;
    T value;
    int height;

    Node(const std::string &key, T value) {
        this->key = key;
        this->value = value;
        height = 0;
    }

    virtual ~Node() {
    }

    bool operator==(const Node &rhs) const {
        return key.compare(rhs.key) == 0;
    }

    bool operator!=(const Node &rhs) const {
        return !(*this == rhs);
    }
};

template<class T>
bool operator<(const Node<T> &lhs, const Node<T> &rhs) {
    return lhs.key.compare(rhs.key) < 0;
}

template<class T>
bool operator>(const Node<T> &lhs, const Node<T> &rhs) {
    return lhs.key.compare(rhs.key) > 0;
}

template<class T>
std::ostream &operator<<(std::ostream &ostr, const Node<T> &node) {
    ostr << "Key: \""
         << "\x1B[0;36m" << node.key << "\x1B[0m"
         << "\", Value: "
         << "\x1B[0;36m" << node.value << "\x1B[0m"
         << ", Height: "
         << "\x1B[0;36m" << node.height << "\x1B[0m";
    return ostr;
}

#endif

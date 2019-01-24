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

#ifndef TreeNode_hpp
#define TreeNode_hpp

template<class T>
class BinaryTreeNode {
    public:
    BinaryTreeNode<T> *parent = nullptr;
    BinaryTreeNode<T> *left = nullptr;
    BinaryTreeNode<T> *right = nullptr;
    T value;

    BinaryTreeNode() = default;

    BinaryTreeNode(const T &value) {
        this->value = value;
    }

    BinaryTreeNode(T &&value) {
        this->value = value;
    }

    virtual ~BinaryTreeNode() {
        parent = left = right = nullptr;
    }
};

#endif

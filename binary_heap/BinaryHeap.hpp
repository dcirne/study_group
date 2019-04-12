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

#ifndef BinaryHeap_hpp
#define BinaryHeap_hpp

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template<class T>
class BinaryHeap {
protected:
    std::vector<T> _items;

    void bubbleUp(unsigned int i) noexcept {
        printItems("Bubble up");
        auto p = parentIndex(i);

        while (i > 0 && _items[i] < _items[p]) {
            std::swap(_items[i], _items[p]);
            i = p;
            p = parentIndex(i);
            printItems();
        }
    }

    int leftChildIndex(const unsigned int i) const noexcept {
        return 2 * i + 1;
    }

    int parentIndex(const unsigned int i) const noexcept {
        return (i - 1) / 2;
    }

    void printItems(const std::string title = "") const noexcept {
        if (!displayLog || _items.empty()) {
            return;
        }

        if (!title.empty()) {
            std::cout << "  \x1B[0;32m" << title << "\x1B[0m" << std::endl;
        }

        std::cout << "    \x1B[0;31m[ \x1B[0m" << _items.front();

        for (size_t i = 1; i < _items.size(); ++i) {
            std::cout << "\x1B[0;34m | \x1B[0m" << _items.at(i);
        }
        std::cout << "\x1B[0;31m ]\x1B[0m" << std::endl;
    }

    int rightChildIndex(const unsigned int i) const noexcept {
        return 2 * i + 2;
    }

    void trickleDown(int i) noexcept {
        printItems("Trickle down");
        const int numberOfItems = static_cast<int>(_items.size());

        do {
            const int j = [this, &i, &numberOfItems]() {
                const int r = rightChildIndex(i);
                const int l = leftChildIndex(i);

                if (r < numberOfItems && _items[r] < _items[i]) {
                    return _items[l] < _items[r] ? l : r;
                } else if (l < numberOfItems && _items[l] < _items[i]) {
                    return l;
                }

                return -1;
            }();

            if (j >= 0) {
                std::swap(_items[i], _items[j]);
            }

            i = j;
            printItems();
        } while (i >= 0);
    }

public:
    bool displayLog = true;

    BinaryHeap() {}

    virtual ~BinaryHeap() {}

    void clear() noexcept {
        _items.clear();
    }

    bool empty() const noexcept {
        return _items.empty();
    }

    T pop() noexcept {
        if (_items.size() == 0) {
            return T();
        }

        T item = _items.front();
        _items[0] = _items.back();
        _items.pop_back();
        trickleDown(0);

        return item;
    }

    void push(const T &item) noexcept {
        _items.push_back(item);
        bubbleUp(_items.size() - 1);
    }

    void push(T &&item) noexcept {
        _items.push_back(item);
        bubbleUp(_items.size() - 1);
    }

    size_t size() const noexcept {
        return _items.size();
    }
};

#endif

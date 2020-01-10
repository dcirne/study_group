// Copyright 2020 Dalmo Cirne
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

#ifndef Knapsack_hpp
#define Knapsack_hpp

#include <algorithm>
#include <assert.h>
#include <tuple>
#include <vector>

class Knapsack final {
    std::vector<std::vector<unsigned int>> _matrix;
    size_t _capacity;

    unsigned int computeMaxValue(const std::vector<unsigned int> &weights,
                                 const std::vector<unsigned int> &values)
    {
        for (size_t item = 1; item < _matrix.size(); ++item) {
            for (size_t c = 1; c <= _capacity; ++c) {
                const auto prevItem = item - 1;

                _matrix[item][c] = std::max((weights[prevItem] <= c) * (values[prevItem] + _matrix[prevItem][c - weights[prevItem]]),
                                            _matrix[prevItem][c]);
            }
        }

        const auto maxValue = _matrix[_matrix.size() - 1][_capacity];
        return maxValue;
    }

    std::vector<unsigned int> findSelectedItems(const std::vector<unsigned int> &weights) {
        std::vector<unsigned int> selectedItems;
        auto row = static_cast<unsigned int>(weights.size() - 1);
        auto col = static_cast<unsigned int>(_capacity);

        while (row > 0 && _matrix[row][col] != 0) {
            const auto prevRow = row - 1;

            if (_matrix[row][col] != _matrix[prevRow][col]) {
                selectedItems.push_back(row);
            }

            row = prevRow;
            col -= weights[prevRow];
        }

        return selectedItems;
    }

public:
    const std::vector<std::vector<unsigned int>> &matrix() const noexcept {
        return _matrix;
    }

    Knapsack(const size_t capacity) : _capacity(capacity) {}

    std::tuple<unsigned int, std::vector<unsigned int>>
    operator()(const std::vector<unsigned int> &weights, const std::vector<unsigned int> &values) noexcept {
        assert(weights.size() == values.size());
        const auto numberOfItems = weights.size();
        _matrix.clear();
        _matrix.resize(numberOfItems + 1,
                       std::vector<unsigned int>(_capacity + 1, 0));

        const auto maxValue = computeMaxValue(weights, values);

        const auto selectedItems = findSelectedItems(weights);

        return std::make_tuple(maxValue, selectedItems);
    }
};

#endif

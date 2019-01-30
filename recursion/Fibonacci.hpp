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

#ifndef Fibonacci_hpp
#define Fibonacci_hpp

class Fibonacci final {
    unsigned int _numberOfTerms = 0;
    unsigned int _computedResult = 0;

    unsigned int compute(const unsigned int term) const noexcept {
        if (term < 2) {
            return term;
        }

        const auto result = compute(term - 1) + compute(term - 2);

        return result;
    }

public:
    Fibonacci() = default;

    unsigned int operator()(const unsigned int numberOfTerms) noexcept {
        if (_numberOfTerms != numberOfTerms || _computedResult == 0) {
            _numberOfTerms = numberOfTerms;
            _computedResult = compute(_numberOfTerms);
        }

        return _computedResult;
    }
};

#endif

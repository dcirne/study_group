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
#include <algorithm>
#include <map>
#include <string>
#include <vector>

std::vector<std::string> findLongestSequence(const std::vector<std::string> &sequence1, const std::vector<std::string> &sequence2) {
    std::map<std::string, std::vector<std::string>> sequences;
    std::vector<std::string> result;
    int previousIdx = -1;

    for (auto seq1It = sequence1.begin(); seq1It != sequence1.end(); ++seq1It) {
        const auto seq2It = std::find(sequence2.begin(), sequence2.end(), *seq1It);

        if (seq2It != sequence2.end()) {
            const auto idx = std::distance(sequence2.begin(), seq2It);

            if (!result.empty() && idx != previousIdx + 1) {
                result.clear();
            }

            result.push_back(*seq1It);
            previousIdx = idx;
            sequences[*seq1It] = result;
        }
    }

    std::string longestKey;
    size_t longestLength = 0;
    for (auto it = sequences.begin(); it != sequences.end(); ++it) {
        if (sequences[it->first].size() > longestLength) {
            longestKey = it->first;
            longestLength = sequences[longestKey].size();
        }
    }

    return sequences[longestKey];
}

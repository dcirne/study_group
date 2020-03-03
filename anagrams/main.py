# Copyright 2020 Dalmo Cirne
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
from enum import auto
from enum import Enum
from time import time
from typing import List


class FindAlgorithm(Enum):
    DICTIONARY = auto()
    NESTED_LOOP = auto()


def find_anagrams_dict(input_list: List[str]) -> List[str]:
    anagrams = set()
    len_input_list = len(input_list)
    anagrams_dict = {}

    for item in input_list:
        sorted_item = "".join(sorted(item))

        if sorted_item in anagrams_dict:
            anagrams_dict[sorted_item].add(item)
        else:
            anagrams_dict[sorted_item] = set([item])

    for val in anagrams_dict.values():
        if len(val) > 1:
            anagrams = anagrams.union(val)

    return sorted(anagrams, key=len)


def find_anagrams_nested_loop(input_list: List[str]) -> List[str]:
    anagrams = set()
    len_input_list = len(input_list)

    for idx, item in enumerate(input_list):
        sorted_item = "".join(sorted(item))

        next_idx = idx + 1
        if next_idx >= len_input_list:
            break

        for nested_idx in range(next_idx, len_input_list):
            nested_item = input_list[nested_idx]
            if len(item) != len(nested_item):
                continue

            sorted_nested_item = "".join(sorted(nested_item))
            if sorted_item == sorted_nested_item:
                anagrams.add(item)
                anagrams.add(nested_item)

    return sorted(anagrams, key=len)


def find_anagrams(input_list: List[str], find_algorithm: FindAlgorithm) -> List[str]:
    if find_algorithm == FindAlgorithm.DICTIONARY:
        return find_anagrams_dict(input_list)
    elif find_algorithm == FindAlgorithm.NESTED_LOOP:
        return find_anagrams_nested_loop(input_list)
    else:
        return None


if __name__ == "__main__":
    words_list = ['bat', 'rats', 'god', 'dog', 'cat', 'arts', 'star',
                  'acres', 'cares', 'races', 'scare', 'alert', 'alter', 'later',
                  'lab', 'lag', 'nod', 'aligned', 'dealing', 'leading', 'banana']
    expected_anagrams = ['rats', 'god', 'dog', 'arts', 'star', 'acres', 'cares',
                       'races', 'scare', 'alert', 'alter', 'later', 'aligned',
                       'dealing', 'leading']
    non_anagrams = ['bat', 'cat', 'lab', 'lag', 'nod', 'banana']

    print("List of words:\n\t{0}\n".format(words_list))

    for algorithm in FindAlgorithm:
        start = time()
        anagrams = find_anagrams(words_list, algorithm)
        end = time()

        assert isinstance(anagrams, list)
        for anagram in expected_anagrams:
            assert anagram in anagrams

        for non_anagram in non_anagrams:
            assert non_anagram not in anagrams

        print("Anagrams ({0}):\n\t{1}\n\ttime: {2:2.8f} sec\n".format(algorithm, anagrams, end - start))

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
import json
from typing import Dict
from typing import List


def flatten_dictionary(source_dict: Dict, target_dict: Dict, key: str = "") -> Dict[str, List[str]]:
    for k, v in source_dict.items():
        dict_key = k if len(key.strip()) == 0 else key + "." + k

        if isinstance(v, dict):
            for nested_k, nested_v in flatten_dictionary(v, target_dict, dict_key).items():
                target_dict[nested_k] = nested_v
        else:
            if dict_key in target_dict:
                if hasattr(v, '__iter__'):
                    target_dict[dict_key].extend(v)
                else:
                    target_dict[dict_key].append(v)
            else:
                target_dict[dict_key] = v if hasattr(v, '__iter__') else [v]

    return target_dict


def parse_string(input_str: str) -> Dict:
    json_dict = json.loads(input_str)
    return json_dict


if __name__ == "__main__":
    str1 = '{"a": 1, "c": {"a": 2, "b": {"x": 5, "y": [10, 11]}}, "d": [1, 2, 3]}'
    str2 = '{"a": [3, 5], "c": {"a": 2, "b": {"x": [6], "y": 12}}, "d": [1, 2, 3]}'
    str3 = '{"a": 7, "c": {"e": 42, "b": {"x": 9, "y": [13]}}, "d": 4}'
    flatten_dict = {}

    for payload in [str1, str2, str3]:
        nested_dict = parse_string(payload)

        flatten_dict = flatten_dictionary(nested_dict, flatten_dict)

    print("{0}".format(flatten_dict))

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

#include <iostream>
#include <string>
#include <variant>

enum class SoftwareTrait {
    Fast,
    Stable,
    Easy,
};

int main(int argc, char *argv[]) {
    std::variant<SoftwareTrait, int, float, std::string> code {SoftwareTrait::Fast};
    std::variant<SoftwareTrait, int, float, std::string> codeCheck;

    // code = SoftwareTrait::Fast;

    SoftwareTrait *pCode = std::get_if<SoftwareTrait>(&code);
    if (pCode != nullptr) {
        std::cout << "`code` is Fast." << std::endl;
    }

    code = 84;
    pCode = std::get_if<SoftwareTrait>(&code);
    if (pCode == nullptr) {
        std::cout << "`code` does not contain a SoftwareTrait." << std::endl;
    }

    codeCheck = code;
    int *pCodeCheck = std::get_if<int>(&codeCheck);
    if (pCodeCheck != nullptr) {
        std::cout << "`codeCheck` is " << *pCodeCheck << std::endl;
    }

    codeCheck = SoftwareTrait::Stable;
    pCodeCheck = std::get_if<int>(&codeCheck);
    if (pCodeCheck == nullptr) {
        std::cout << "`codeCheck` does not contain an int." << std::endl;
    }

    code = static_cast<float>(3.1415);
    float *fCode = std::get_if<float>(&code);
    std::cout << *fCode << std::endl;

    code = "What the meaning of life, the universe and everything?";
    std::string *sCode = std::get_if<std::string>(&code);
    std::cout << *sCode << std::endl;

    return 0;
}

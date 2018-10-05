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

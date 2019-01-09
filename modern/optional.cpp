#include <iostream>
#include <optional>
#include <string>

struct Person {
    std::string firstName;
    std::optional<std::string> middleName;
    std::string lastName;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Not enough parameters" << std::endl;
        return 1;
    }

    Person person;
    person.firstName = argv[1];

    if (argc > 3) {
        person.middleName = argv[2];
        person.lastName = argv[3];
    } else {
        person.lastName = argv[2];
    }

    std::cout << "Hello " << person.firstName << " ";

    // if (person.middleName.has_value()) {
    //     std::cout << *(person.middleName) << " ";
    // }
    std::cout << person.middleName.value_or("(no middle name)") << " ";

    std::cout << person.lastName << " ";

    std::cout << std::endl;

    std::optional<int> i;
    i = 42;
    if (i) {
        std::cout << *i << std::endl;
    } else {
        std::cout << "i has no value." << std::endl;
    }

    return 0;
}

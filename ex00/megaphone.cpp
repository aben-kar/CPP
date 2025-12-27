#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char** av) {
    if (argc <= 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; av[i]; i++) {
        for (int j = 0; av[i][j]; j++) {
            char c = av[i][j];
            if (c >= 'a' && c <= 'z')
                c = std::toupper(c);
            std::cout << c;
        }
    }

    std::cout << std::endl;
    return 0;
}
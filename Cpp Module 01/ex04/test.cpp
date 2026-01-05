#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string str1 = "Hello ";
    std::string str2 = "World!";
    
    // str1.append(str2); 
    // std::cout << "After appending str2: " << str1 << std::endl;

    str1.append(str2, 0, 2); // " di"
    std::cout << "After appending part of c-string: " << str1 << std::endl; // Output: Hello World! di

    str1.append(4, '!');
    std::cout << "After appending multiple chars: " << str1 << std::endl; // Output: Hello World! di!!!

    return 0;
}

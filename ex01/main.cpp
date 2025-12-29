#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(int ac, char **av)
{
    (void)av;
    PhoneBook phoneBook;
    if (ac == 1)
    {
        std::string input;;
        while (1)
        {
            std::cout << "Enter command (ADD, SEARCH, or EXIT): ";
            if (!std::getline(std::cin, input)) // EOF (Ctrl+D)
                break;

            if (input == "ADD")
                phoneBook.AddContact();
            else if (input == "SEARCH")
                phoneBook.SearchContact();
            else if (input =="EXIT")
                break;
            else
                std::cout << "Error: Invalid argument. Please use ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    else
        std::cout << "Error: This program does not take any arguments." << std::endl;
    return 0;
}
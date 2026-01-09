#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    if (ac == 2)
    {
        std::string arg = av[1];
        int level = levelIndex(arg);

        switch (level)
        {
        case 0:
            harl.complain("DEBUG");
        case 1:
            harl.complain("INFO");
        case 2:
            harl.complain("WARNING");
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
        }
    }
    else
        std::cout << "Error: Invalid argument." << std::endl;

    return 0;
}
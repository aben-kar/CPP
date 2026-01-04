#include "Zombie.hpp"

int main()
{
    std::cout << BLUE "Zombie HeapZombie created!" RESET << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    std::cout << CYAN "Zombie StackZombie created!" RESET << std::endl;
    randomChump("StackZombie");
    delete heapZombie;
    return 0;
}

#include "Zombie.hpp"

int main()
{
    std::cout << "Zombie HeapZombie created!" << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    std::cout << "Zombie StackZombie created!" << std::endl;
    randomChump("StackZombie");
    delete heapZombie;
    return 0;
}

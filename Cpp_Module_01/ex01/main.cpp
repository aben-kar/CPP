#include "Zombie.hpp"

int main()
{
    int N = 12;
    Zombie* horde = zombieHorde(N, "Foo");

    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}
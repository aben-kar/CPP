#include <iostream>

class Animal
{
    public:
        void makeSound() const {
            std::cout << "Animal Sound" << std::endl;
        }
};

class Cat : public Animal {
    public:
        void makeSound() const {
            std::cout << "Cat Sound" << std::endl;
        }
};


int main()
{
    Animal *obj;
    Cat c;
    c.makeSound();
    obj->makeSound();
}
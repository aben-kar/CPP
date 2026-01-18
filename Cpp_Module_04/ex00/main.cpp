#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // --- PART 1: The Correct Implementation (Polymorphism) ---
    std::cout << "===== CORRECT ANIMAL TESTS =====" << std::endl;
    
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    // std::cout << "meta type " << meta->getType() << " " << std::endl;
    // std::cout << "j type: " << j->getType() << " " << std::endl;
    // std::cout << "i type: " << i->getType() << " " << std::endl;

    i->makeSound(); // will output the cat sound! (Meow!)
    j->makeSound(); // will output the dog sound! (Woof!)
    meta->makeSound(); // will output the generic animal sound

    // Dima delete what you allocated with 'new'
    delete meta;
    delete j;
    delete i;

    std::cout << "\n===== WRONG ANIMAL TESTS =====" << std::endl;

    // --- PART 2: The Wrong Implementation (Static Binding) ---
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    // std::cout << "wrongCat type: " << wrongCat->getType() << " " << std::endl;

    // This is the trap! 
    // Even though it's a WrongCat, it will call WrongAnimal::makeSound()
    // because the function is NOT virtual.
    wrongCat->makeSound(); 
    wrongMeta->makeSound();

    // Memory cleanup
    delete wrongMeta;
    delete wrongCat; 
    // Note: Since ~WrongAnimal is not virtual, ~WrongCat() won't be called!

    return 0;
}
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	std::cout << "--- Test 1: Creating Animals ---\n";
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	dog->makeSound();
	cat->makeSound();

	std::cout << "\n--- Test 2: Testing Deep Copy ---\n";
	Dog *_dog = new Dog();
	_dog->makeSound();
	Dog *_dogCopier = new Dog(*_dog);
	_dogCopier->makeSound();

	std::cout << "\n--- Test 3: Array of Animals ---\n";
	Animal *animals[4];

	for(int i = 0; i < 2; i++){
		animals[i] = new Dog();
	}
	
	for(int i = 2; i < 4; i++){
		animals[i] = new Cat();
	}

	for(int i = 0; i < 4; i++){
		animals[i]->makeSound();
	}

	std::cout << "\n--- Cleanup (Destructors) ---\n";
	delete dog;
	delete cat;
	delete _dog;
	delete _dogCopier;
	for(int i = 0; i < 4; i++) {
		delete animals[i];
	}
}
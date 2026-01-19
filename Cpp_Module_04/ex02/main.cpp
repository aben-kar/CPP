#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== Simple Test: Understanding Polymorphism & Deep Copy ===\n\n";
	
	std::cout << "--- Test 1: Creating Animals ---\n";
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << "\nType: " << dog->getType() << std::endl;
	dog->makeSound();
	
	std::cout << "\nType: " << cat->getType() << std::endl;
	cat->makeSound();
	
	// -----------------Test 2: Deep copy with Brain---------------
	std::cout << "\n\n--- Test 2: Testing Deep Copy ---\n";
	Dog* originalDog = new Dog();
	std::cout << "Created original dog\n";
	
	Dog* copiedDog = new Dog(*originalDog);  // Copy constructor
	std::cout << "Created copied dog (should have its own brain)\n";
	
	// ---------------------Test 3: Array of animals----------------------
	std::cout << "\n\n--- Test 3: Array of Animals ---\n";
	Animal* animals[4];
	
	std::cout << "Creating 2 dogs and 2 cats...\n";
	for (int i = 0; i < 2; i++) {
		animals[i] = new Dog();
	}
	for (int i = 2; i < 4; i++) {
		animals[i] = new Cat();
	}
	
	std::cout << "\nMaking sounds:\n";
	for (int i = 0; i < 4; i++) {
		animals[i]->makeSound();
	}
	
	std::cout << "\n\n--- Cleanup (Destructors) ---\n";
	delete dog;
	delete cat;
	delete originalDog;
	delete copiedDog;
	
	for (int i = 0; i < 4; i++) {
		delete animals[i];
	}
	
	std::cout << "\n=== Test Complete ===\n";
	return 0;

}

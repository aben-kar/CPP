#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructed." << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructed." << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor." << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain copy assignment operator." << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
    }
    return *this;
}
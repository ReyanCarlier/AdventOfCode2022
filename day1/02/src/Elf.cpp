#include "Elf.hpp"

Elf::Elf() : calories(0) {}

Elf::Elf(Elf const & src)
{
	*this = src;
}

Elf::~Elf() {}

Elf & Elf::operator=(Elf const & rhs)
{
	if (this != &rhs)
	{
		this->calories = rhs.calories;
	}
	return *this;
}

int Elf::getCalories(void) const
{
	return this->calories;
}

void Elf::setCalories(int calories)
{
	this->calories = calories;
}

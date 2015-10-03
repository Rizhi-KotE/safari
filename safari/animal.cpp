#include "stdafx.h"
#include "Animal.h"

/*Animal::Animal(double weight, int age, bool gender)
{
	this->weight = weight;
	this->age = age;
	this->gender = gender;
	std::cout << "Born\n";
}*/
void Animal::setAge(int age)
{
	this->age = age;
}
int Animal::getAge()
{
	return age;
}
void Animal::setWeight(double weight)
{
	this->weight = weight;
}
double Animal::getWeight()
{
	return weight;
}
void Animal::setGender(bool gender)
{
	this->gender = gender;
}
bool Animal::getGender()
{
	return gender;
}
Animal::~Animal()
{
	std::cout << "Die\n";
}
void Animal::eat()
{
	std::cout << "OM NOM NOM\n";
}
string & Animal::getName()
{
	return name;
}
Animal::Animal()
{
	std::cout << "born\n";
}
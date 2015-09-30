#include "stdafx.h"
#include "animal.h"

animal::animal(double weight, int age, bool gender)
{
	this->weight = weight;
	this->age = age;
	this->gender = gender;
	std::cout << "Born\n";
}
void animal::setAge(int age)
{
	this->age = age;
}
int animal::getAge()
{
	return age;
}
void animal::setWeight(double weight)
{
	this->weight = weight;
}
double animal::getWeight()
{
	return weight;
}
void animal::setGender(bool gender)
{
	this->gender = gender;
}
bool animal::getGender()
{
	return gender;
}
animal::~animal()
{
	std::cout << "Die\n";
}
void animal::eat()
{
	std::cout << "OM NOM NOM\n";
}
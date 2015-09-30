#pragma once
#include "stdafx.h"
using namespace std;

class Plant;
class Area;

	class Animal
	{
		double weight;
		int age;
		bool gender;
		string name;
	public:
		Animal();
		//Animal(double weight = 0, int age = 0, bool gender = true, string name = "animal");
		void setWeight(double weight = 1);
		double getWeight();
		void setAge(int age = 0);
		int getAge();
		void setGender(bool gender);
		bool getGender();
		void eat();
		void talk();
		~Animal();
		string & getName();
		void reproduction(Plant *);
		void a(Area);
	};




#pragma once
#include "stdafx.h"
	class animal
	{
		double weight;
		int age;
		bool gender;
	public:
		animal(double weight = 0, int age = 0, bool gender = true);
		void setWeight(double weight = 1);
		double getWeight();
		void setAge(int age = 0);
		int getAge();
		void setGender(bool gender);
		bool getGender();
		void eat();
		void talk();
		~animal();
	};
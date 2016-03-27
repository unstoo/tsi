#pragma once
#include "precompiled.h"

class data {

	char name[20];
	unsigned int age;

public:
	data() : name("_blank"), age(0) {}

	friend std::ostream& operator<<(std::ostream& os, const data& obj)
	{
		os << obj.name << " " << obj.age << "\r\n";
		return os;
	}

	friend std::istream& operator>>(std::istream& is, data& obj) {
		is >> obj.name >> obj.age;
		return is;
	}

	void display_formatted() const {
		cout << "|" << std::setw(20) << name << " | ";
		cout << std::setw(5) << age << " |";
		cout << endl;
	}

	void get_data() {
		cout << "Enter name: ";
		cin.get(name, strlen(name), '\n');
		age = get_integer(14, 128, "Student's age:");
	}
};

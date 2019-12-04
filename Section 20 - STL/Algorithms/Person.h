#pragma once
#include <string>

class Person {
	std::string name;
	int age;
public:
	Person() = default;
	Person(std::string name, int age);
	bool operator<(const Person& rhs);
	bool operator==(const Person& rhs);

};
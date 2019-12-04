#include "Person.h"

Person::Person(std::string name, int age) 
	: name{ name }, age{ age } {
}

bool Person::operator<(const Person& rhs) {
	return age < rhs.age;
}
bool Person::operator==(const Person& rhs) {
	return (name == rhs.name && age == rhs.age);
}
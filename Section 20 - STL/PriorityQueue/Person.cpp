#include "Person.h"
#include <string>

std::ostream &operator<<(std::ostream &os, const Person &p) {
	os << p.name << ":" << p.age;
	return os;
}

Person::Person(std::string name, int age)
	: name{ name }, age{ age }  {
}
bool Person::operator<(const Person &rhs) const {
	return this->age < rhs.age;
}
bool Person::operator==(const Person &rhs) const {
	return (this->name == rhs.name && this->age == rhs.age);
}
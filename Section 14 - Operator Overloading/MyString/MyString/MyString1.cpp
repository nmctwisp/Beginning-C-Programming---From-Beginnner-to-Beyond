#define  _CRT_SECURE_NO_WARNINGS
#include "MyString1.h"
#include <cstring>
#include <cctype>

std::ostream &operator<<(std::ostream& os, const MyString1& rhs) {
	// Insertion Operator
	os << rhs.str;

	return os;
}

std::istream &operator>>(std::istream& in, MyString1& rhs) {
	// Extraction Operator
	char* buff = new char[1000];
	in >> buff;
	
	rhs = MyString1{ buff };

	delete[] buff;

	return in;
}

MyString1::MyString1() 
	: str{nullptr} {
	// No-Args Constructor
	this->str = new char[1];
	*(this->str) = '\0';
}

MyString1::MyString1(const char* source)
	: str{ nullptr } {
	// Overloaded Constructor
	if (source == nullptr) {
		this->str = new char[1];
		*(this->str) = '\0';
	}
	else {
		this->str = new char[std::strlen(source) + 1];
		std::strcpy(this->str, source);
	}
}

MyString1::MyString1(const MyString1& source)
	: str{ nullptr } {
	// Copy Constructor
	this->str = new char[std::strlen(source.str) + 1];
	std::strcpy(this->str, source.str);
}

MyString1::MyString1(MyString1&& source)
	: str{ source.str } {
	// Move Constructor
	source.str = nullptr;
}	

MyString1::~MyString1() {
	// Destructor
	delete[] this->str;
}

MyString1 &MyString1::operator=(const MyString1& rhs) {
	//Copy Assignment
	if (this == &rhs) {
		return *this;
	}

	delete[] this->str;
	this->str = new char[std::strlen(rhs.str) + 1];
	std::strcpy(this->str, rhs.str);
	
	return *this;
}

MyString1 &MyString1::operator=(MyString1&& rhs) {
	// Move Assignment
	if (this == &rhs) {
		return *this;
	}

	delete[] this->str;
	this->str = rhs.str;
	rhs.str = nullptr;

	return *this;
}

MyString1& MyString1::operator+=(const MyString1& rhs) {
	// Concatenate and Assign Operator
	*this = *this + rhs;

	return *this;
}

MyString1& MyString1::operator*=(int n) {
	// Repeat and Assign Operator
	*this = *this * n;

	return *this;
}

MyString1& MyString1::operator++() {
	// Make Uppercase Operator via Pre-Increment Operator
	for (size_t i = 0; i < std::strlen(this->str); i++) {
		this->str[i] = std::toupper(this->str[i]);
	}

	return *this;
}

MyString1 MyString1::operator-() const {
	// Make Lowercase Operator
	char* buff = new char[std::strlen(this->str) + 1];
	std::strcpy(buff, this->str);

	for (size_t i = 0; i < std::strlen(buff); i++) {
		buff[i] = std::tolower(buff[i]);
	}

	MyString1 temp{ buff };
	delete[] buff;
	
	return temp;
}

MyString1 MyString1::operator+(const MyString1& rhs) const {
	// Concatenate Operator
	char* buff = new char[std::strlen(this->str) + std::strlen(rhs.str) + 1];
	std::strcpy(buff, this->str);
	std::strcat(buff, rhs.str);

	MyString1 temp{ buff };
	delete[] buff;
	
	return temp;
}

bool MyString1::operator==(const MyString1& rhs) const {
	// Equality Operator
	bool result = (std::strcmp(this->str, rhs.str) == 0);

	return result;
}

bool MyString1::operator!=(const MyString1& rhs) const {
	// Inequality Operator
	bool result = (std::strcmp(this->str, rhs.str) != 0);

	return result;
}

bool MyString1::operator<(const MyString1& rhs) const {
	// Less-Than Operator
	bool result = (std::strcmp(this->str, rhs.str) < 0);

	return result;
}

bool MyString1::operator>(const MyString1& rhs) const {
	// Greater-Than Operator
	bool result = (std::strcmp(this->str, rhs.str) > 0);

	return result;
}

MyString1 MyString1::operator*(int n) const {
	// Repeat Operator
	MyString1 temp;
	for (size_t i = 0; i <= n; i++) {
		temp = temp + *this;
	}

	return temp;
}

MyString1 MyString1::operator++(int n) {
	// Make Uppercase Operator via Post-Increment Operator
	MyString1 temp{ *this };
	
	this->operator++();

	return temp;
}

void MyString1::display() const {
	// Display Method
	std::cout << this->str << " : " <<
		this->get_length() << std::endl;
}

size_t MyString1::get_length() const {
	// Get Length Method
	return std::strlen(this->str);
}

const char* MyString1::get_string() const {
	// Get String Method
	return this->str;
}
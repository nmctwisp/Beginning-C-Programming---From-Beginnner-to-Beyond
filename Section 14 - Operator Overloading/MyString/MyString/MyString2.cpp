#define  _CRT_SECURE_NO_WARNINGS
#include "MyString2.h"
#include <cstring>
#include <cctype>

std::ostream& operator<<(std::ostream& os, const MyString2&  rhs) {
	// Insertion Operator
	os << rhs.str;

	return os;
}

std::istream& operator>>(std::istream& is, MyString2& rhs) {
	// Extraction Operator
	char* buff = new char[1000];
	is >> buff;

	rhs = MyString2{ buff };

	delete[] buff;

	return is;
}

MyString2& operator+=(MyString2& lhs, const MyString2& rhs) {
	// Concatenate and Assign Operator
	lhs = lhs + rhs;

	return lhs;
}

MyString2& operator*=(MyString2& lhs, int n) {
	// Repeat and Assign Operator
	lhs = lhs * n;
	
	return lhs;
}

MyString2& operator++(MyString2& rhs) {
	// Make Uppercase Operator via Pre-Increment Operator
	for (size_t i = 0; i < std::strlen(rhs.str); i++) {
		rhs.str[i] = std::toupper(rhs.str[i]);
	}

	return rhs;
}

MyString2 operator-(const MyString2& rhs) {
	// Make Lowercase Operator
	char* buff = new char[std::strlen(rhs.str) + 1];
	std::strcpy(buff, rhs.str);

	for (size_t i = 0; i < std::strlen(buff); i++) {
		buff[i] = std::tolower(buff[i]);
	}

	MyString2 temp{ buff };
	delete[] buff;

	return temp;
}

MyString2 operator+(const MyString2& lhs, const MyString2& rhs) {
	// Concatenate Operator
	char* buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
	std::strcpy(buff, lhs.str);
	std::strcat(buff, rhs.str);

	MyString2 temp{ buff };
	delete[] buff;

	return temp;
}

bool operator==(const MyString2& lhs, const MyString2& rhs) {
	// Equality Operator
	bool result = (std::strcmp(lhs.str, rhs.str) == 0);

	return result;
}

bool operator!=(const MyString2& lhs, const MyString2& rhs) {
	// Inequality Operator
	bool result = (std::strcmp(lhs.str, rhs.str) != 0);

	return result;
}

bool operator<(const MyString2& lhs, const MyString2& rhs) {
	// Less-Than Operator
	bool result = (std::strcmp(lhs.str, rhs.str) < 0);

	return result;
}

bool operator>(const MyString2& lhs, const MyString2& rhs) {
	// Greater-Than Operator
	bool result = (std::strcmp(lhs.str, rhs.str) > 0);

	return result;
}

MyString2 operator*(const MyString2& lhs, int n) {
	// Repeat Operator
	MyString2 temp;
	for (size_t i = 0; i <= n; i++) {
		temp = temp + lhs;
	}

	return temp;
}

MyString2 operator++(MyString2& lhs, int n) {
	// Make Uppercase Operator via Post-Increment Operator
	MyString2 temp{ lhs };
	operator++(lhs);
	
	return temp;
}

MyString2::MyString2():
	str{nullptr} {
	// No-Args Constructor
	this->str = new char[1];
	*(this->str) = '\0';
}

MyString2::MyString2(const char* source):
	str{nullptr} {
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

MyString2::MyString2(const MyString2& source):
	str{nullptr} {
	// Copy Constructor
	this->str = new char[std::strlen(source.str) + 1];
	std::strcpy(this->str, source.str);
}

MyString2::MyString2(MyString2&& source): 
	str{ source.str } {
	// Move Constructor
	source.str = nullptr;
}

MyString2::~MyString2() {
	// Destructor
	delete[] this->str;
}

MyString2 &MyString2::operator=(const MyString2& rhs) {
	// Copy Assignment
	if (this == &rhs) {
		return *this;
	}

	delete[] this->str;
	this->str = new char[std::strlen(rhs.str) + 1];
	std::strcpy(this->str, rhs.str);

	return *this;
}

MyString2 &MyString2::operator=(MyString2&& rhs) {
	// Move Assignment
	if (this == &rhs) {
		return *this;
	}

	delete[] this->str;
	this->str = rhs.str;
	rhs.str = nullptr;

	return *this;
}

void MyString2::display() const {
	// Display Method
	std::cout << this->str << " : " <<
		this->get_length() << std::endl;
}

size_t MyString2::get_length() const {
	// Get Length Method
	return std::strlen(this->str);
}

const char* MyString2::get_string() const {
	// Get String Method
	return this->str;
}
#pragma once
#include <iostream>

class MyString1 {

	friend std::ostream &operator<<(std::ostream& os, const MyString1& rhs);
	friend std::istream &operator>>(std::istream& in, MyString1& rhs);

private:

	char *str;
	
public:

	// Constructors and Destructors
	MyString1();
	MyString1(const char* source);
	MyString1(const MyString1& source);
	MyString1(MyString1&& source);
	~MyString1();

	// Assignment Operator
	MyString1& operator=(const MyString1& rhs);
	MyString1& operator=(MyString1&& rhs);

	// Unary & Binary Operator Overloading via Memeber Function
	MyString1& operator+=(const MyString1& rhs);
	MyString1& operator*=(int n);
	MyString1& operator++();

	MyString1 operator-() const;
	MyString1 operator+(const MyString1& rhs) const;
	bool operator==(const MyString1& rhs) const;
	bool operator!=(const MyString1& rhs) const;
	bool operator<(const MyString1& rhs) const;
	bool operator>(const MyString1& rhs) const;
	MyString1 operator*(int n) const;
	MyString1 operator++(int n);

	// Member Functions
	void display() const;
	size_t get_length() const;
	const char* get_string() const;
};


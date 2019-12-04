#pragma once
#include <iostream>

class MyString2 {
	// Extraction and Insertion Operatos
	friend std::ostream& operator<<(std::ostream& os, const MyString2& rhs);
	friend std::istream& operator>>(std::istream& is, MyString2& rhs);

	// Unary & Binary Operator Overloading via Friend Function
	friend MyString2& operator+=(MyString2& lhs, const MyString2& rhs);
	friend MyString2& operator*=(MyString2& lhs, int n);
	friend MyString2& operator++(MyString2& rhs);

	friend MyString2 operator-(const MyString2& rhs);
	friend MyString2 operator+(const MyString2& lhs, const MyString2& rhs);
	friend bool operator==(const MyString2& lhs, const MyString2& rhs);
	friend bool operator!=(const MyString2& lhs, const MyString2& rhs);
	friend bool operator<(const MyString2& lhs, const MyString2& rhs);
	friend bool operator>(const MyString2& lhs, const MyString2& rhs);
	friend MyString2 operator*(const MyString2& lhs, int n);
	friend MyString2 operator++(MyString2& lhs, int n);

private:
	// Raw Pointer
	char *str;

public:	
	// Constructors and Destructors
	MyString2();
	MyString2(const char* source);
	MyString2(const MyString2& source);
	MyString2(MyString2&& source);
	~MyString2();

	// Assignment Operators
	MyString2& operator=(const MyString2& rhs);
	MyString2& operator=(MyString2&& rhs);

	// Member Functions
	void display() const;
	size_t get_length() const;
	const char* get_string() const;
};
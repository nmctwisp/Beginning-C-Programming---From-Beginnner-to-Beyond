#pragma once
#include <string>

class Account {
public:
	Account();
	~Account();

	double balance;
	std::string name;

	void deposit(double amount);
	void withdraw(double amount);
};
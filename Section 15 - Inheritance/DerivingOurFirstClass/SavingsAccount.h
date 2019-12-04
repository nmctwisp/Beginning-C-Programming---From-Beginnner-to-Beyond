#pragma once
#include "Account.h"

class SavingsAccount : public Account {
public:
	SavingsAccount();
	~SavingsAccount();

	double interest_rate;

	void deposit(double amount);
	void withdraw(double amount);
};
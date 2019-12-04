// Example of Dynamic Bindings with references

#include <iostream>
#include <vector>

class Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "In Account::withdraw" << std::endl;
	}
	virtual ~Account() {
		std::cout << "Account::destructor" << std::endl;
	}
};

class Checking : public Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "In Checking::withdraw" << std::endl;
	}
	virtual ~Checking() {
		std::cout << "Checking::destructor" << std::endl;
	}
};

class Savings : public Account {
public:
	int num = 1;
	virtual void withdraw(double amount) {
		std::cout << "In Savings::withdraw" << std::endl;
	}
	virtual ~Savings() {
		std::cout << "Savings::destructor" << std::endl;
	}
};

class Trust : public Savings {
public:
	virtual void withdraw(double amount) {
		std::cout << "In Trust::withdraw" << std::endl;
	}
	virtual ~Trust() {
		std::cout << "Trust::destructor" << std::endl;
	};;
};

void do_withdraw(Account& acc, double amount) {
	acc.withdraw(amount);
}

int main() {
	Account a;
	Account &ref = a;
	ref.withdraw(1000);		// In Account::withdraw

	Trust t;
	Account &ref1 = t;
	ref1.withdraw(1000);	// In Trust::withdraw

	Account a1;				
	Savings a2;				
	Checking a3;			
	Trust a4;				

	do_withdraw(a1, 1000);		// In Account::withdraw
	do_withdraw(a2, 1000);		// In Savings::withdraw
	do_withdraw(a3, 1000);		// In Checking::withdraw
	do_withdraw(a4, 1000);		// In Trust::withdraw

	return 0;				
}
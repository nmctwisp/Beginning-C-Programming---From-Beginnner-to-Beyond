#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"

using std::cout;
using std::endl;

int main() {
	// Using the Account Class
	cout << "\n==== Account =======================================" << endl;
	Account acc{};
	acc.deposit(2000.0);
	acc.withdraw(500.0);
	
	cout << endl;
	
	Account *acc_ptr{ nullptr };
	acc_ptr = new Account();
	acc_ptr->deposit(1000.0);
	acc_ptr->withdraw(500.0);
	delete acc_ptr;

	// Using SavingsAccount Class
	cout << "\n==== SavingsAccount ================================" << endl;
	SavingsAccount sav_acc{};
	sav_acc.deposit(2000.0);
	sav_acc.withdraw(500.0);

	cout << endl;
	
	SavingsAccount *sav_ptr{ nullptr };
	sav_ptr = new SavingsAccount();
	sav_ptr->deposit(1000.0);
	sav_ptr->withdraw(500.0);
	delete sav_ptr;

	cout << "\n====================================================" << endl;

	return 0;
}
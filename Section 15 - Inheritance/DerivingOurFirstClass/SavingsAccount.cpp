#include <iostream>
#include "SavingsAccount.h"

using std::cout;
using std::endl;

SavingsAccount::SavingsAccount():
	interest_rate{3.0} {

}

SavingsAccount::~SavingsAccount() {

}

void SavingsAccount::deposit(double amount) {
	cout << "SavingsAccount::deposit called with " << amount << endl;
}

void SavingsAccount::withdraw(double amount) {
	cout << "SavingsAccount::withdraw called with " << amount << endl;
}
#include <iostream>
#include "Account.h"

using std::cout;
using std::endl;

Account::Account():
	balance{0.0},
	name{"An Acount"} {

}

Account::~Account() {

}

void Account::deposit(double amount) {
	cout << "Account deposit called with " << amount << endl;
}

void Account::withdraw(double amount) {
	cout << "Account withdraw called with " << amount << endl;
}

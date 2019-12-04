#include "Checking_Account.h"

std::ostream& operator<<(std::ostream& os, const Checking_Account& checking_acct) {
	os << "Checking Account: " << checking_acct.name;
	os << " Account Balance: " << checking_acct.balance;
	os	<< " Transaction Fee: " << checking_acct.transact_fee;

	return os;
}

Checking_Account::Checking_Account(std::string name, double balance, double transact_fee) :
	Account{name, balance},
	transact_fee{transact_fee} {

}

bool Checking_Account::withdraw(double amount) {
	if (amount >= this->balance){
		return false;
	}

	return Account::withdraw(amount + transact_fee);
}
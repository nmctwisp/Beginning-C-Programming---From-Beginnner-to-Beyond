#define _CRT_SECURE_NO_WARNINGS
#include "Trust.h"
#include "Savings_Account.h"
#include <ctime>

std::ostream& operator<<(std::ostream& os, const Trust& account) {
	os << "Trust Account: " << account.name;
	os << " Account Balance: " << account.balance;
	os << " Interest Rate: " << account.int_rate;
	return os;
 }


Trust::Trust(std::string name, double balance, double int_rate):
	Savings_Account{name, balance, int_rate} {
	current_year = get_current_year();
	current_year_withdrawals = 0;
}

bool Trust::valid_withdrawal_amt(double amount) {
	return (amount < (balance * withdrawal_pct_cut_off)) ? true : false;
}

void Trust::update_current_year() {
	int year{ get_current_year() };
	
	if (current_year == year)
		return;

	if (current_year < year) {
		current_year = year;
		current_year_withdrawals = 0;
		return;
	}
}

int Trust::get_current_year() {
	time_t current_time = time(NULL);
	tm* current_time_ptr = localtime(&current_time);
	
	return current_time_ptr->tm_year + 1900;
}

bool Trust::deposit(double amount) {
	if (amount >= bonus_deposit_threshold) {
		amount += bonus;
	}

	return Savings_Account::deposit(amount);
}

bool Trust::withdraw(double amount) {
	update_current_year();

	if ((++current_year_withdrawals > annual_withdrawal_limit) || !valid_withdrawal_amt(amount))
		return false;

	return Account::withdraw(amount);
}

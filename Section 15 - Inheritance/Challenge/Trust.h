#pragma once
#include "Savings_Account.h"

class Trust : public Savings_Account {
	friend std::ostream& operator<<(std::ostream& os, const Trust& account);
private:
	/// \copydoc Account::def_name
	static constexpr const char* def_name = "Unnamed Trust Account";
	/// \copydoc Account::def_balance
	static constexpr double def_balance = 0.0;
	/// \copydoc Savings_Account::int_rate
	static constexpr double def_int_rate = 1.5;
	/// Bonus Deposit Threshold
	static constexpr double bonus_deposit_threshold = 5000.0;
	/// Deposit Bonus Amount
	static constexpr double bonus = 50.0;

	/// the maximum number of withdrawals for a given year
	static constexpr int annual_withdrawal_limit = 3;

	/// the maximum % of balance allowed eligible for withdrawal
	static constexpr double withdrawal_pct_cut_off = 0.20;

protected:
	/// Counter to track the number of withdrawals that were made in the current year
	int current_year_withdrawals;
	/// Current Year
	int current_year;
	
	/**
		Valdiates that the amount requested to be withdrawed is less than 
		\f$ balance * withdrawal\_pct\_cut\_off \f$
		\returns 
			- \b true if amount < balance * withdrawal_pct_cut_off \n
			- \b false if amount >= balance * withdrawal_pct_cut_off
	**/
	bool valid_withdrawal_amt(double amount);
	
	/**
		- Checks to see of the current year is up-to-date in order to limit the number of withdrawals within a year.
		- Resets the current_year_withdrawals counter once a withdrawal attempt is made in the new year. 
	**/
	void update_current_year();

public:
    /**
        \b Constructor \b Description \n
        - The Trust class instantiation is similar to Savings_Account class with only two exception. 
			-# the current_year_withdrawals is initalized to 0
			-# the current_year is initalized to the current local year

        @param name - if a name is not provided at instantiation, then the object will be constructed with def_name.
        @param balance - if a balance is not provided at instantiation, then the object will be constructed with def_balance.
        @param int_rate - if a int_rate is not provided at instantiation, then the object will be constructed with def_int_rate.

		\see Savings_Account::Savings_Account
		\see Account::Account
    **/
	Trust(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);

	/**
		Trust::deposit overloads Savings_Account::deposit to 
			- add an additional check to see if the deposit is eligible for a bonus
			- if eligible add the bonus amount to the inputted deposit amount
	**/
	bool deposit(double amount);

	/**
		Trust::withdraw overloads Account::withdraw to
			- add an additional check to see if the number of annual withdrawals has been exceeeded, or
			- the requested withdrawal amount does not exceed the withdrawal cut off

		\returns
			- \b false if either one of the conditions above is satisfied
			- \b true if neither one of the conditions above is satisfied
	**/
	bool withdraw(double amount);

	/// \returns the current 4 digit year
	int get_current_year();

};
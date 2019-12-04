#pragma once
#include "Account.h"

class Checking_Account : public Account {
	friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
private:
    /// \copydoc Account::def_name
	static constexpr const char *def_name = "Unnamed Checking Account";
    /// \copydoc Account::def_balance
	static constexpr double def_balance = 0.0;
    /// Default Checking_Account::transact_fee
	static constexpr double def_transact_fee = 1.5;

protected:
    /**
        \brief set to def_transact_fee if one is not provided upon initialization
        \see Account::Account 
        \see Checking_Account::Checking_Account
    **/
	double transact_fee;

public:
    /**
        \b Constructor \b Description \n
        - The Checking_Account class inherits from the Account class, therefore it inherits the Account class protected attributes name and balance. 
        - Upon initializing the Checking_Account object, the Account object is first instantiated with name and balance. 
        - Next, the Checking_Account object is instantiated with both the Account obj and transact_fee. 

        @param name - if a name is not provided at instantiation, then the object will be constructed with def_name.
        @param balance - if a balance is not provided at instantiation, then the object will be constructed with def_balance.
        @param transact_fee - if a transact_fee is not provided at instantiation, then the object will be constructed with def_transact_fee.

        \see Account::Account
    **/
	Checking_Account(std::string name=def_name, double balance=def_balance, double transact_fee=def_transact_fee);

    /**
        - Checking_Account class overloads the Account class withdraw member function to deduct a transaction fee each time there is a withdrawal.\n 
        \f$ amount = amount + transact\_fee \f$ \n
        \copydetails Account::withdraw
        \see Account::withdraw
    **/
    bool withdraw(double amount);



};
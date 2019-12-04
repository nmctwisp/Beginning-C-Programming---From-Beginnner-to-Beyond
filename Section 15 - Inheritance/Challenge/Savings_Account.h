#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "Account.h"

class Savings_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);
    
private:
    /// \copydoc Account::def_name
    static constexpr const char *def_name = "Unnamed Savings Account";
    /// \copydoc Account::def_balance
    static constexpr double def_balance = 0.0;
    /// Default Savings_Account::int_rate
    static constexpr double def_int_rate = 0.0; 

protected:
    /**
        \brief set to def_int_rate if one is not provided upon initialization
        \see Account::Account 
        \see Savings_Account::Savings_Account
    **/
    double int_rate; 
public:
    /**
        \b Constructor \b Description \n
        - The Savings_Account class inherits from the Account class, therefore it inherits the Account class protected attributes name and balance. 
        - Upon initializing the Savings_Account object, the Account object is first instantiated with name and balance. 
        - Next, the Savings_Account object is instantiated with both the Account obj and int_rate. 
       
        @param name - if a name is not provided at instantiation, then the object will be constructed with def_name.
        @param balance - if a balance is not provided at instantiation, then the object will be constructed with def_balance.
        @param int_rate - if a int_rate is not provided at instantiation, then the object will be constructed with def_int_rate.
    **/
    Savings_Account(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate); 
    
    /**
        - Savings_Account class overloads the Account class deposit member function to include the interest accrued. The interest is calculated at the time of the deposit. 
        The method calculates interest in a simple manner, so it doesn't take into consideration the days accrued.\n
        \f$ amount = amount + (amount * \frac{int\_rate}{100}) \f$\n
        \copydetails Account::deposit
        \see Account::deposit
    **/
    bool deposit(double amount) ;
};

#endif // _SAVINGS_ACCOUNT_H_

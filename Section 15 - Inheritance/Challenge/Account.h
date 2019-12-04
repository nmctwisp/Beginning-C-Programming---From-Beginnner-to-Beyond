// Simple Account 
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>

class Account {
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
private:
    /// Default Account::name
    static constexpr const char *def_name = "Unnamed Account";
    /// Default Account::balance
    static constexpr double def_balance = 0.0;

protected:
    /**
        \brief set to def_name if one is not provided upon instantiation
        \see Account::Account 
    **/
    std::string name;
    /**
        \brief set to def_balance if one is not provided upon instantiation
        \see Account::Account 
    **/
    double balance;

public:
    /**
        \b Constructor \b Description \n
        - The Account class is intended to be the base class to derive different types of Accounts.
        @param name - the name on the account, if one is not provided then the default name, "Unnamed Account", will be used.

        @param balance - if a balance was not provided at instantiation, then the object will be constructed with 0.0 balance.
    **/
    Account(std::string name=def_name, double balance=def_balance);
    
    /**
        \brief The method simply adds the inputted deposit amount to the account balance\n
        \details 
        \f$balance = balance + amount\f$
        - The method returns a bool as a indicator as to whether the deposit was sucessful. The only time a deposit that will be rejected is when the method is called with a negative amount.    
        \returns
        <table>
        <tr>
            <th>Amount                      
            <th>Output
        <tr>
            <td>\f$amount >= 0\f$
            <td>true   
        <tr>
            <td>\f$amount < 0\f$
            <td>false
        </table>
        
        \param amount in dollars to be deposited
    **/ 
    bool deposit(double amount);
    /**
        \brief The method simply adds the inputted withdrawal amount from the account balance\n
        \details
        \f$balance = balance - amount\f$
        - The method returns a bool as a indicator as to whether the withdrawal was sucessful. The withdrawal will rejected or return false if the withdrawal amount exceeds the balance.    
        \returns
        <table>
        <tr>
            <th>Amount                      
            <th>Output
        <tr>
            <td>\f$(balance - amount) >= 0\f$
            <td>true   
        <tr>
            <td>\f$(balance - amount) < 0\f$
            <td>false
        </table>
        
        \param amount in dollars to be deposited
    **/ 
    bool withdraw(double amount);

    /// \returns Account::balance
    double get_balance() const;
};
#endif
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>

using namespace std;

class Account {

private:
    //attributes
        string name;
        double balance;
public:
    //methods
        void set_balance(double bal);
        double get_balance();
        void set_name(string input_name);
        string get_name();
        bool deposit(double amount);
        bool withdraw(double amount);
};

#endif _ACCOUNT_H_

#include "account.h"
using namespace std;

void Account::set_balance(double bal){
    
    balance = bal;
}

double Account::get_balance(){
    
    return balance;
}
void Account::set_name(string input_name){
    name = input_name;
}

string Account::get_name(){
    return name;
}

bool Account::deposit(double amount){
    balance += amount;
    return true;
}

bool Account::withdraw(double amount){
    if (balance-amount >= 0){
        balance -= amount;
        return true;
    }
    else {
        return false;
    }

}
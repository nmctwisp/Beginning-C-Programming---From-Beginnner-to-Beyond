#include <iostream>
#include "account.h"

int main(){
    Account frank_account;
    frank_account.set_name("Frank's Account");
    frank_account.set_balance(1000.00);

    if (frank_account.deposit(200))
        cout << "Deposit OK" << endl;
    else
        cout << "Deposit Not Allowed" << endl;

    if (frank_account.withdraw(1500.00))
        cout << "Sufficent Funds, OK to Withdraw" << endl;
    else
        cout << "Insufficent Funds" << endl;

    return 0;
}
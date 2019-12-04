#include <iostream>
#include <string>

using namespace std;

class Account {

private:
    //attributes
        string name;
        double balance;
public:
    //methods
        //Full Method Definition and Implementation within Class
        void set_balance(double bal){
            
            balance = bal;
        }
        double get_balance(){
            
            return balance;
        }

        //Prototype within class
        //Methods will be declared outside the class declarations
        void set_name(string input_name);
        string get_name();
        bool deposit(double amount);
        bool withdraw(double amount);
};

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
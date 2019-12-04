#include <iostream>
#include <string>

using namespace std;

class Player {

public:
    //attributes
        string name;
        int health;
        int experience_points;
    //methods
        void talk(string message){

            cout << name << " says " << message << endl;
        }
        bool is_dead();
};

class Account {

public:
    //attributes
        string name;
        double balance;
    //methods
        void set_balance(double bal){
            
            balance = bal;
        }
        double get_balance(){
            
            return balance;
        }
        void deposit(double amount){

            balance += amount;
        }
        void withdraw(double amount){

            balance -= amount;
        }
};

int main() {
    // Player Object Creation
    Player frank;
    frank.name = "Frank";
    frank.health = 100;
    frank.experience_points = 12;
    frank.talk("Hi there!");

    Player *enemy = new Player;
    (*enemy).name = "Enemy";
    (*enemy).health = 100;
    enemy -> experience_points = 15;
    enemy -> talk("I will destroy you!");

    // Account Object Creation
    Account frank_account;
    frank_account.name = "Frank's Account";
    frank_account.set_balance(5000.00);
    frank_account.deposit(1000.00);
    frank_account.withdraw(500.00);
    
    return 0;
}
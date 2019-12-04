#include <iostream>
#include <string>

using namespace std;

class Player {

private:
    //attributes
        string name;
        int health;
        int experience_points;
public:
    //methods
        void talk(string message){

            cout << name << " says " << message << endl;
        }
        bool is_dead();
};

class Account {

private:
    //attributes
        string name;
        double balance;
public:
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

int main {
    // Player Object Creation
    Player frank;
    frank.name = "Frank"; // Compiler error
    frank.health = 100; // Compiler error
    frank.experience_points = 12; // Compiler error
    frank.talk("Hi there!"); // OK

    Player *enemy = new Player;
    (*enemy).name = "Enemy"; // Compiler error
    (*enemy).health = 100; // Compiler error
    enemy -> experience_points = 15; // Compiler error
    enemy -> talk("I will destroy you!"); // OK

    // Account Object Creation
    Account frank_account; 
    frank_account.name = "Frank's Account"; // Compiler error
    frank_account.set_balance(5000.00); // OK
    frank_account.deposit(1000.00); // OK
    frank_account.withdraw(500.00); // OK
    return 0;
}
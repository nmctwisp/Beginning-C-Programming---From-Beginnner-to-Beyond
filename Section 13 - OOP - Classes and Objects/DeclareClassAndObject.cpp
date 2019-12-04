#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
    //attributes
        string name;
        int health;
        int experience_points;
    //methods
        void talk(string);
        bool is_dead();
};

class Account {
    //attributes
        string name;
        double balance;
    //methods
        void set_balance(double bal);
        double get_balance();
        void deposit(double amount);
        double withdraw(double amount);
};

int main() {
    // Player Object Creation
    Player frank;
    Player hero;

    Player player_arr[] = {frank, hero};
    vector<Player> player_vector = {frank};

    player_vector.push_back(hero);

    Player *enemy = nullptr;
    enemy = new Player;

    delete enemy;

    // Account Object Creation

    Account frank_account;
    Account jim_account;

    Account account_arr[] = {frank_account, jim_account};
    vector<Account> account_vec = {frank_account};

    account_vec.push_back(jim_account); 

    Account *mary_account = nullptr;
    mary_account = new Account;

    delete mary_account;

    return 0;
}
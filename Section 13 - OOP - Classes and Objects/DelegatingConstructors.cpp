#include <iostream>
#include <string>

using namespace std;

class Player{
private:
    // attributes
    std::string name;
    int health;
    int xp;
public:
    // Constructors
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};

Player::Player(std::string name_val, int health_val, int xp_val):
    name{name_val},
    health{health_val},
    xp{xp_val}{
        cout << "three-args constructor" << endl;
}

// the following two constructors delegates the construction to all-arg constructor
Player::Player(): Player{"None", 100, 3}{
    cout << "no-args constructor" << endl;
}

Player::Player(std::string name_val): 
    Player{name_val, 100, 3}{
        cout << "one-arg constructor" << endl;
}

int main(){
    Player empty;
    Player frank = "Frank";
    Player villian = {"Villian", 100, 55};
}
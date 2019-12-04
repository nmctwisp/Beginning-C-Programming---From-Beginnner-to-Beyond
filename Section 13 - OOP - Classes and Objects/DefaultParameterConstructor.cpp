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
    // Constructor with default parameter values, the default is done on the definition, during implementation you can exclude the default values
    // Player(); // including a no-args overload constructor would cause an error due to ambiguity 
    Player(std::string name_val="None", int health_val=0, int xp_val=0);
};

Player::Player(std::string name_val, int health_val, int xp_val):
    name{name_val},
    health{health_val},
    xp{xp_val}{
        cout << "three-args constructor" << endl;
        cout << name << endl;
        cout << health << endl;
        cout << xp << endl;
}

int main(){
    Player empty;
    Player frank = "Frank";
    Player Hero = {"Hero", 100};
    Player villian = {"Villian", 100, 55};
}
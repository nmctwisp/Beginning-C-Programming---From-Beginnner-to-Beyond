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
    // methods
        std::string get_name(){return name;}
        int get_health(){return health;}
        int get_xp(){return xp;}
    // Constructor
        Player(std::string name_val="None", int health_val=0, int xp_val=0);
    // Copy Constructor
        Player(const Player &source);
    // Destructor
        ~Player(){
            cout << "Destructor called for " << name << endl;
    }
};

Player::Player(std::string name_val, int health_val, int xp_val):
    name{name_val},
    health{health_val},
    xp{xp_val}{
        cout << "three-args constructor" << endl;
}
Player::Player(const Player &source):
    // name{source.name},
    // health{source.health},
    // xp{source.xp}
    Player{source.name, source.health, source.xp}{
        cout << "Copy Constructor - made a copy of " << source.name << endl;
}

void display_player(Player p){
    cout << "Name: " << p.get_name() << endl;
    cout << "Health: " << p.get_health() << endl;
    cout << "XP: " << p.get_xp() << endl;

}

int main(){
    Player villian = {"Villian", 100, 55};
    display_player(villian);
    Player new_villian = villian;
    display_player(new_villian);
}
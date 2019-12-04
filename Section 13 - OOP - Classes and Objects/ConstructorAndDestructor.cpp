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
        void set_name(std::string name_val){
            name = name_val;
        }
        std::string get_name(){
            return name;
        }
    // Overloaded Constructors
        Player(){

            cout << "no-args constructor called" << endl;
        }
        Player(std::string name_val){
            name = name_val;
            cout << "one arg constructor called for " << name << endl;
        }
        Player(std::string name_val, int health_val, int xp_val){
            name = name_val;
            health = health_val;
            xp = xp_val;
            cout << "three args constructor called for " << name << endl;
        }
    // Destructor
        ~Player(){
            cout << "deconstructor called for " << name << endl;
        }
};

int main(){
    {
        Player slayer1; // no arg constructor
        Player slayer2 = "Slayer2"; // one arg constructor
        Player slayer3 = Player("Slayer3"); // one arg constructor
        Player slayer4 = {"Slayer4", 100, 100}; // three args constructor
    }

    Player *enemy = new Player;
    (*enemy).set_name("Enemy");

    Player *level_boss = new Player("Level Boss", 1000, 3000);

    delete enemy;
    delete level_boss;


    return 0;
}
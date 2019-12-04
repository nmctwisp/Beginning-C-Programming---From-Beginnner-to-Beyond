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
        // // Previous Style
        // Player(){
        //     name = "None";  
        //     health = 100;
        //     xp = 3;
        // }
        // Player(std::string name_val){
        //     name = name_val;
        //     health = 100;
        //     xp = 3;
        // }
        // Player(std::string name_val, int health_val, int xp_val){
        //     name = name_val;
        //     health = health_val;
        //     xp = xp_val;
        // }
        // Initialize List Style
        Player()
            :   name{"None"}, 
                health{100}, 
                xp{3} {
        }
        Player(std::string name_val)
            :   name{name_val}, 
                health{100}, 
                xp{3} {
        }
        Player(std::string name_val, int health_val, int xp_val)
            :   name{name_val}, 
                health{health_val}, 
                xp{xp_val} {
        }
    // Destructor
        ~Player(){
        }
};

int main(){
    Player empty;
    Player frank = Player("Frank", 0, 13);
    Player jim {"Jim"};
    Player villian {"Villian", 100, 55};
    cout << frank.get_name() << endl;

    return 0;
}
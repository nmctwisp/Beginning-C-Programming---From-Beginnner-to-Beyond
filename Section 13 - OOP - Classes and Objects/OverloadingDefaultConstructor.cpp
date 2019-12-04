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
        Player(){// arg, no arg constructor
            name = "None";  
            health = 100;
            xp = 3;
        }
        Player(std::string name_val){// arg mix one arg constructor
            name = name_val;
            health = 100;
            xp = 3;
        }
        Player(std::string name_val, int health_val, int xp_val){
            name = name_val;
            health = health_val;
            xp = xp_val;
        }
    // Destructor
        ~Player(){
        }
};

int main(){
    Player hero;
    Player frank = Player("Frank", 0, 13);
    cout << frank.get_name() << endl;

    return 0;
}
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

class Player {
private:
    static int num_players;
    std::string name;
    int health;
    int xp;
public:
    std::string get_name();
    int get_health();
    int get_xp();
    static int get_num_players();
    // Constructor w/ defaults args
    Player(std::string name_val="None", int health_val=0, int xp_val=0);
    // Copy Constructor
    Player(const Player &source);
    //Destructor
    ~Player();
};

#endif // _PLAYER_H_
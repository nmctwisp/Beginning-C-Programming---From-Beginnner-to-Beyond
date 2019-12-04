#include <iostream>
#include "Player.h"

using namespace std;

void display_active_players(){
    cout << "Active Players: " << Player::get_num_players() << endl;
}

int main(){
    display_active_players();
    Player hero = "Hero";
    display_active_players();
    return 0;
}
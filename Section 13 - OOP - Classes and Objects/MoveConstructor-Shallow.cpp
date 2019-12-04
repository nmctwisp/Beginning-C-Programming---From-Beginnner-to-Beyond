
#include <iostream>
#include <vector>
using namespace std;

class Move{
private:
    int *data;
public:
    void set_data_value(int d);
    int get_data_value();
    // Constructor
    Move(int d);
    // Copy Constructor
    Move(const Move &source);
    // Move Constructor
    ~Move();
};

void Move::set_data_value(int d){
    *data = d;
}

int Move::get_data_value(){
    return *data;
}

Move::Move(int d){
    data = new int;
    *data = d;
}

Move::Move(const Move &source):
    Move{*source.data}{
        cout << "Copy Constructor - Move Copy" << endl;
    }

Move::~Move(){
    if (data != nullptr){
        cout << "Destructor releases data for "<< *data << endl;
    }
    else {
        cout << "Destructor releases data for nullptr" << endl;
    }
    delete data;
}

void display_Move(Move s){
    cout << s.get_data_value() << endl;
}

int main(){
    vector<Move> vec;

    vec.push_back(Move(10));

    vec.push_back(Move(20));
    vec.push_back(Move(30));
    vec.push_back(Move(40));
    vec.push_back(Move(50));
    vec.push_back(Move(60));
    vec.push_back(Move(70));
    vec.push_back(Move(80));

    return 0;
}
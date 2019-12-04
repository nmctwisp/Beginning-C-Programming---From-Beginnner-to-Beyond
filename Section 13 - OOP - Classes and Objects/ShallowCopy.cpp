#include <iostream>

using namespace std;

class Shallow{
private:
    int *data;
public:
    void set_data_value(int d);
    int get_data_value();
    // Constructor
    Shallow(int d);
    // Copy Constructor
    Shallow(const Shallow &source);
    //
    ~Shallow();
};

void Shallow::set_data_value(int d){
    *data = d;
}

int Shallow::get_data_value(){
    return *data;
}

Shallow::Shallow(int d){
    data = new int;
    *data = d;
}

Shallow::Shallow(const Shallow &source):
    data{source.data}{
        cout << "Copy Constructor - Shallow Copy" << endl;
    }

Shallow::~Shallow(){
    delete data;
    cout << "Destructor releases data" << endl;
}

void display_shallow(Shallow s){
    cout << s.get_data_value() << endl;
}

int main(){
    Shallow obj1 = 100;
    display_shallow(obj1);

    Shallow obj2 = obj1;
    obj2.set_data_value(1000);

    return 0;
}
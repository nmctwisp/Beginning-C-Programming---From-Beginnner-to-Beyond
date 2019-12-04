#ifndef __DOG_H__
#define __DOG_H__
#include <string>
using namespace std;

class Dog {
private:
    // attributes
    string name;
    int age;
public:

//---- WRITE YOUR CLASS FUNCTIONS BELOW THIS LINE----
    string get_name(){
        return name; 
    }
    int get_age(){
        return age;
    }
    void set_name(string dog_name){
        name = dog_name;
    }
    void set_age(int dog_age){
        age = dog_age;
    }

//---- WRITE YOUR CLASS FUNCTIONS ABOVE THIS LINE----
};
#endif 

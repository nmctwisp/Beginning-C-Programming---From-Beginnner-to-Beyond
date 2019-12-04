#include <iostream>

using namespace std;

void global_example();
void local_example(int x);
void static_local_example();


// Global variable - declared outside any class of funtion
int num = 300; 
// it is not advised to use global variables, but it is acceptable to use global constants

int main() {
    int num = 100;
    int num1 = 500;

    cout << "Local num is: " << num << " in main" << endl;

    {
        int num = 200;
        cout << "Local num is: " << num << " in inner block in main" << endl;
        cout << "Inner block does not have num1 so it checks the next immediate scope for num1, which is: " << num1 << endl;
    }

    cout << "Local num is: " << num << " in main\n" << endl;

    local_example(10);
    local_example(20);
    global_example();
    global_example();
    static_local_example();
    static_local_example();
    static_local_example();

    return 0;
}

void local_example(int x) {
    int num = 1000; //local to local_example func
    cout << "local_example output " << endl;
    cout << "=====================" << endl;
    cout << "Local num is: " << num << " in local_example - start" << endl;
    num = x;
    cout << "Local num is: " << num << " in local_example - end" << endl;
    // num1 in main is not within scope - so it can't be used here.
}

void global_example() {
    cout << "global_example output " << endl;
    cout << "=====================" << endl;
    cout << "Global number is: " << num << " in global_example - start" << endl;
    num *= 2; // Since num was found in the global scope it can be directly modified without using references. 
    // references are mainly for aliasing arguments
    cout << "Global num is: " << num << " in global_example - end" << endl;
}

void static_local_example() {
    cout << "\nstatic_local_example output " << endl;
    cout << "=====================" << endl;
    static int num = 5000; // local to static_local_example static - retains it value between calls unlike local_example
    cout << "Local static num is: " << num << " in static_local_example - start" << endl;
    num += 1000;
    cout << "Local static num is: " << num << " in static_local_example - end" << endl;
}

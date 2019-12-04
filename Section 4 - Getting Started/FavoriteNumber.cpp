#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main() {

    int favorite_num; 
    cout << "What is your favorite number between 1 and 100? ";
    cin >> favorite_num;

    cout << "Amazing! That's my favorite number too!" << endl;
    cout << "No really!, " << favorite_num << " is my favorite number!" << endl;

    return 0;
}
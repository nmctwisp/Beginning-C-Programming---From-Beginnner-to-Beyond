#include <iostream>

using namespace std;

void scale_number(int &num);

int main() {

    int number = 1000;
    scale_number(number);
    cout << number << endl; // 100

    return 0;
}

void scale_number(int &num) {
    if (num > 100)
        num = 100;
}
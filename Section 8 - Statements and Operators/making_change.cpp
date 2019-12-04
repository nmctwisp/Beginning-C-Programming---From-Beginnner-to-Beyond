#include <iostream>


using std::cin;
using std::cout;
using std::endl;

int main() {

    int cents {0};

    cout << "Enter the number of cents: ";
    cin >> cents;

    cout << "Dollars: "  << cents/100 << endl;
    cents %= 100;

    cout << "Quarters: " << cents/25 << endl;
    cents %= 25;

    cout << "Dimes: " << cents/10 << endl;
    cents %= 10;

    cout << "Nickels: " << cents/5 << endl;
    cents %= 5;

    cout << "Pennies: " << cents;

    return 0;
}
#include <iostream>
using namespace std;

int calculate_sum() {
    //---- WRITE YOUR CODE BELOW THIS LINE
    int sum = 0;
    for (int i = 1; i < 16; ++i) {
        sum += (i%2 != 0) ? i : 0;

    }
   
    
    //---- WRITE YOUR CODE ABOVE THIS LINE
    //---- DO NOT MODIFY THE CODE BELOW
    return sum;
}

int main() {
    cout << calculate_sum() << endl;
    return 0;
}
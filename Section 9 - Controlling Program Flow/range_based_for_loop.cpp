#include <vector>
#include <iostream>
using namespace std;

int count_divisible() {
    
    vector<int> vec {1,3,5,15,16,17,18,19,20,21,25,26,27,30,50,55,56,58,100,200,300,400,-99,500,600,700};
    //---- WRITE YOUR CODE BELOW THIS LINE----

    int count = 0;

    for (auto elm: vec) {
        if (elm % 3 == 0 || elm % 5 == 0)
            count += 1;
    }    
    
    
    //---- WRITE YOUR CODE ABOVE THIS LINE----
    //---- DO NOT CHANGE THE CODE BELOW THIS LINE----
    return count;
}

int main() {
    cout << count_divisible();
    return 0;
}
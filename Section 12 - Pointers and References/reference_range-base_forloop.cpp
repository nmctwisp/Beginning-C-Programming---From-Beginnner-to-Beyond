#include <iostream>

using namespace std;

int main() {
    int arr[] = {1,2,3,4,5,6};

    
    for (auto &i: arr){
        i *= 5;
        cout << i << endl;
    }

    
    return 0;
}
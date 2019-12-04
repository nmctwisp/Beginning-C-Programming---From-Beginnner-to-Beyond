#include <iostream>
#include <string>

using namespace std;

void print(const string arr[], size_t arr_len);


int main() {
    // Arrays are called by Reference instead of call by Value so you
    // do not need to use the reference operator, & for the parameter list
    string arr[] = {"Chen", "Yam"};
    size_t arr_len = 2;
    print(arr, arr_len);
    return 0;
}

void print(const string arr[], size_t arr_len) {
    for (size_t i=0; i < arr_len; ++i)
        cout << arr[i] << endl;
}
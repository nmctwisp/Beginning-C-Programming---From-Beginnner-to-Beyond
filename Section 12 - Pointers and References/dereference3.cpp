#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {


    vector<string> stooges = {"Larry", "Mo", "Curly"};
    vector<string> *vector_ptr = nullptr;

    vector_ptr = &stooges;

    cout << (*vector_ptr).at(0) << endl; //Larry
    cout << endl;

    for (auto name: *vector_ptr)
        cout << name << endl;
 
    return 0;
}
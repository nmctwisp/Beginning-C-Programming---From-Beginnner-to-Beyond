#include <iostream>
#include <string>
#include <vector>

using namespace std;

void display(vector<string> *v) {
    for (auto str: *v)
        cout << str << " ";

    cout << endl;
}

void display(int *array, int sentinel);

int main() {

    cout << "============================" << endl;
    vector<string> stooges = {"Larry", "Moe", "Curly"};
    display(&stooges);

    // cout << "\n============================" << endl;
    // int scores[] = {100, 98, 97, 79, 85, -1};
    // display(scores, -1);

    cout << endl;
    return 0;
}
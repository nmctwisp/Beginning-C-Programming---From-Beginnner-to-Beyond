#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print1(vector<string> vec);
void print2(vector<string> &vec);

int main() {
    vector<string> vec = {"Chen", "Yam"};
    print1(vec);
    cout << endl;
    cout << "Main Function Values" << endl;
    cout << "====================" << endl;
    cout << vec[0] << endl;
    cout << vec[1] << endl;
    print2(vec);
    cout << endl;
    cout << "Main Function Values" << endl;
    cout << "====================" << endl;
    cout << vec[0] << endl;
    cout << vec[1] << endl;
    return 0;
}

void print1(vector<string> vec) {
    vec.at(0) = "Charles";
    cout << "Print1 Function Values" << endl;
    cout << "====================" << endl;
    for (string name: vec) {
        cout << name << endl;
    }
}

void print2(vector<string> &vec) {
    vec.at(0) = "Charles";
    cout << "Print2 Function Values" << endl;
    cout << "====================" << endl;
    for (string name: vec) {
        cout << name << endl;
    }
}
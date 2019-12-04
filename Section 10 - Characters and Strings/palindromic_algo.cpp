#include <iostream>
#include <string>

using namespace std;

int main() {
    string str {"Hello"};
    string new_str{};
    size_t str_len = str.length();

    for (char letter: str) {
        new_str.push_back(letter);
            cout << new_str;
        size_t new_str_len = new_str.length();
        for (size_t i=new_str_len-2; i != -1; --i) {
                cout << new_str.at(i);

        }
        cout << endl;

    }
}
#include <iostream>
#include <string>
using namespace std;

int main() {

    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string key = "DiNBTlxVpeRuEjPSstKwHhUvQrOMbJfZgYzkGXdoaqFAnIyLCWcm";
    string unencrypted_message = "Hello";
    string encrypted_message{};

    for (char letter: unencrypted_message) {
        int index = alphabet.find(letter);
        encrypted_message.push_back(key[index]);
    }
    cout << encrypted_message << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const string mapping = "0123456789ABCDEF";

int hex_to_base(string &hex_str);

int main() {
    string hex_str;
    cout << "Enter a hexidecimal string: ";
    cin >> hex_str;
    cout << hex_to_base(hex_str) << endl;
    return 0;
}

int hex_to_base(string &hex_str) {
    size_t hex_str_len = hex_str.length();

    int index = 0;
    int base10{};
    for (signed int i=hex_str_len-1; i >= 0; --i){
        base10 += mapping.find(toupper(hex_str.at(index))) * pow(16, i);
        index++;
    }
    return base10;
}
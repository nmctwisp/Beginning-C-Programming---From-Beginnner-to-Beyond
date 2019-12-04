#include <iostream>
#include <string>

using namespace std;

int main() {

    string input_str;
    cout << "Enter a string: ";
    cin >> input_str;
    // input_str = "ABC";

    size_t max_palindrome_length = input_str.size() * 2 - 1;
    string available_char{};

    for (char letter: input_str){
        available_char.push_back(letter);
        size_t available_char_len = available_char.length();
        string palindrome_str = available_char;

        for (size_t i=available_char_len-2; i != -1; --i) {
            palindrome_str.push_back(available_char.at(i));
        }

        size_t padding_size = (max_palindrome_length - palindrome_str.length()) / 2;
        string padding (padding_size, ' ');
        cout << padding << palindrome_str << padding <<endl;
    }
        
    return 0;
}
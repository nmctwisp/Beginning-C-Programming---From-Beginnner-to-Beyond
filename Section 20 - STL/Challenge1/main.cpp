#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <deque>

/*
	std::string getalpha(std::string word) {
		std::string new_word{};

		for (size_t i = 0; i < word.size(); i++)
			if (std::isalpha(word.at(i)) != 0){
				new_word += std::toupper(word.at(i));
			}

		return new_word;
	}
	std::string getreverse(std::string word) {
		std::reverse(word.begin(), word.end());

		return word;
	}
	bool is_palindrome(std::string &word) {
		std::string reverse_word = getreverse(word);
	
		return (word == reverse_word) ? true : false;
	
	}
*/

bool is_palindrome(std::string& word) {
	std::string new_word{};
	std::deque<char> d;
	for (const char& letter : word) {
		if (std::isalpha(letter)){
			d.push_back(letter);
			new_word += letter;
		}
	}

	while (d.size() > 0) {
		if (d.front() != new_word.back())
			return false;
		d.pop_front();
		new_word.pop_back();
	}

	return true;
}

int main() {


	// std::string word{ "a santa at nasa" };
	std::string word{ "Hello" };
	std::cout << is_palindrome(word) << std::endl;

	return 0;
}
// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {

	std::ifstream in_file{ "../Challenge3/romeoandjuliet.txt" };

	std::cout << "Enter the substring to search for: ";
	std::string search_word;
	std::cin >> search_word;
	
	int match_cnt{ 0 };
	int word_cnt{ 0 };
	std::string word;
	while (in_file >> word){
		word_cnt++;

		if (word.find(search_word) != word.npos)
			match_cnt++;
	}
	in_file.close();

	std::cout << word_cnt << " words were searched..." << std::endl;
	std::cout << "The substring love was found " << match_cnt << " times"
		<< std::endl;

	return 0;
}


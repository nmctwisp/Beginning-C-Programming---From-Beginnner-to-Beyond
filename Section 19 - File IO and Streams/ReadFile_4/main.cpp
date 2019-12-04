#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class FileNotOpenException : std::exception {
public:
	FileNotOpenException() noexcept = default;
	~FileNotOpenException() = default;
	const char* what() const noexcept override {
		return "Problem opening file";
	}
};
int main() {
	
	std::ifstream in_file;
	
	
	in_file.open("../ReadFile_4/poem.txt");

	try {
		if (!in_file)
			throw FileNotOpenException{};
	}
	catch (FileNotOpenException &ex) {
		std::cerr << ex.what() << std::endl;
	}

	std::vector<char> char_vec{};
	char c{};
	while (in_file.get(c)){
		char_vec.push_back(c);
	}
	in_file.close();
	for (char& c : char_vec)
		std::cout << c;
	return 0;
}
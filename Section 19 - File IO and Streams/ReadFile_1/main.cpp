#include <iostream>
#include <fstream>
#include <exception>
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
	std::string line;
	int num;
	double total;


	in_file.open("../ReadFile_1/test.txt");


	try {
		if (!in_file)
			throw FileNotOpenException{};
	}
	catch (FileNotOpenException &ex) {
		std::cerr << ex.what() << std::endl;
		return 1;
	}

	in_file >> line >> num >> total;
	std::cout << line << std::endl;
	std::cout << num << std::endl;
	std::cout << total << std::endl;

	in_file.close();

	return 0;
}
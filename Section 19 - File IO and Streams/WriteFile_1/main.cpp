#include <iostream>
#include <fstream>
#include <string>
#include <exception>

class FileCreationException : public std::exception {
public:
	FileCreationException() noexcept = default;
	~FileCreationException() = default;
	const char* what() const noexcept override {
		return "File Cannot Be Created";
	}
};

int main() {
	
	std::ofstream out_file{"../WriteFile_1/output.txt", std::ios::app};

	try {
		if (!out_file)
			throw FileCreationException{};
	}
	catch (FileCreationException &ex) {
		std::cerr << ex.what() << std::endl;
		return 1;
	}

	
	std::cout << "Enter something to write to the file: ";
	// std::string word;
	// std::cin >> word;

	std::string line;
	std::getline(std::cin, line);
	
	out_file << line << std::endl;

	out_file.close();


}
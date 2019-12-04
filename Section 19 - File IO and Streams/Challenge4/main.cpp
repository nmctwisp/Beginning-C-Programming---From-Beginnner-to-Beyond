#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <iomanip>

class FileNotOpenException : std::exception {
public:
	FileNotOpenException() noexcept = default;
	~FileNotOpenException() = default;
	const char* what() const noexcept override {
		return "Problem opening file";
	}
};

class FileCreationException : public std::exception {
public:
	FileCreationException() noexcept = default;
	~FileCreationException() = default;
	const char* what() const noexcept override {
		return "File Cannot Be Created";
	}
};

int main() {

	std::ifstream infile{"../Challenge4/romeoandjuliet"};
	std::ofstream outfile{"../Challenge4/out_romeoandjuliet.txt"};

	try {
		if (!infile)
			throw FileNotOpenException{};
		if (!outfile)
			throw FileCreationException{};
	}
	catch (FileNotOpenException &ex) {
		std::cerr << ex.what() << std::endl;
	}
	catch (FileCreationException &ex) {
		std::cerr << ex.what() << std::endl;
	}
	int line_cnt {1};
	std::string line;
	while (std::getline(infile, line)) {
		outfile << std::setw(9) << std::left << line_cnt++ 
			<< line << std::endl;
	}
	infile.close();
	outfile.close();

	return 0;

}
#include <iostream>
#include <iomanip>
#include <fstream>
#include <exception>
#include <string>
#include <vector>

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


	in_file.open("../ReadFile_2/test.txt");


	try {
		if (!in_file)
			throw FileNotOpenException{};
	}
	catch (FileNotOpenException &ex) {
		std::cerr << ex.what() << std::endl;
		return 1;
	}
	std::vector<std::string> line_vec;
	std::vector<int> num_vec;
	std::vector<double> total_vec;

	while (in_file >> line >> num >> total) {
		
		std::cout << std::setw(10) << std::left << line
			<< std::setw(10) << num
			<< std::setw(10) << total
			<< std::endl;
	
		line_vec.push_back(line);
		num_vec.push_back(num);
		total_vec.push_back(total);
	}

	in_file.close();

	return 0;
}
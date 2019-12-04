#include <iostream>
#include <fstream>
#include<string>
#include<vector>

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

	in_file.open("../ReadFile_3/poem.txt");
	
	try {
		if (!in_file)
			throw FileNotOpenException{};
	}
	catch (FileNotOpenException &ex) {
		std::cout << ex.what() << std::endl;
	}
	
	std::vector<std::string> line_vec;
	std::string line;

	//while (std::getline(in_file, line)) {
	//	std::cout << line << std::endl;
	//	line_vec.push_back(line);
	//}

	//while (in_file.good())
	//	std::getline(in_file, line);
	//	line_vec.push_back(line);
	
	//while (std::getline(in_file, line)) {
	//	line_vec.push_back(line);
	//}
	
	while (in_file >> line){
		line_vec.push_back(line);
	}

	in_file.close();


}
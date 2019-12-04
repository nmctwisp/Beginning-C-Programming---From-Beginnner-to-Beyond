#include <iostream>
#include <fstream>
#include <string>
#include <exception>

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
	std::ifstream in_file{ "../CopyFile_2/poem.txt" };
	std::ofstream out_file{ "../CopyFile_2/poem_out.txt" };

	try {
		if (!out_file)
			throw FileCreationException{};

		if (!in_file)
			throw FileNotOpenException{};
	}
	catch (FileCreationException &ex) {
		std::cerr << ex.what() << std::endl;
	}
	catch (FileNotOpenException &ex) {
		std::cerr << ex.what() << std::endl;
	}

	char character;
	while (in_file.get(character)) {
		out_file.put(character);
	}

	in_file.close();
	out_file.close();
	return 0;
}
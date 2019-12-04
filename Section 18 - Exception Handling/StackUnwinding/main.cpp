#include <iostream>
void func_b();

void func_a() {
	std::cout << "Entering func_a" << std::endl;
	try {
		func_b();
	}
	catch (int &ex) {
		std::cout << "Caught and Error in func_a" << std::endl;
	}
	std::cout << "Exiting func_a" << std::endl;
}

void func_c();
void func_b() {
	std::cout << "Entering func_b" << std::endl;
	try {
		func_c();
	}
	catch (int &ex) {
		std::cout << "Caught and Error in func_b" << std::endl;
	}
	std::cout << "Exiting func_b" << std::endl;
}

void func_c() {
	std::cout << "Entering func_c" << std::endl;
	throw 0;
	std::cout << "Exiting func_c" << std::endl;
}

int main() {
	std::cout << "Entering Main" << std::endl;
	try {
		func_a();
	}
	catch (int &ex) {
		std::cout << "Caught and Error in Main" << std::endl;
	}
	
	std::cout << "Exiting Main";

	return 0;
}
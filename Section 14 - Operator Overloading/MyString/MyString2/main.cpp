#include "MyString2.h"


int main() {
	MyString2 ms{ "hellO" };
	-ms;
	MyString2 ms2 = MyString2("hellO");
	MyString2 ms3{ "again" };

	std::cout << (ms == ms2) << std::endl;
	std::cout << (ms == ms3) << std::endl;

	std::cout << (ms != ms2) << std::endl;
	std::cout << (ms != ms3) << std::endl;

	return 0;
}
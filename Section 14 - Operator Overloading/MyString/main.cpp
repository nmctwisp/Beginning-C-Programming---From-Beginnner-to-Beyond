#include "MyString1.h"
#include "MyString2.h"


int main() {

	{
		MyString1 ms{ "hellO" };
		-ms;
		MyString1 ms2 = MyString1("hellO");
		MyString1 ms3{ "again" };

		std::cout << (ms == ms2) << std::endl;
		std::cout << (ms == ms3) << std::endl;

		std::cout << (ms != ms2) << std::endl;
		std::cout << (ms != ms3) << std::endl;
	}

	{
		MyString2 ms{ "hellO" };
		MyString2 ms2 = MyString2("hellO");
		MyString2 ms3{ "again" };

		std::cout << (-ms + ms3) << std::endl;

		std::cout << (ms == ms2) << std::endl;
		std::cout << (ms == ms3) << std::endl;

		std::cout << (ms != ms2) << std::endl;
		std::cout << (ms != ms3) << std::endl;
	}
	return 0;
}
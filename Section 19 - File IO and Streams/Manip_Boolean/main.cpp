#include <iostream>
#include <iomanip>

int main() {
	
	
	{std::cout << "\n=================== Part 1 ===================\n" << std::endl;
		
		std::cout << "noboolalpha - default (10 == 10), Result: " << (10 == 10) << std::endl;
		std::cout << "noboolalpha - default (10 == 20), Result: " << (10 == 20) << std::endl;
		
	}

	{std::cout << "\n=================== Part 2 ===================\n" << std::endl;

		// Set to true/false formatting
		std::cout << std::boolalpha; // change stream output for bool from 1/0 to true/false
		std::cout << "noboolalpha - default (10 == 10), Result: " << (10 == 10) << std::endl;
		std::cout << "noboolalpha - default (10 == 20), Result: " << (10 == 20) << std::endl;

		// Setting still stays for future boolean insertions
		std::cout << "noboolalpha - default (10 == 10), Result: " << (10 == 10) << std::endl;
		std::cout << "noboolalpha - default (10 == 20), Result: " << (10 == 20) << std::endl;

		// Toggling back to 1/0 formatting
		std::cout << std::noboolalpha; // change stream output for bool from true/false to 1/0
		std::cout << "noboolalpha - default (10 == 10), Result: " << (10 == 10) << std::endl;
		std::cout << "noboolalpha - default (10 == 20), Result: " << (10 == 20) << std::endl;
	}

	{std::cout << "\n=================== Part 3 ===================\n" << std::endl;

		// Notice how the formatting does NOT reset when crossing between local spaces
		std::cout << "noboolalpha - default (10 == 10), Result: " << (10 == 10) << std::endl;
		std::cout << "noboolalpha - default (10 == 20), Result: " << (10 == 20) << std::endl;

		// Set back to true/false formatting via setf method	
		std::cout.setf(std::ios::boolalpha);
		std::cout << "noboolalpha - default (10 == 10), Result: " << (10 == 10) << std::endl;
		std::cout << "noboolalpha - default (10 == 20), Result: " << (10 == 20) << std::endl;

		// Reset to default which is 1/0
		std::cout << std::resetiosflags(std::ios::boolalpha);
		std::cout << "noboolalpha - default (10 == 10), Result: " << (10 == 10) << std::endl;
		std::cout << "noboolalpha - default (10 == 20), Result: " << (10 == 20) << std::endl;
	}
	return 0;
}
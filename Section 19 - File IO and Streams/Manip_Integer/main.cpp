#include <iostream>
#include <iomanip>

int main() {

	int num{ 255 };

	
	{std::cout << "\n=================== Part 1 ===================\n" << std::endl;
		// Display integer using different bases

		std::cout << std::dec << num << std::endl;
		std::cout << std::hex << num << std::endl;
		std::cout << std::oct << num << std::endl;
	}

	{std::cout << "\n=================== Part 2 ===================\n" << std::endl;
		// Display showing the base prefix for hex and oct
		
		std::cout << std::showbase;
		std::cout << std::dec << num << std::endl;
		std::cout << std::hex << num << std::endl;
		std::cout << std::oct << num << std::endl;
		std::cout << std::noshowbase;
	}

	{std::cout << "\n=================== Part 3 ===================\n" << std::endl;
		// Display the hex value in uppercase

		std::cout << std::showbase << std::uppercase;
		std::cout << std::hex << num << std::endl;

		// Resetting to defaults
		std::cout << std::resetiosflags(std::ios::uppercase);
		std::cout << std::resetiosflags(std::ios::showbase);
	}

	{std::cout << "\n=================== Part 4 ===================\n" << std::endl;
		// Display positive sign for base 10 numbers;

		std::cout << std::showpos;
		std::cout << std::dec << num << std::endl;
		std::cout << std::hex << num << std::endl;
		std::cout << std::oct << num << std::endl;

		// Setting using the set method
		std::cout.setf(std::ios::showbase);
		std::cout.setf(std::ios::uppercase);
		std::cout.setf(std::ios::showpos);

		// Resetting to defaults
		std::cout << std::resetiosflags(std::ios::basefield);
		std::cout << std::resetiosflags(std::ios::uppercase);
		std::cout << std::resetiosflags(std::ios::showbase);
		std::cout << std::resetiosflags(std::ios::showpos);	
	}
	{std::cout << "\n=================== Part 5 ===================\n" << std::endl;
		
		std::cout << "Enter an integer: ";
		std::cin >> num;

		std::cout << "Decimal Default: " << num << std::endl << std::endl;

		std::cout << "Hexadecimal: " << std::hex << num << std::endl;
		std::cout << "Hexadecimal: " << std::uppercase << num << std::endl;
		std::cout << "Hexadecimal: " << num << std::endl;
		std::cout << "Hexadecimal: " << std::nouppercase << num << std::endl;

		std::cout << "Octal: " << std::oct << num << std::endl;
		std::cout << "Hexadecimal: " << std::hex << std::showbase << num << std::endl;
		std::cout << "Octal: " << std::oct << num << std::endl;

		std::cout << std::endl << std::endl;
	}


	return 0;
}
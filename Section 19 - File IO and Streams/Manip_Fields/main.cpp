#include <iostream>
#include <string>
#include <iomanip>

void ruler() {
	std::cout << "\n12345678901234567890123456789012345678901234567890" << std::endl;
}

int main() {
	int num1{ 1234 };
	double num2{ 1234.5678 };
	std::string hello{ "Hello" };

	{std::cout << "\n=================== Defaults ===================\n" << std::endl;
		// Default Precision is set to 6 across floating notation 
		
		ruler();
		std::cout << num1 << num2 << hello << std::endl; // 12341234.5678hello
	}
	{std::cout << "\n=================== Defaults One Per Line =======\n" << std::endl;
		// Default Precision is set to 6 across floating notation 
		
		ruler();
		std::cout << num1 << std::endl;  // 1234
		std::cout << num2 << std::endl;  // 1234.5678
		std::cout << hello << std::endl; // hello
	}

	{std::cout << "\n============ Width 10 for num1 ===================\n" << std::endl;
		// Set field width to 10, Note the default justification is right for num1 only!
		
		ruler();
		std::cout << std::setw(10) << num1 << num2 << hello << std::endl; //      12341234.57Hello
	}

	{std::cout << "\n============ Width 10 for num1 and num2 ===========\n" << std::endl;
		// Set field width to 10 for all 3 outputs, Note the default justification is RIGHT for both
		
		ruler();
		std::cout << std::setw(10);
		std::cout << num1;
		std::cout << std::setw(10);
		std::cout << num2 << std::endl; 
		//       1234   1234.57
	}

	{std::cout << "\n============ Width 10 for num1, num2 and hello =====\n" << std::endl;
		// Set field width to 10 for all 3 outputs, Note the default justification is RIGHT for all
		
		ruler();
		std::cout << std::setw(10) << num1 << std::setw(10) << num2 << std::setw(10) << hello << std::endl;
		//      1234   1234.57     Hello
	}
	{std::cout << "\n==== Width 10 for num1, num2 and hello align left ===\n" << std::endl;
		// Set field width to 10 for all 3 outputs and justify all left
	
		ruler();
		std::cout << std::setw(10) << std::left << num1;
		std::cout << std::setw(10) << std::left << num2;
		std::cout << std::setw(10) << std::left << hello << std::endl;
	}
	{
		std::cout << "\n===== Width 10 for num1, num2, hello left fill =======\n" << std::endl;
		// Set fill to a dash, this is persistent so you don't need to add another stream manipulator

		ruler();
		std::cout << std::setfill('-');
		std::cout << std::setw(10) << std::left << num1;
		std::cout << std::setw(10) << std::left << num2;
		std::cout << std::setw(10) << std::left << hello << std::endl;
	}
	{
		std::cout << "\n===== Width 10 for num1, num2, hello left fill vary ===\n" << std::endl;
		// Set width to 10 for all, left justify all and cary the setfill character

		ruler();
		std::cout << std::setfill('*');
		std::cout << std::setw(10) << std::left << num1;
		std::cout << std::setfill('#');
		std::cout << std::setw(10) << std::left << num2;
		std::cout << std::setfill('-');
		std::cout << std::setw(10) << std::left << hello << std::endl;
	}
	return 0;
}


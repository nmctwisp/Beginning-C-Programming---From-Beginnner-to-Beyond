#include <iostream>
#include <iomanip>

int main() {
	double num1{ 123456789.987654321 };
	double num2{ 1234.5678 };
	double num3{ 1234.0 };

	{std::cout << "\n=================== Defaults ===================\n" << std::endl;
		// Default Precision is set to 6 across floating notation 

		std::cout << num1 << std::endl; // 1.23457e+08
		std::cout << num2 << std::endl; // 1234.57
		std::cout << num3 << std::endl; // 1234

	}

	{std::cout << "\n=================== Precision 2 =================\n" << std::endl;	
		//Notice that since we cannot display the doubles in precision 2, scientific notation is used instead

		std::cout << std::setprecision(2);
		std::cout << num1 << std::endl; // 1.2e+08
		std::cout << num2 << std::endl; // 1.2e+03
		std::cout << num3 << std::endl; // 1.2e+03
	}

	{std::cout << "\n=================== Precision 5 =================\n" << std::endl;

		std::cout << std::setprecision(5);
		std::cout << num1 << std::endl; // 1.2346e+08
		std::cout << num2 << std::endl; // 1234.6
		std::cout << num3 << std::endl; // 1234
	}

	{std::cout << "\n=================== Precision 9 =================\n" << std::endl;

		std::cout << std::setprecision(9);
		std::cout << num1 << std::endl; // 123456790
		std::cout << num2 << std::endl; // 1234.5678
		std::cout << num3 << std::endl; // 1234
	}
	{std::cout << "\n=================== Precision 3 & Fixed ==========\n" << std::endl;

		std::cout << std::setprecision(3) << std::fixed;
		std::cout << num1 << std::endl; // 123456789.988
		std::cout << num2 << std::endl; // 1234.568
		std::cout << num3 << std::endl; // 1234.000
	}
	{std::cout << "\n=================== Precision 3 & Scentific =======\n" << std::endl;

	std::cout << std::setprecision(3) << std::scientific;
	std::cout << num1 << std::endl; // 1.235e+08
	std::cout << num2 << std::endl; // 1.235e+03
	std::cout << num3 << std::endl; // 1.234e+03
	}
	{std::cout << "\n========= Precision 3, Scentific & Uppercase =======\n" << std::endl;
		// Only works for scentific notion, where the lowercase e is changed to an uppercase E

		std::cout << std::setprecision(3) << std::scientific << std::uppercase;
		std::cout << num1 << std::endl; // 1.235E+08
		std::cout << num2 << std::endl; // 1.235E+03
		std::cout << num3 << std::endl; // 1.234E+03
	}
	{std::cout << "\n========= Precision 3, Fixed & Positive =============\n" << std::endl;

		std::cout << std::setprecision(3) << std::fixed<< std::showpos;
		std::cout << num1 << std::endl; // +123456789.988
		std::cout << num2 << std::endl; // +1234.568
		std::cout << num3 << std::endl; // +1234.000
		
		// Back to defaults
		std::cout.unsetf(std::ios::scientific | std::ios::fixed);
		std::cout << std::resetiosflags(std::ios::showpos);
	}
	{std::cout << "\n========= Precision 10, Show Point ===================\n" << std::endl;
		// Show trailing zeroes up to precision 10

		std::cout << std::setprecision(10) << std::fixed << std::showpoint;
		std::cout << num1 << std::endl; // 123456789.9876543283
		std::cout << num2 << std::endl; // 1234.5678000000
		std::cout << num3 << std::endl; // 1234.0000000000
	}
	{std::cout << "\n========= Back to Defaults ============================\n" << std::endl;
		// Show trailing zeroes up to precision 10

		std::cout.unsetf(std::ios::scientific | std::ios::fixed);
		std::cout << std::setprecision(6);
		std::cout << std::resetiosflags(std::ios::showpos);
		std::cout << std::resetiosflags(std::ios::showpoint);

		std::cout << num1 << std::endl; // 1.23457e+08
		std::cout << num2 << std::endl; // 1234.57
		std::cout << num3 << std::endl; // 1234
	}
	return 0;
}


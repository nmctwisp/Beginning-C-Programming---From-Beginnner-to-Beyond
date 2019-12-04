#include <iostream>

double calculate_mpg(int miles, int gallons) {
	if (gallons == 0)
		throw 0;
	
	return static_cast<double>(miles) / gallons;


}

int main() {
	int miles{};
	int gallons{};
	double miles_per_gallon{};

	std::cout << "Enter the miles: ";
	std::cin >> miles;
	std::cout << "Enter the gallons: ";
	std::cin >> gallons;
	
	try {
		miles_per_gallon = calculate_mpg(miles, gallons);
	}
	catch (int &ex) {
		std::cerr << "Cannot Divde By Zero" << std::endl;
	}
	

	std::cout << "Result: " << miles_per_gallon << std::endl;
	std::cout << "Bye" << std::endl;
	return 0;
}
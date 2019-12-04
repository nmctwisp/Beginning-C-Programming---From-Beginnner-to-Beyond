#include <iostream>
#include <string>

class DivideByZeroException{
private:
	std::string err_msg = "Cannot Divde By Zero";
public:
	DivideByZeroException() {
		std::cout << "DivideByZeroException::DivideByZeroException()" << std::endl;
	}
	~DivideByZeroException() {
		std::cout << "DivideByZeroException::~DivideByZeroException()" << std::endl;
	}

	std::string get_err_msg() const {
		return err_msg;
	}
};

class NegativeValueException{
private:
	std::string err_msg = "Negative Value Error";
public:
	NegativeValueException() {
		std::cout << "NegativeValueException::NegativeValueException()" << std::endl;
	}
	~NegativeValueException() {
		std::cout << "NegativeValueException::~NegativeValueException()" << std::endl;
	}

	std::string get_err_msg() const {
		return err_msg;
	}
};


double calculate_mpg(int miles, int gallons) {
	if (gallons == 0)
		throw DivideByZeroException{};

	if (miles < 0 || gallons < 0)
		throw NegativeValueException{};

	return static_cast<double>(miles) / gallons;
	
}

int main() {
	int miles{};
	int gallons{};
	double miles_per_gallon{};

	std::cout << "Enter the number of miles: ";
	std::cin >> miles;
	std::cout << "Enter the number of gallons: ";
	std::cin >> gallons;

	try {
		miles_per_gallon = calculate_mpg(miles, gallons);
		std::cout << "Result: " << miles_per_gallon <<std::endl;
	}
	catch (const DivideByZeroException& ex) {
		std::cerr << ex.get_err_msg() << std::endl;
	}
	catch (const NegativeValueException& ex) {
		std::cerr << ex.get_err_msg() << std::endl;
	}

	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "MyPair.h"

// Template Classes are typically completely conatined within the header files
// So, we would have the template class in Item.h and no Item.cpp file would be used

int main() {
	Item<int> item1{ "Frank", 100 };
	std::cout << item1.get_name() << " " << item1.get_value() << std::endl;

	Item<std::string> item2{ "Frank", "Professor" };
	std::cout << item2.get_name() << " " << item2.get_value() << std::endl;

	Item<Item<std::string>> item3{ "Frank", {"C++", "Professor"} };
	std::cout << item3.get_name()
		<< " " << item3.get_value().get_name()
		<< " " << item3.get_value().get_value()
		<< std::endl;

	std::cout << "\n================================" << std::endl;

	std::vector<Item<double>> stooges{};
	stooges.push_back(Item<double>("Larry", 100.0));
	stooges.push_back(Item<double>("Moe", 200.0));
	stooges.push_back(Item<double>("Curly", 300.0));
	
	for (const auto& stooge : stooges)
		std::cout << stooge.get_name() << " " << stooge.get_value() << std::endl;

	std::cout << "\n================================" << std::endl;

	MyPair<std::string, int> p1{ "Frank", 100 };
	MyPair<int, double> p2{124, 13.6};

	std::cout << p1.first << ", " << p1.second << std::endl;
	std::cout << p1.first << ", " << p2.second << std::endl;
	return 0;
}
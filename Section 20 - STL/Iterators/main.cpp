#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <string>

// Display any vector of integers using range-based for loop
void display(const std::vector<int> & vec) {
	std::cout << "[ ";
	for (auto const& i : vec)
		std::cout << i;
	std::cout << " ]" << std::endl;
}

void test1() {
	std::cout << "\n=============================" << std::endl;
	std::vector<int> nums1{ 1, 2, 3, 4, 5 };

	auto it = nums1.begin();			// returns a pointer, pointing at 1
	std::cout << *it << std::endl;		// it pointing to 1

	it++;
	std::cout << *it << std::endl;		// it pointing to 2

	it+=2;
	std::cout << *it << std::endl;		// it pointing to 4

	it-=2;
	std::cout << *it << std::endl;		// it pointing to 2

	it = nums1.end() - 1;
	std::cout << *it << std::endl;		// it pointing to 5
}

void test2() {
	std::cout << "\n=============================" << std::endl;
	std::vector<int> nums1{ 1, 2, 3, 4, 5 };

	// Displays all vector elements using an iterator
	std::vector<int>::iterator it = nums1.begin();
	while (it != nums1.end()) {
		std::cout << *it << std::endl;
		it++;
	}

	// Change all vector elements to 0
	it = nums1.begin();
	while (it != nums1.end()) {
		*it = 0;
		it++;
	}

	display(nums1);
}

void test3() {
	std::cout << "\n=============================" << std::endl;
	std::vector<int> nums1{ 1, 2, 3, 4, 5 };

	// Constant Iterator
	std::vector<int>::const_iterator it1 = nums1.begin();
	// auto it1 = nums1.cbeing(); // returns a constant iterator pointing to the beginning element

	while (it1 != nums1.end()) {
		std::cout << *it1 << std::endl;
		it1++;
	}
	
	// remember that this is a constant iterator, so you cannot use it to change the values of elements
}

void test4() {
	std::cout << "\n=============================" << std::endl;
	std::vector<int> nums1{ 1, 2, 3, 4, 5 };

	// Reverse Iterator
	auto it1 = nums1.rbegin();				// returns a reverse iterator pointing at 5
	while (it1 != nums1.rend()) {
		std::cout << *it1 << std::endl;
		it1++;
	}

	// Const Reverse Iterator over a List
	std::list<std::string> names{ "Larry", "Moe", "Curly" };
	auto it2 = names.crbegin();				// returns a const reverse iterator pointing at Curly
	while (it2 != names.crend()) {
		std::cout << *it2 << std::endl;
		it2++;
	}
	
	// Iterator over a Map
	std::map<std::string, std::string> favorites{
		{"Frank", "C++"},
		{"Bill", "Java"},
		{"James", "Haskell"}
	};

	auto it3 = favorites.begin();			// returns a regular iterator pointing to the first string pair {"Frank", "C++"}

	while (it3 != favorites.end()){
		std::cout	
			<< it3->first
			<< " "
			<< it3->second 
			<< std::endl;
		it3++;
	}
}	

void test5() {
	std::cout << "\n=============================" << std::endl;
	std::vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	auto start = vec.begin() + 2;
	auto finish = vec.end() - 3;

	while (start != finish){
		std::cout << *start << std::endl;
		start++;
	}
}

int main() {

	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}
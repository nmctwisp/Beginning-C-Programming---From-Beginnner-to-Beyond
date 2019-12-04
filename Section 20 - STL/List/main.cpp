#include "Person.h"
#include <string>
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

template <typename T>
void display(const std::list<T>& lst) {
	std::cout << "[ ";
	for (const auto& elem : lst)
		std::cout << elem << " ";
	std::cout << "]" << std::endl;
}

void test1() {
	std::cout << "\n================ Test 1 ================" << std::endl;

	std::list<int> lst1{ 1,2,3,4,5 };
	display(lst1);

	std::list<std::string> lst2;
	lst2.push_back("Back");
	lst2.push_front("Front");
	display(lst2);

	std::list<int> lst3;
	lst3 = { 1,2,3,4,5,6,7,8,9,10 };
	display(lst3);

	std::list<int> lst4(10, 100);	// ten 100s
	display(lst4);
}
void test2() {
	std::cout << "\n================ Test 2 ================" << std::endl;
	
	std::list<int> lst{ 1,2,3,4,5,6,7,8,9,10 };
	display(lst);

	std::cout << "Size: " << lst.size() << std::endl;
	std::cout << "Front: " << lst.front() << std::endl;
	std::cout << "Back: " << lst.back() << std::endl;

	lst.clear();
	display(lst);
	std::cout << "Size: " << lst.size() << std::endl;
}
void test3() {
	std::cout << "\n================ Test 3 ================" << std::endl;

	std::list<int> lst{ 1,2,3,4,5,6,7,8,9,10 };
	display(lst);

	lst.resize(5);
	display(lst);

	lst.resize(10);
	display(lst);

	std::list<Person> persons;
	persons.resize(5);
	display(persons);
}
void test4() {
	std::cout << "\n================ Test 4 ================" << std::endl;

	std::list<int> lst{ 1,2,3,4,5,6,7,8,9,10 };
	display(lst);

	auto it = std::find(lst.begin(), lst.end(), 5);
	if (it != lst.end()) 
		lst.insert(it, 100); // 5 gets pushed to position 6 after insert
							 // iterator is still pointing to 5.

	display(lst);

	std::advance(it, -1);	// change pointer relative to current positon
							// 5 is now in position 6, so to point to 100
							// the index needs to shift by -1.
	std::cout << *it << std::endl;
	display(lst);

	lst.erase(it); // removes the 100 from the list and the iterator becomes invalid
	display(lst);
}
void test5() {
	std::cout << "\n================ Test 5 ================" << std::endl;
	
	std::list<Person> stooges{
		{"Larry", 18},
		{"Moe", 25},
		{"Curly", 17},
	};

	display(stooges);
	
	std::string name;
	int age{};
	std::cout << "\nEnter the name of the next stooge: ";
	std::getline(std::cin, name);
	std::cout << "Enter their age: ";
	std::cin >> age;

	stooges.emplace_back(name, age);
	display(stooges);

	// Insert Before Moe
	auto it = std::find(stooges.begin(), stooges.end(), Person{ "Moe", 25 });
	// stooges.insert(it, Person{ "Chen", 32 });
	if (it != stooges.end())
		stooges.emplace(it, "Chen", 32);
	display(stooges);
}
void test6() {
	std::cout << "\n================ Test 6 ================" << std::endl;

	std::list<Person> stooges{
		{"Larry", 18},
		{"Moe", 25},
		{"Curly", 17},
	};

	display(stooges);
	stooges.sort();
	display(stooges);
}

int main() {

	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	std::cout << std::endl;
	return 0;
}
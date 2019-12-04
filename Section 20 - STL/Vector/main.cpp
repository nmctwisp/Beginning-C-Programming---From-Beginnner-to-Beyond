#include "Person.h"
#include <vector>
#include <algorithm>
#include <iostream>

// Use for_each and a lambda expression to display vector elements
void display2(const std::vector<int> &vec) {
	std::cout << "[ ";
	std::for_each(vec.begin(), vec.end(),
		[](int x) { std::cout << x << " "; });
	std::cout << "]" << std::endl;
}

// template function to display any vector
template <typename T>
void display(const std::vector<T> &vec) {
	std::cout << "[ ";
	for (const auto &elem : vec)
		std::cout << elem << " ";
	std::cout << "]" << std::endl;
}

void test1() {
	std::cout << "\n================ Test 1 ================" << std::endl;

	std::vector<int> vec{ 1, 2, 3, 4, 5 };
	display(vec);

	vec = { 2, 4, 5, 6 };
	display2(vec);

	std::vector<int> vec1{ 10, 100 };
	display(vec1);
}
void test2() {
	std::cout << "\n================ Test 2 ================" << std::endl;

	std::vector<int> vec{ 1, 2, 3, 4, 5 };
	display(vec);
	std::cout << "\nvecsize: " << vec.size() << std::endl;
	std::cout << "vec max size: " << vec.max_size() << std::endl;
	std::cout << "vec capcity: " << vec.capacity() << std::endl;

	vec.push_back(6);
	display(vec);
	std::cout << "\nvecsize: " << vec.size() << std::endl;
	std::cout << "vec max size: " << vec.max_size() << std::endl;
	std::cout << "vec capcity: " << vec.capacity() << std::endl;

	vec.shrink_to_fit(); // C++11
	display(vec);
	std::cout << "\nvecsize: " << vec.size() << std::endl;
	std::cout << "vec max size: " << vec.max_size() << std::endl;
	std::cout << "vec capcity: " << vec.capacity() << std::endl;

	vec.reserve(100);
	display(vec);
	std::cout << "\nvecsize: " << vec.size() << std::endl;
	std::cout << "vec max size: " << vec.max_size() << std::endl;
	std::cout << "vec capcity: " << vec.capacity() << std::endl;
}
void test3() {
	std::cout << "\n================ Test 3 ================" << std::endl;

	std::vector<int> vec{ 1, 2, 3, 4, 5 };
	display(vec);

	vec[0] = 100;
	vec.at(1) = 200;

	display(vec);
}
void test4() {
	std::cout << "\n================ Test 4 ================" << std::endl;

	std::vector<Person> stooges;

	Person p1{ "Larry", 18 };
	display(stooges);

	stooges.push_back(p1);
	display(stooges);

	stooges.push_back({ "Moe", 25 });
	display(stooges);

	stooges.emplace_back("Moe", 25);
	display(stooges);
}
void test5() {
	std::cout << "\n================ Test 5 ================" << std::endl;

	std::vector<Person> stooges{
		{"Larry", 18},
		{"Moe", 25},
		{"Curly", 30}
	};

	display(stooges);
	std::cout << "\nFront: " << stooges.front() << std::endl;
	std::cout << "Back: " << stooges.back() << std::endl;

	stooges.pop_back();
	display(stooges);
}
void test6() {
	std::cout << "\n================ Test 6 ================" << std::endl;

	std::vector<int> vec{ 1, 2, 3, 4, 5, };
	display(vec);

	vec.clear();
	display(vec);

	vec = { 1,2,3,4,5,6,7,8,9,10 };
	display(vec);
	vec.erase(vec.begin(), vec.begin() + 2);
	display(vec);

	vec = { 1,2,3,4,5,6,7,8,9,10 };
	// Erase only even numbers
	auto it = vec.begin();
	while (it != vec.end()) {
		if ((*it % 2) == 0)
			it = vec.erase(it);
		else
			it++;   // only increment if not erased!
	}
	display(vec);
}
void test7() {
	std::cout << "\n================ Test 7 ================" << std::endl;

	std::vector<int> vec1{ 1, 2, 3, 4, 5 };
	std::vector<int> vec2{ 10, 20, 30, 40, 50 };
	
	display(vec1);
	display(vec2);
	std::cout << std::endl;

	vec2.swap(vec1);
	display(vec1);
	display(vec2);
}
void test8() {
	std::cout << "\n================ Test 8 ================" << std::endl;

	std::vector<int> vec1{ 1, 21, 3, 40, 12 };
	
	display(vec1);
	std::sort(vec1.begin(), vec1.end());
	display(vec1);

}
void test9() {
	std::cout << "\n================ Test 9 ================" << std::endl;    
	// std::back_inserter contructs a back-insert iterator that inserts new elements 
	// at the end of the container it applied to. It's a special output iterator
	// It's awesome!!!!   and  very efficient
	// There is also a front_inserter we can use with deques and lists
	// Copy one list to another using an iterator and back_inserter

	std::vector<int> vec1{ 1,2,3,4,5 };
	std::vector<int> vec2{ 10,20 };

	display(vec1);
	display(vec2);
	
	std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
	display(vec1);
	display(vec2);
	std::cout << std::endl;

	// Copy_if the element is even
	vec1 = { 1,2,3,4,5,6,7,8,9,10 };
	vec2 = { 10,20 };
	display(vec1);
	display(vec2);

	std::cout << std::endl;
	std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2),
		[](int x) {return x % 2 == 0; });
	display(vec1);
	display(vec2);
}
void test10() {
	std::cout << "\n================ Test 10 ===============" << std::endl;
	// transform over 2 ranges

	std::vector<int> vec1{ 1,2,3,4,5 };
	std::vector<int> vec2{ 10,20,30,40,50 };
	std::vector<int> vec3;

	// 1*10, 2*20, 3*30, 4*40, 5*50 and store the results in vec3
	std::transform(vec1.begin(), vec1.end(), vec2.begin(), std::back_inserter(vec3),
		[](int x, int y) {
			return x * y;
		}
	);

	display(vec3);
}
void test11() {
	std::cout << "\n================ Test 11 ===============" << std::endl;
	std::vector<int> vec1{ 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> vec2{ 100,200,300,400 };

	display(vec1);
	display(vec2);
	std::cout << std::endl;

	// Insertion from another vector
	// Insert vec2 into vec1 before the 5
	auto it = std::find(vec1.begin(), vec1.end(), 5);
	if (it != vec1.end()) {
		std::cout << "inserting..." << std::endl;
		vec1.insert(it, vec2.begin(), vec2.end());
	}
	else{
		std::cout << "Sorry, 5 not found" << std::endl;
	}
	display(vec1);
	// [ 1 2 3 4 100 200 300 400 5 6 7 8 9 10 ]
}

int main() {

	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	test11();

	return 0;
}
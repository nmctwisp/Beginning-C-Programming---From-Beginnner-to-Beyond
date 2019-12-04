#include <iostream>
#include <queue>
#include "Person.h"
#include <string>

// This displays the priority queue by
// repeatedly topping and popping the priority queue
// It is being passed by value so we don't modify the 
// priority queue being passed in

template <typename T>
void display(std::priority_queue<T> pq) {
	std::cout << "[ ";
	while (!pq.empty()) {
		T elem = pq.top();
		pq.pop();
		std::cout << elem << " ";
	}
	std::cout << "]" << std::endl;
}

void test1() {
	std::cout << "\n================ Test 1 ================" << std::endl;
	
	std::priority_queue<int> pq;
	for (int i : {3, 5, 7, 12, 23, 12, 4, 100, 0, 3, 5, 7})
		pq.push(i);

	std::cout << "Size: " << pq.size() << std::endl;
	std::cout << "Top: " << pq.top() << std::endl;

	display(pq);
	
	pq.pop();
	display(pq);
}
void test2() {
	std::cout << "\n================ Test 2 ================" << std::endl;
	
	std::priority_queue<Person> pq;

	pq.push(Person{ "A", 10 });
	pq.push(Person{ "B", 1 });
	pq.push(Person{ "C", 14 });
	pq.push(Person{ "D", 18 });
	pq.push(Person{ "E", 7 });
	pq.push(Person{ "F", 27 });

	display(pq);
}

int main() {
	test1();
	test2();
	return 0;
}

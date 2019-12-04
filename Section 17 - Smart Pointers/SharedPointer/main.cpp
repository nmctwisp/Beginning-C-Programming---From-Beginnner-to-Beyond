// Section 17
// Shared Pointers
#include <iostream>
#include <memory>
#include <vector>
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"


class Test {
private:
	int data;
public:
	Test()
		: data{ 0 } {
		std::cout << "Test::Test(" << data << ")" << std::endl;
	}
	Test(int data)
		: data{ data } {
		std::cout << "Test::Test(" << data << ")" << std::endl;
	}
	~Test() {
		std::cout << "Test::~Test()" << std::endl;
	}
	int get_data() const {
		return data;
	}
};

void func(std::shared_ptr<Test> p) {
	std::cout << "Used Count: " << p.use_count() << std::endl;
}

int main() {

	std::cout << "=================== Section 1 ===================" << std::endl;
	{
		// use_count - returns the # of shared_ptr objects
		// managing the heap object

		std::shared_ptr<int> p1{ new int{100} };
		std::cout << "Use count: " << p1.use_count() << std::endl;

		// unlike unique_ptr shared_ptr can copied
		std::shared_ptr<int> p2{ p1 };
		std::cout << "Use count: " << p1.use_count() << std::endl;

		// resets the p1 shared_ptr, decrements the use_count
		// and p1 is nulled out
		p1.reset();
		std::cout << "Use count: " << p1.use_count() << std::endl;
		std::cout << "Use count: " << p2.use_count() << std::endl;
	}

	std::cout << "\n=================== Section 2 ===================\n" << std::endl;
	{
		std::shared_ptr<Test> ptr = std::make_shared<Test>(100);
		func(ptr);
		std::cout << "Used Count: " << ptr.use_count() << std::endl;

		{
			std::shared_ptr<Test> ptr1 = ptr;
			std::cout << "Used Count: " << ptr.use_count() << std::endl;
			{
				std::shared_ptr<Test> ptr2 = ptr;
				// 3 - [ptr, ptr1 and ptr2]
				std::cout << "Used Count: " << ptr.use_count() << std::endl;
				// ptr was reset to nullptr, decrement use_count
				ptr.reset();
				// 2 - [ptr1 and ptr2]
				std::cout << "Used Count: " << ptr1.use_count() << std::endl; 
			} // ptr2 fell out of scope, decrement use_count
			// 1 - [ptr1]
			std::cout << "Used Count: " << ptr1.use_count() << std::endl; 
		} // ptr1 fell out of scope, decrement use_count
		// 0 - call deconstructor on the shared resource
		std::cout << "Used Count: " << ptr.use_count() << std::endl; 
	}
	std::cout << "\n=================== Section 3 ===================\n" << std::endl;
	{
		std::shared_ptr<Account> acct1 = std::make_shared<Trust_Account>("Larry", 10000, 3.1);
		std::shared_ptr<Account> acct2 = std::make_shared<Savings_Account>("Moe", 5000, 1.5);
		std::shared_ptr<Account> acct3 = std::make_shared<Checking_Account>("Curly", 6000);
		{

		}
		std::vector<std::shared_ptr<Account>> accounts;
		// std::vector::push_back copies the object
		accounts.push_back(acct1);
		accounts.push_back(acct2);
		accounts.push_back(acct3);

		for (const auto acc : accounts) {
			std::cout << *acc << std::endl;
			std::cout << "Used Count: "  <<acc.use_count() << std::endl;
		}

		for (const auto &acc : accounts) {
			std::cout << *acc << std::endl;
			std::cout << "Used Count: " << acc.use_count() << std::endl;
		}
	}
    return 0;
}


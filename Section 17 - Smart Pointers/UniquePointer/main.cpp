// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include <memory>

#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
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
		std::cout << "Test::~Test(" << data << ")" << std::endl;
	}
};


int main() {
	{			
		Test* t1 = new Test{ 1000 };
		std::unique_ptr<Test> t2 { new Test{ 1000 } };

		/*
			- notice how the only one destructor is called when we exit the local space
			- the destructor was only called for the unique_ptr, t2.
			- The ptr name t1 was declared in this scope so it would not be available outside the scope, which means
			  that we are leaking memory because we have a manual storage allocation with no way in releasing the storage space 
			  after we exit this scope:
		*/
		// delete t1;
	}
	
	std::unique_ptr<Test> t1{ new Test{100} };
	std::unique_ptr<Test> t2 = std::make_unique<Test>(1000);

	std::unique_ptr<Test> t3;
	// t3 = t1 // Not allowed to assign a unique_ptr because you cannot copy, but you can move it
	t3 = std::move(t1);
	
	if (!t1)
		std::cout << "t1 is nullptr" << std::endl;

	std::cout << "\n=======================================================\n" << std::endl;

	std::unique_ptr<Account> a1 = std::make_unique<Checking_Account>("Moe", 5000);
	std::cout << *a1 << std::endl;
	
	a1->deposit(5000);
	std::cout << *a1 << std::endl;

	std::cout << "\n=======================================================\n" << std::endl;

	std::vector<std::unique_ptr<Account>> accounts;

	accounts.push_back(std::make_unique<Checking_Account>("James", 1000));
	accounts.push_back(std::make_unique<Savings_Account>("Billy", 4000, 5.2));
	accounts.push_back(std::make_unique<Trust_Account>("Bobby", 5000, 4.5));

	for (auto &account : accounts)
		std::cout << *account << std::endl;
	


	return 0;
}


// Section 17
// Shared Pointers
#include <iostream>
#include <memory>
#include <vector>
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "IllegalBalanceException.h"


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
	std::vector<std::shared_ptr<Account>> accounts;
	std::shared_ptr<Account> acct1 = std::make_shared<Trust_Account>("Larry", 10000, 3.1);
	std::shared_ptr<Account> acct3 = std::make_shared<Checking_Account>("Curly", 6000);
	accounts.push_back(acct1);
	accounts.push_back(acct3);

	try {
		std::shared_ptr<Account> acct2 = std::make_shared<Savings_Account>("Moe", -1, 1.5);
		accounts.push_back(acct2);
	}
	catch (IllegalBalanceException &ex) {
		std::cerr << ex.what() << std::endl;
	}

	for (const auto acc : accounts) {
		std::cout << *acc << std::endl;
		std::cout << "Used Count: "  <<acc.use_count() << std::endl;
	}

	for (const auto &acc : accounts) {
		std::cout << *acc << std::endl;
		std::cout << "Used Count: " << acc.use_count() << std::endl;
	}
	
    return 0;
}


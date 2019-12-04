#include <iostream>
#include <memory>
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "IllegalBalanceException.h"
#include "InsufficentFundsException.h"

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

	try {
		acct3->withdraw(10000);
	}
	catch (InsufficentFundsException &ex) {
		std::cerr << ex.what() << std::endl;
	}

    std::cout << "Program completed successfully" << std::endl;
    return 0;
}


#include <iostream>
#include <vector>

class Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "In Account::withdraw" << std::endl;
	}
	virtual ~Account() {
		std::cout << "Account::destructor" << std::endl;
	}
};

class Checking : public Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "In Checking::withdraw" << std::endl;
	}
	virtual ~Checking() {
		std::cout << "Checking::destructor" << std::endl;
	}
};

class Savings : public Account {
public:
	int num = 1;
	virtual void withdraw(double amount) {
		std::cout << "In Savings::withdraw" << std::endl;
	}
	virtual ~Savings() {
		std::cout << "Savings::destructor" << std::endl;
	}
};

class Trust : public Savings {
public:
	virtual void withdraw(double amount) {
		std::cout << "In Trust::withdraw" << std::endl;
	}
	virtual ~Trust() {
		std::cout << "Trust::destructor" << std::endl;
	};;
};

int main() {
	std::cout << "\n ==== Pointers ====" << std::endl;
	Account* p1 = new Account();
	Account* p2 = new Checking();
	Account* p3 = new Savings();
	Account* p4 = new Trust();

	/*
		- Notice how this behaves differently than the example in BaseClassPointer project.
		  So instead of the being statically bounded to the Base Class data/function.
		- This is an example of Dynamic Bindings, which was done via the virtual qualifer
		- Even though the pointer is dynamically binded, you still would not be able to access members
		  unique to the Derived Class, because the pointer is a Base Class pointer.
	*/
	p1->withdraw(1000);
	p2->withdraw(1000);
	p3->withdraw(1000);
	p4->withdraw(1000);

	std::cout << "\n ==== Arrays ====" << std::endl;
	Account* array[] = { p1, p2, p3, p4 };
	for (auto i = 0; i < 4; ++i)
		array[i]->withdraw(1000);

	std::cout << "\n ==== Arrays ====" << std::endl;
	array[0] = p4;
	for (auto i = 0; i < 4; ++i)
		array[i]->withdraw(1000);

	std::cout << "\n ==== Vector ====" << std::endl;
	std::vector<Account*> accounts{ p1, p2, p3, p4 };
	for (auto const account : accounts)
		account->withdraw(1000);

	std::cout << "\n ==== Vector ====" << std::endl;
	accounts.push_back(p4);
	accounts.push_back(p4);
	for (auto const account : accounts)
		account->withdraw(1000);

	std::cout << "\n ==== Clean Up ====" << std::endl;
	/*
		- Notice the differnce in behavior of the destructor, when qualifying each class's destructor as virtual
		- Rule of thumb is that if you intend for the Base Class and the Derived Classes to be polymorphic objects, 
		  then you should always declare a virtual destructor. 
		- By using a virtual destructor for polymorphic object, allows us to default back to how 
		  non-polymorphic inherited objects are destroyed
	*/
	delete p1;
	delete p2;
	delete p3;
	delete p4;

	return 0;
}
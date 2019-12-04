#include <iostream>

using std::cout;
using std::endl;

class Account {
	friend std::ostream& operator<<(std::ostream& os, const Account& account);
public:
	virtual void withdraw(double amount) {
		cout << "Account::withdraw" << endl;
	}

	virtual ~Account() {
		cout << "Account::~Account()" << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Account& account) {
	os << "Account Display";
	return os;
}

class Checking : public Account {
	friend std::ostream& operator<<(std::ostream& os, const Checking& account);
public:
	virtual void withdraw(double amount) override {
		cout << "Checking::withdraw" << endl;
	}

	virtual ~Checking() override {
		cout << "Checking::~Checking()" << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Checking& account) {
	os << "Checking Display";
	return os;
}

class Savings : public Account {
	friend std::ostream& operator<<(std::ostream& os, const Savings& account);
public:
	virtual void withdraw(double amount) override {
		cout << "Savings::withdraw" << endl;
	}

	virtual ~Savings() override {
		cout << "Savings::~Savings()" << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Savings& account) {
	os << "Savings Display";
	return os;
}
class Trust : public Savings {
	friend std::ostream& operator<<(std::ostream& os, const Trust& account);
public:
	virtual void withdraw(double amount) override {
		cout << "Trust::withdraw" << endl;
	}

	virtual ~Trust() override {
		cout << "Trust::~Trust()" << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Trust& account) {
	os << "Trust Display";
	return os;
}

int main() {
	Account account{};
	cout << account << endl;

	Checking checking{};
	cout << checking << endl;

	Savings savings{};
	cout << savings << endl;

	Trust trust{};
	cout << trust << endl;

	cout << "\n =================================== \n" << endl;

	Account* acct_ptr = new Account();
	cout << *acct_ptr << endl;
	
	Checking* chk_ptr = new Checking();
	cout << *chk_ptr << endl;

	Savings* sav_ptr = new Savings();
	cout << *sav_ptr << endl;

	Trust* trust_ptr = new Trust();
	cout << *trust_ptr << endl;

	cout << "\n =================================== \n" << endl;
	return 0;
}
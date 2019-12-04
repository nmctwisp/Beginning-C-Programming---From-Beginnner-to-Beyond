#include <iostream>

using std::cout;
using std::endl;

class I_Printable {
	friend std::ostream& operator<<(std::ostream& os, const I_Printable& obj);
public:
	virtual void print(std::ostream& os) const = 0;
	virtual ~I_Printable() {};
};

std::ostream& operator<<(std::ostream &os, const I_Printable& obj) {
	obj.print(os);
	return os;
}

class Account : public I_Printable {
public:
	virtual void print(std::ostream& os) const override {
		os << "Account Display";
	}

	virtual void withdraw(double amount) {
		cout << "Account::withdraw" << endl;
	}

	virtual ~Account() override {
		cout << "Account::~Account()" << endl;
	}
};

class Checking : public Account {
public:
	virtual void print(std::ostream& os) const override {
		os << "Checking Display";
	}

	virtual void withdraw(double amount) override {
		cout << "Checking::withdraw" << endl;
	}

	virtual ~Checking() override {
		cout << "Checking::~Checking()" << endl;
	}
};

class Savings : public Account {
public:
	virtual void print(std::ostream& os) const override {
		os << "Savings Display";
	}

	virtual void withdraw(double amount) override {
		cout << "Savings::withdraw" << endl;
	}

	virtual ~Savings() override {
		cout << "Savings::~Savings()" << endl;
	}
};

class Trust : public Savings {
public:
	virtual void print(std::ostream& os) const override {
		os << "Trust Display";
	}

	virtual void withdraw(double amount) override {
		cout << "Trust::withdraw" << endl;
	}

	virtual ~Trust() override {
		cout << "Trust::~Trust()" << endl;
	}
};

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
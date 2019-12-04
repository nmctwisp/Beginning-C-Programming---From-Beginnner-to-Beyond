#include <iostream>

using namespace std;

class Base {
private:
	int value;
public:
	Base() :
		value{ 0 } {
		cout << "Base No-Args Constructor" << endl;
	}
	Base(int x) :
		value{ x } {
		cout << "Base int Overloaded Constructor" << endl;
	}
	~Base() {
		cout << "Base Destructor" << endl;
	}
};

class Derived : public Base {
private:
	int double_value;
public:
	Derived() :
		Base{},
		double_value{ 0 } {
		cout << "Derived No-Args Constructor" << endl;
	}
	Derived(int x) :
		Base{ x },
		double_value{ x * 2 } {
		cout << "Derived int Overloaded Constructor" << endl;
	}
	~Derived() {
		cout << "Derived Destructor" << endl;
	}
};

int main() {

	Base a;
	Base b{ 100 };

	Derived c;
	Derived d{ 100 };
	return 0;

}
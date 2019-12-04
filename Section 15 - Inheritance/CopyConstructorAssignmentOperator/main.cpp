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
	Base(const Base& other) :
		value{ other.value } {
		cout << "Base Copy Constructor" << endl;
	}
	Base &operator=(const Base& other) {
		cout << "Base Copy Assignment" << endl;
		if (this == &other) {
			return *this;
		}
		
		this->value = other.value;
		return *this;
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
	Derived(const Derived& other) :
		Base{other},
		double_value{other.double_value} {
		cout << "Derived Copy Constructor" << endl;
	}
	Derived operator=(const Derived& other) {
		cout << "Derived Copy Assignment" << endl;
		if (this == &other) {
			return *this;
		}
		
		Base::operator=(other);
		this->double_value = other.double_value;

		return *this;
	}
	~Derived() {
		cout << "Derived Destructor" << endl;
	}
};

int main() {

	Base b {100};   // Overloaded constructor
	Base b1 {b};    // Copy constructor
	b = b1;          //   Copy assignment

	Derived d{ 100 };    // Overloaded constructor
	Derived d1{ d };     // Copy constructor
	d = d1;                // Copy assignment

	return 0;

}
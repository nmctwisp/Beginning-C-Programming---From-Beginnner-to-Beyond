#include <iostream>

using namespace std;

class Base {
	//Note friends of the Base Class have access to all
public:
	int a{ 0 };
	void display() { // member methods has access to all
		cout << a << ", " << b << ", " << c << endl; 
	}
protected:
	int b{ 0 };
private:
	int c{ 0 };
};

class Derived : public Base {
	// Note friends of Derived have access to only what Derived has access to

	// a will be public
	// b will be protected
	// will have no access to c

public:
	void access_base_members() {
		a = 200;
		b = 300;
		// c = 300; // not accessible
	}
};

int main() {
	cout << "=== Base member access from base objects ===============" << endl;
	Base base;
	base.a = 100; // OK
	// base.b = 200; // Compiler Error
	// base.c = 300; // Compiler Error

	cout << "=== Base member access from derived objects ============" << endl;
	Derived derived;
	derived.a = 100; // OK
	// derived.b = 200; // Compiler Error
	// derived.c = 300; // Compiler Error
	derived.access_base_members();
	
	return 0;
}
#include <iostream>

using namespace std;

class Base {
public:
	virtual void say_hello() const {
		cout << "Hello - I am a Base Class object" << endl;
	}

	virtual ~Base() {
		cout << "Base Class Destructor" << endl;
	}
};

class Derived : public Base {
public:
	virtual void say_hello() const override final {
		cout << "Hello - I am a Derived Class object" << endl;
	}

	virtual ~Derived() {
		cout << "Derived Class Destructor" << endl;
	}
};

class Another : public Derived {
public:
	virtual void say_hello() {
		// Error cannot override final menthod
		cout << "Hello - I am a Another Class object" << endl;
	}

	virtual ~Another() {
		cout << "Another Class Destructor" << endl;
	}
};

void greetings(const Base& obj) {
	cout << "Greetings: ";
	obj.say_hello();
};

int main() {

	Base b;
	b.say_hello();

	Derived d;
	d.say_hello();
	
	Another a;
	a.say_hello();
	
	Base* p1 = new Base();
	p1->say_hello();

	Derived* p2 = new Derived();
	p2->say_hello();

	Another* p3 = new Another();
	p3->say_hello();

	Base* p4 = new Derived();
	p4->say_hello();

	Derived* p5 = new Another();
	p5->say_hello();

	Base* p6 = new Another();
	p6->say_hello();

	cout << "\n =================================" << endl;


	greetings(b);
	greetings(d);
	greetings(a);
	greetings(*p1);
	greetings(*p2);
	greetings(*p3);
	greetings(*p4);
	greetings(*p5);
	greetings(*p6);

	return 0;
}
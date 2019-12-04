#include <iostream>

class Base {
public:
	virtual void say_hello() const {
		std::cout << "Hello - I'm a Base Class object" << std::endl;
	}
	virtual ~Base() {}
};

class Derived1: public Base {
public:
	virtual void say_hello() { 
		/*
			- notice how the const specifier is not used
			- Since the Derived::say_hello signature does NOT EXACTLY match the of the Base::say_hello signature,
			  then Derived::say_hello is NOT OVERRIDING Base::say_hello. This is instead, REDEFINITION of Base::say_hello
			- This means that the Derived::say_hello is not dynamically bound, but instead remains as statically bound.
		*/
		std::cout << "Hello - I'm a Derived1 Class object" << std::endl;
	}
	virtual ~Derived1() {};
};

class Derived2 : public Base {
public:
	virtual void say_hello() const {
		std::cout << "Hello - I'm a Derived2 Class object" << std::endl;
	}
	virtual ~Derived2() {};
};

class Derived3: public Base {
public:
	virtual void say_hello() const override {
		std::cout << "Hello - I'm a Derived3 Class object" << std::endl;
	}
	virtual ~Derived3() {}
};

int main() {
	Base* ptr1 = new Base();
	ptr1->say_hello();

	Derived1* ptr2 = new Derived1();
	ptr2->say_hello();

	Derived2* ptr3 = new Derived2();
	ptr3->say_hello();

	Derived3* ptr4 = new Derived3();
	ptr4->say_hello();

	Base* ptr5 = new Derived1();
	ptr5->say_hello();

	Base* ptr6 = new Derived2();
	ptr6->say_hello();

	Base* ptr7 = new Derived3();
	ptr7->say_hello();

	delete ptr1;
	delete ptr2;
	delete ptr3;
	delete ptr4;
	delete ptr5;
	delete ptr6;
	delete ptr7;

	return 0;
}
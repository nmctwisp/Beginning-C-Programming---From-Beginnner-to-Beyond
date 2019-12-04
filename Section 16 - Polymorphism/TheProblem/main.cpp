#include <iostream>
#include <memory>

class Base {
public:
	void say_hello() const {
		std::cout << "Hello - I am a Base Class object" << std::endl;
	}
};

class Derived: public Base {
public:
	void say_hello() const {
		std::cout << "Hello - I am a Derived class object" << std::endl;
	}
};

void greetings(const Base& obj) {
	std::cout << "Greetings: ";
	obj.say_hello();
}

int main() {
	
	Base base{};
	base.say_hello();

	Derived derived{};
	derived.say_hello();

	Base* base_ptr = new Base();
	base_ptr->say_hello();

	Derived* derived_ptr = new Derived();
	derived_ptr->say_hello();

	/* 
		Example of Static Binding
		#########################
		- Base* ptr = new Derived(), is legal because Derived is a Base. 
		- Since we're assigning a new Derived class object to a Base Class pointer, 
		  any data/function members will be called using the data/function members from the Base Class,
		  not the derived class. This is an example of static binding.
		- This is important, because if a Derived Class object is used as an argument for a functions 
		  that expects a Base Class reference or pointer, the Base Class, instead of the Derived Class, 
		  members are used 
		- The initalized Base Class pointers are statically binded to the Base Class, so if there are any members unique 
		  to the Derived Class, you would not be able to access the member.
	*/
	Base* ptr = new Derived(); 
	ptr->say_hello();

	greetings(base);
	greetings(derived);

	std::unique_ptr<Base> smt_ptr = std::make_unique<Derived>();
	smt_ptr->say_hello();

	delete base_ptr;
	delete derived_ptr;
	delete ptr;

	return 0;
}
#include <iostream>
#include <memory>

class B; // forward declaration ??

class A {
	std::shared_ptr<B> b_ptr;
public:
	A() {
		std::cout << "A::A()" << std::endl;
	}
	~A() {
		std::cout << "A::~A()" << std::endl;
	}
	void set_B(std::shared_ptr<B> &b) {
		b_ptr = b;
	}
};

class B {
	// make weak to break the strong circular reference/relationship
	std::shared_ptr<A> a_ptr;
public:
	B() {
		std::cout << "B::B()" << std::endl;
	}
	~B() {
		std::cout << "B::~B()" << std::endl;
	}

	void set_A(std::shared_ptr<A> &a) {
		a_ptr = a;
	}
};
class C; // forward declaration ??

class D {
	std::shared_ptr<C> c_ptr;
public:
	D() {
		std::cout << "D::D()" << std::endl;
	}
	~D() {
		std::cout << "D::~D()" << std::endl;
	}
	void set_C(std::shared_ptr<C> &c) {
		c_ptr = c;
	}
};

class C {
	// make weak to break the strong circular reference/relationship
	std::weak_ptr<D> d_ptr;
public:
	C() {
		std::cout << "C::C()" << std::endl;
	}
	~C() {
		std::cout << "C::~C()" << std::endl;
	}

	void set_D(std::shared_ptr<D> &d) {
		d_ptr = d;
	}
};
int main() {

	{
		std::shared_ptr<A> a = std::make_shared<A>();
		std::shared_ptr<B> b = std::make_shared<B>();

		a->set_B(b);
		b->set_A(a);
		b.reset();
		a.reset();
		// notice how no destructors were called
		// the circular reference prevents this from happening
	}

	{
		std::shared_ptr<D> d = std::make_shared<D>();
		std::shared_ptr<C> c = std::make_shared<C>();
		/*
			- notice how destructors were called
			- if the container holding the weak_ptr is reset the destructor is not immediately called
			- if the container holding the strong_ptr is reset then the destructor is called immediately
			- if the container holding the weak_ptr is reset first then the container holding when the strong_ptr
			  is destroyed the destructor for the weak_ptr is called as well
			- if the container holding the strong_ptr is reset first, then it breaks the circular relationship
			  and the destruction for the container holding the weak_ptr is handled like normal.
		*/

		d->set_C(c);
		c->set_D(d);
		c.reset(); 
		d.reset();



	}
	return 0;
}
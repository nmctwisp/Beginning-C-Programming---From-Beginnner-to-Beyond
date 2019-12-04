#include <iostream>
#include <memory>

class Test {
private:
	int data;
public:
	Test()
		: data{ 0 } {
		std::cout << "Test::Test()" << std::endl;
	}
	Test(int num)
		: data { num } {
		std::cout << "Test::Test(" << num << ")" << std::endl;
	}
	~Test() {
		std::cout << "Test::~Test()" << std::endl;
	}
};

void custom_deleter(Test *ptr) {
	std::cout << "custom_deleter(" << ptr << ")" << std::endl;
	delete ptr;
}

int main() {
	{
		// include the function name for initialization to use a custom deleter
		std::shared_ptr<Test> ptr1{ new Test{100}, custom_deleter };
	}

	std::cout << "====================================================" << std::endl;
	{
		// Using a Lambda Expression
		std::shared_ptr<Test> ptr2 { new Test{ 100 }, 
			[] (Test* ptr) {
				std::cout << "lambda_deleter(" << ptr << ")" << std::endl;
				delete ptr;
			}
		};
	}
}

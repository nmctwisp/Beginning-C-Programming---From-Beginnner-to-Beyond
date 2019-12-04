#include <iostream>

// Macros - Noticed how each variable is enclosed in parenthesis
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {

	std::cout << min(2, 3) << std::endl;
	std::cout << min("A", "B") << std::endl;
	std::cout << min(12.5, 9.2) << std::endl;
	std::cout << min(5+2*2, 7+40) << std::endl;
	
	std::cout << max(10, 20) << std::endl;

	return 0;
}
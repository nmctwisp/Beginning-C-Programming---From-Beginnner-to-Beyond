#include "I_Printable.h"

std::ostream& operator<<(std::ostream& os, const I_Printable& account) {
	account.print(os);
	return os;
}

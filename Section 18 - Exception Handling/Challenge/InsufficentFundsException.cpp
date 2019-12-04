#include "InsufficentFundsException.h"

const char* InsufficentFundsException::what() const noexcept{
	return "Exception: Insufficent Funds!";
}
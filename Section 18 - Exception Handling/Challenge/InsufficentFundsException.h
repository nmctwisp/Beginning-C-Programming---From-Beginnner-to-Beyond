#pragma once
#include <exception>

class InsufficentFundsException : public std::exception {
public:
	InsufficentFundsException() noexcept = default;
	~InsufficentFundsException() = default;

	virtual const char* what() const noexcept;
};
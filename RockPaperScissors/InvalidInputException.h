#pragma once
#include <stdexcept>
class InvalidInputException : public std::invalid_argument
{
public:
	InvalidInputException() : std::invalid_argument("Invalid Input") {};
};

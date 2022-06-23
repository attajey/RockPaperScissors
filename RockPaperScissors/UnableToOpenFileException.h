#pragma once
#include <stdexcept>

class UnableToOpenFileException : public std::invalid_argument
{
public:
	UnableToOpenFileException() : std::invalid_argument("Unable To Open File") {};
};

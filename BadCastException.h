#pragma once
#include<exception>

class BadCastException : public std::exception
{
public:
    virtual const char* what() const throw() { return "Cannot cast type!"; }
};
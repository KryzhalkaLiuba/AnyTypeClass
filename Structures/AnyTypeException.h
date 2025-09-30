#pragma once
#include<exception>

class AnyTypeException : public std::bad_cast
{
public:
    AnyTypeException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override{ return message.c_str(); }
private:
    std::string message;
};
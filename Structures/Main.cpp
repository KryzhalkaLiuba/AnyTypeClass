#include "AnyType.h"
#include "AnyTypeException.h"
#include <typeinfo>
#include <iostream>

using namespace Any;

int main() {
    AnyType anyType = 1;
    anyType = true;
    anyType = 1.7;

    try
    {
        int storedValue = anyType.ToInt();
    }
    catch (const std::bad_cast& exception)
    {
        std::cout << exception.what() << std::endl;
    }

}
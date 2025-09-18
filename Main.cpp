#include "AnyType.h"

int main() {
    AnyType anyType = 1;
    anyType = true;
    anyType = 1.7;

    try
    {
        int storedValue = anyType.ToInt();
    }
    catch (BadCastException& exception)
    {
        //Bad cast exception
    }

    double storedValue = anyType.ToDouble();

}
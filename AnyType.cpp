#pragma once

#include "AnyType.h"
#include "BadCastException.h"

#include<ostream>
#include<exception>


    AnyType::AnyType(): data_type(TypeId::Undefined), data{} {
    }

    AnyType::AnyType(bool bool_var) {
        data_type = TypeId::Bool;
        data.bool_var = bool_var;
    }

    AnyType::AnyType(unsigned char unsigned_char_var) {
        data_type = TypeId::UnsignedChar;
        data.unsigned_char_var= unsigned_char_var;
    }

    AnyType::AnyType(signed char signed_char_var) {
        data_type = TypeId::SignedChar;
        data.signed_char_var = signed_char_var;
    }

    AnyType::AnyType(wchar_t wchar_t_var) {
        data_type = TypeId::WcharT;
        data.wchar_t_var = wchar_t_var;
    }

    AnyType::AnyType(short int short_int_var) {
        data_type = TypeId::ShortInt;
        data.short_int_var = short_int_var;
    }

    AnyType::AnyType(unsigned short int unsigned_short_int_var) {
        data_type = TypeId::UnsignedShortInt;
        data.unsigned_short_int_var = unsigned_short_int_var;
    }

    AnyType::AnyType(int int_var) {
        data_type = TypeId::Int;
        data.int_var = int_var;
    }

    AnyType::AnyType(unsigned int unsigned_int_var) {
        data_type = TypeId::UnsignedInt;
        data.unsigned_int_var = unsigned_int_var;
    }

    AnyType::AnyType(long int long_int_var) {
        data_type = TypeId::LongInt;
        data.long_int_var = long_int_var;
    }
    AnyType::AnyType(unsigned long int unsigned_long_int_var) {
        data_type = TypeId::UnsignedLongInt;
        data.unsigned_long_int_var = unsigned_long_int_var;
    }

    AnyType::AnyType(long long int long_long_int_var) {
        data_type = TypeId::LongLongInt;
        data.long_long_int_var = long_long_int_var;
    }

    AnyType::AnyType(unsigned long long int unsigned_long_long_int_var) {
        data_type = TypeId::UnsignedLongLongInt;
        data.unsigned_long_long_int_var = unsigned_long_long_int_var;
    }

    AnyType::AnyType(float float_var) {
        data_type = TypeId::Float;
        data.float_var = float_var;
    }

    AnyType::AnyType(double double_var) {
        data_type = TypeId::Double;
        data.double_var = double_var;
    }

    AnyType::AnyType(long double long_double_var) {
        data_type = TypeId::LongDouble;
        data.long_double_var = long_double_var;
    }

    AnyType::AnyType(const AnyType& obj): data_type(obj.data_type), data(obj.data){
    }

    AnyType::AnyType(AnyType&& obj): data(std::move(obj.data)), data_type(std::move(obj.data_type)) {
        obj.data_type = TypeId::Undefined;
    }

    AnyType& AnyType::operator=(const AnyType& obj) {
        if (this != &obj) {
            data_type = obj.data_type;
            data = obj.data;
        }
        return *this;
    }

    AnyType& AnyType::operator=(AnyType&& obj) {
        if (this != &obj)
        {
            data = std::move(obj.data);
            data_type = std::move(obj.data_type);
            obj.data_type = TypeId::Undefined;
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const AnyType& obj);

    void AnyType::Reset(AnyType& obj) {
        obj.data_type = TypeId::Undefined;
    }

    void AnyType::Swap(AnyType& left, AnyType& right) {

        if (&left.data != &right.data)
        {
            AnyType temp = left;

            left.data = right.data;
            left.data_type = right.data_type;
            right.data = temp.data;
            right.data_type = temp.data_type;
        }
    }


    bool AnyType::ToBool() const {
        if (data_type == TypeId::Bool) {
            return data.bool_var;
        }
        throw BadCastException();
    }

    unsigned char AnyType::ToUnsignedChar() const {
        if (data_type == TypeId::UnsignedChar) {
            return data.unsigned_char_var;
        }
        throw BadCastException();
    }

    signed char AnyType::ToSignedChar() const {
        if (data_type == TypeId::SignedChar) {
            return data.signed_char_var;
        }
        throw BadCastException();
    }

    wchar_t AnyType::ToWchar_t() const {
        if (data_type == TypeId::WcharT) {
            return data.wchar_t_var;
        }
        throw BadCastException();
    }

    short int AnyType::ToShortInt() const {
        if (data_type == TypeId::ShortInt) {
            return data.short_int_var;
        }
        throw BadCastException();
    }

    unsigned short int AnyType::ToUnsignedShortInt() const {
        if (data_type == TypeId::UnsignedShortInt) {
            return data.unsigned_short_int_var;
        }
        throw BadCastException();
    }

    int AnyType::ToInt() const {
        if (data_type == TypeId::Int) {
            return data.int_var;
        }
        throw BadCastException();
    }

    unsigned int AnyType::ToUnsignedInt() const {
        if (data_type == TypeId::UnsignedInt) {
            return data.unsigned_int_var;
        }
        throw BadCastException();
    }

    long int AnyType::ToLongInt() const {
        if (data_type == TypeId::LongInt) {
            return data.long_int_var;
        }
        throw BadCastException();
    }    
    
    long long int AnyType::ToLongLongInt() const {
        if (data_type == TypeId::LongLongInt) {
            return data.long_long_int_var;
        }
        throw BadCastException();
    }

    unsigned long int AnyType::ToUnsignedLongInt() const {
        if (data_type == TypeId::UnsignedLongInt) {
            return data.unsigned_long_int_var;
        }
        throw BadCastException();
    }

    unsigned long long int AnyType::ToUnsignedLongLongInt() const {
    
        if (data_type == TypeId::UnsignedLongLongInt) {
            return data.unsigned_long_long_int_var;
        }
        throw BadCastException();
    }


    float AnyType::ToFloat() const {
        if (data_type == TypeId::Float) {
            return data.float_var;
        }
        throw BadCastException();
    }
    double AnyType::ToDouble() const {
        if (data_type == TypeId::Double) {
            return data.double_var;
        }
        throw BadCastException();
    }

    long double AnyType::ToLongDouble() const {
        if (data_type == TypeId::LongDouble) {
            return data.long_double_var;
        }
        throw BadCastException();
    }

    TypeId AnyType::getType() const { return data_type; }

    const char* AnyType::getTypeName() {

        switch (getType()) {
        case TypeId::Undefined:
            return "type is undefined";
            break;
        case TypeId::Bool:
            return "bool";
            break;
        case TypeId::UnsignedChar:
            return "unsigned char";
            break;
        case TypeId::SignedChar:
            return "signed char";
            break;
        case TypeId::WcharT:
            return "wchar_t";
            break;
        case TypeId::ShortInt:
            return "short int";
            break;
        case TypeId::UnsignedShortInt:
            return "unsigned short int";
            break;
        case TypeId::Int:
            return "int";
            break;
        case TypeId::UnsignedInt:
            return "unsigned int";
            break;
        case TypeId::LongInt:
            return "long int";
            break;
        case TypeId::UnsignedLongInt:
            return "unsigned long int";
            break;
        case TypeId::LongLongInt:
            return "long long int";
            break;
        case TypeId::UnsignedLongLongInt:
            return "unsigned long long int";
            break;
        case TypeId::Float:
            return "float";
            break;
        case TypeId::Double:
            return "double";
            break;
        case TypeId::LongDouble:
            return "long double";
            break;
        default:
            return "Something is wrong";
        }
    }

//}
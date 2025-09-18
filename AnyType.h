#pragma once

#include<ostream>
#include<exception>


//namespace AnyType
//{

    enum class TypeId
    {
        Undefined = -1,
        Bool = 0,
        UnsignedChar = 1,
        SignedChar = 2,
        WcharT = 3,
        ShortInt = 4,
        UnsignedShortInt = 5,
        Int = 6,
        UnsignedInt = 7,
        LongInt = 8,
        LongLongInt = 9,
        UnsignedLongInt = 10,
        UnsignedLongLongInt = 11,
        Float = 12,
        Double = 13,
        LongDouble = 14
    };

    template <typename T>
    TypeId TypeInfo()
    {
        if (std::is_same<T, bool>::value)
            return TypeId::Bool;
        if (std::is_same<T, char>::value)
            return TypeId::SignedChar;
        if (std::is_same<T, unsigned char>::value)
            return TypeId::UnsignedChar;
        if (std::is_same<T, wchar_t>::value)
            return TypeId::WcharT;
        if (std::is_same<T, int>::value)
            return TypeId::Int;
        if (std::is_same<T, unsigned int>::value)
            return TypeId::UnsignedInt;
        if (std::is_same<T, short int>::value)
            return TypeId::ShortInt;
        if (std::is_same<T, unsigned short int>::value)
            return TypeId::UnsignedShortInt;
        if (std::is_same<T, long int>::value)
            return TypeId::LongInt;
        if (std::is_same<T, unsigned long int>::value)
            return TypeId::UnsignedLongInt;
        if (std::is_same<T, long long int>::value)
            return TypeId::LongLongInt;
        if (std::is_same<T, unsigned long long int>::value)
            return TypeId::UnsignedLongLongInt;
        if (std::is_same<T, float>::value)
            return TypeId::Float;
        if (std::is_same<T, double>::value)
            return TypeId::Double;
        if (std::is_same<T, long double>::value)
            return TypeId::LongDouble;

        return TypeId::Undefined;
    }



    
    class AnyType
    {
    private:
        union Type
        {
            bool bool_var;
            unsigned char unsigned_char_var;
            signed char signed_char_var;
            wchar_t wchar_t_var;
            short int short_int_var;
            unsigned short int unsigned_short_int_var;
            int int_var;
            unsigned int unsigned_int_var;
            long int long_int_var;
            long long int long_long_int_var;
            unsigned long int unsigned_long_int_var;
            unsigned long long int unsigned_long_long_int_var;
            float float_var;
            double double_var;
            long double long_double_var;
        };

        Type data;
        TypeId data_type;

    public:
        AnyType();

        AnyType(bool bool_var);
        AnyType(unsigned char unsigned_char_var);
        AnyType(signed char signed_char_var);
        AnyType(wchar_t wchar_t_var);
        AnyType(short int short_int_var);
        AnyType(unsigned short int unsigned_short_int_var);
        AnyType(int int_var);
        AnyType(unsigned int unsigned_int_var);
        AnyType(long int long_int_var);
        AnyType(unsigned long int unsigned_long_int_var);
        AnyType(long long int long_long_int_var);
        AnyType(unsigned long long int unsigned_long_long_int_var);
        AnyType(float float_var);
        AnyType(double double_var);
        AnyType(long double long_double_var);

        AnyType(const AnyType& obj);
        AnyType(AnyType&& obj);

        ~AnyType() = default;

        AnyType& operator=(const AnyType& obj);
        AnyType& operator=(AnyType&& obj);

        friend std::ostream& operator<<(std::ostream& os, const AnyType& obj);

        static void Reset(AnyType& obj);
        static void Swap(AnyType& left, AnyType& right);


        bool ToBool() const;
        unsigned char ToUnsignedChar() const;
        signed char ToSignedChar() const;
        wchar_t ToWchar_t() const;
        short int ToShortInt() const;
        unsigned short int ToUnsignedShortInt() const;
        int ToInt() const;
        unsigned int ToUnsignedInt() const;
        long int ToLongInt() const;
        long long int ToLongLongInt() const;
        unsigned long int ToUnsignedLongInt() const;
        unsigned long long int ToUnsignedLongLongInt() const;
        float ToFloat() const;
        double ToDouble() const;
        long double ToLongDouble() const;

        TypeId getType() const { return data_type; }

        const char* getTypeName();
    };

//}
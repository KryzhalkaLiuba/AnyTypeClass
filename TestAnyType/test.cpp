#include "pch.h"
#include "../Structures/AnyType.h"
#include "../Structures/AnyTypeException.h"

using namespace Any;

TEST(TestAnyType, Constructor) {
    AnyType obj;
    ASSERT_EQ(obj.getType(), TypeId::Undefined);
}
TEST(TestAnyType, ConstructorWithParameters) {
    AnyType obj(true);
    ASSERT_EQ(obj.getType(), TypeId::Bool);
    ASSERT_TRUE(obj.ToBool());
}

TEST(TestAnyType, CopyConstructor) {
    AnyType obj(true);

    AnyType obj2 = obj;

    ASSERT_EQ(obj.getType(), obj2.getType());
    ASSERT_EQ(obj.ToBool(), obj2.ToBool());
}

TEST(TestAnyType, MoveConstructor) {
    AnyType obj(3);
    AnyType obj2 = std::move(obj);
    ASSERT_EQ(obj.getType(), TypeId::Undefined);
    ASSERT_EQ(3, obj2.ToInt());
    ASSERT_EQ(obj2.getType(), TypeId::Int);
}

TEST(TestAnyType, AssignmentOperator) {
    AnyType obj1 = true;
    AnyType obj2 = 'b';

    obj1 = obj2;
    ASSERT_EQ(obj1.getType(), obj2.getType());
    ASSERT_EQ(obj1.ToChar(), obj2.ToChar());
}

TEST(TestAnyType, MoveOperator) {
    AnyType a2 = 5.5;
    AnyType a3 = 'b';
    a3 = std::move(a2);

    EXPECT_EQ(a3.getType(), TypeId::Double);
    EXPECT_EQ(a3.ToDouble(), 5.5);
}

TEST(TestAnyType, Reset) {

    AnyType ch('c');
    EXPECT_EQ(ch.getType(), TypeId::Char);
    EXPECT_EQ(ch.ToChar(), 'c');

    AnyType::Reset(ch);
    ASSERT_EQ(TypeId::Undefined, ch.getType());
}

TEST(TestAnyType, BadCast) {
    AnyType a1 = 3.14;
    ASSERT_THROW(a1.ToInt(), AnyTypeException);
}

TEST(TestAnyType, Swap) {
    AnyType a('a');
    AnyType b(5);

    AnyType::Swap(a, a);

    AnyType::Swap(a, b);

    ASSERT_EQ(5, a.ToInt());
    ASSERT_EQ(TypeId::Int, a.getType());

    ASSERT_EQ('a', b.ToChar());
    ASSERT_EQ(TypeId::Char, b.getType());
}

TEST(TestAnyType, GetTypeName) {
    AnyType a1 = 1.5f;
    EXPECT_STREQ(a1.getTypeName(), "float");

    AnyType a2;
    EXPECT_STREQ(a2.getTypeName(), "type is undefined");
}
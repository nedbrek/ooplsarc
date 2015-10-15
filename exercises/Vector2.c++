// -----------
// Vector2.c++
// -----------

// http://www.cplusplus.com/reference/vector/vector/

#include <vector> // vector

#include "gtest/gtest.h"

#include "Vector2.h"

using namespace std;

using testing::Test;
using testing::Types;

template <typename T>
struct Vector_Fixture : Test {
    typedef T vector_type;};

typedef Types<
               vector<int>,
            my_vector<int>>
        vector_types;

TYPED_TEST_CASE(Vector_Fixture, vector_types);

TYPED_TEST(Vector_Fixture, test_1) {
    typedef typename TestFixture::vector_type vector_type;

    vector_type x;
    ASSERT_EQ(x.size(), 0);}

TYPED_TEST(Vector_Fixture, test_2) {
    typedef typename TestFixture::vector_type vector_type;

    vector_type x(3);
    ASSERT_EQ(x.size(), 3);
    ASSERT_EQ(x.at(1), 0);
    x.at(1) = 2;
    ASSERT_EQ(x.at(1), 2);
    fill(x.begin(), x.end(), 4);
    ASSERT_EQ(x.at(1), 4);}

TYPED_TEST(Vector_Fixture, test_3) {
    typedef typename TestFixture::vector_type vector_type;

    const vector_type x(3, 2);
    ASSERT_EQ(x.at(1), 2);}

TYPED_TEST(Vector_Fixture, test_4) {
    typedef typename TestFixture::vector_type vector_type;

    const vector_type x(3, 4);
    const vector_type y(6, 4);
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));}

TYPED_TEST(Vector_Fixture, test_5) {
    typedef typename TestFixture::vector_type vector_type;

    const vector_type x(10, 2);
    const vector_type y(10, 2);
    ASSERT_TRUE(x == y);
    ASSERT_TRUE(x <= y);
    ASSERT_TRUE(x >= y);
    ASSERT_TRUE(!(x != y));
    ASSERT_TRUE(!(x <  y));
    ASSERT_TRUE(!(x >  y));}

// -----------
// Vector1.c++
// -----------

// http://www.cplusplus.com/reference/vector/vector/

#include <vector> // vector

#include "gtest/gtest.h"

#include "Vector1.h"

using namespace std;

using testing::Test;
using testing::Types;

template <typename T>
struct Vector_Fixture : Test {
    using vector_type = T;};

typedef Types<
               vector<int>,
            my_vector<int>>
        vector_types;

TYPED_TEST_CASE(Vector_Fixture, vector_types);

TYPED_TEST(Vector_Fixture, test_1) {
    using vector_type = typename TestFixture::vector_type;

    vector_type x;
    ASSERT_EQ(0, x.size());}

TYPED_TEST(Vector_Fixture, test_2) {
    using vector_type = typename TestFixture::vector_type;

    vector_type x(3);
    ASSERT_EQ(3, x.size());
    ASSERT_EQ(0, x[1]);
    x[1] = 2;
    ASSERT_EQ(2, x[1]);
    fill(x.begin(), x.end(), 4);
    ASSERT_EQ(4, x[1]);}

TYPED_TEST(Vector_Fixture, test_3) {
    using vector_type = typename TestFixture::vector_type;

    const vector_type x(3, 2);
    ASSERT_EQ(2, x[1]);}

TYPED_TEST(Vector_Fixture, test_4) {
    using vector_type = typename TestFixture::vector_type;

    const vector_type x(3, 4);
    const vector_type y(6, 4);
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));}

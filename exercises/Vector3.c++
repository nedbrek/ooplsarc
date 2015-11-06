// -----------
// Vector3.c++
// -----------

// http://www.cplusplus.com/reference/vector/vector/

#include <utility> // move
#include <vector>  // vector

#include "gtest/gtest.h"

#include "Vector3.h"

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

    const vector_type x(10, 2);
    const vector_type y = x;
    ASSERT_NE(x.begin(), y.begin());
    ASSERT_EQ(x, y);}

TYPED_TEST(Vector_Fixture, test_2) {
    using vector_type = typename TestFixture::vector_type;

          vector_type x(10, 2);
    const vector_type y = x;
    ASSERT_NE(x.begin(), y.begin());
    ASSERT_EQ(x, y);
    const vector_type z = move(x);
    ASSERT_NE(x, y);
    ASSERT_NE(x, z);
    ASSERT_EQ(x.begin(), x.end());
    ASSERT_EQ(y, z);}

TYPED_TEST(Vector_Fixture, test_3) {
    using vector_type = typename TestFixture::vector_type;

    const vector_type x(20, 3);
          vector_type y(10, 2);
    y = x;
    ASSERT_NE(x.begin(), y.begin());
    ASSERT_EQ(x, y);}

TYPED_TEST(Vector_Fixture, test_4) {
    using vector_type = typename TestFixture::vector_type;

    vector_type x(20, 3);
    vector_type y(10, 2);
    y = x;
    ASSERT_NE(x.begin(), y.begin());
    ASSERT_EQ(x, y);
    vector_type z(10, 2);
    z = move(x);
    ASSERT_NE(x, y);
    ASSERT_NE(x, z);
    ASSERT_EQ(x.begin(), x.end());
    ASSERT_EQ(y, z);}

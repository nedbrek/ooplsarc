// -----------
// Vector2.c++
// -----------

// http://www.cplusplus.com/reference/vector/vector/

#include <memory>    // allocator
#include <stdexcept> // out_of_range
#include <vector>    // vector

#include "gtest/gtest.h"

#include "Vector2.h"

using namespace std;

using testing::Test;
using testing::Types;

template <typename T>
struct Vector_Fixture : Test {
    using vector_type    = T;
    using allocator_type = typename vector_type::allocator_type;};

typedef Types<
               vector<int, allocator<int>>,
            my_vector<int, allocator<int>>>
        vector_types;

TYPED_TEST_CASE(Vector_Fixture, vector_types);

TYPED_TEST(Vector_Fixture, test_1) {
    using vector_type = typename TestFixture::vector_type;

    vector_type x;
    ASSERT_EQ(0, x.size());}

TYPED_TEST(Vector_Fixture, test_2) {
    typedef typename TestFixture::vector_type vector_type;

    vector_type x(3);
    ASSERT_EQ(3, x.size());
    ASSERT_EQ(0, x.at(1));
    x.at(1) = 2;
    ASSERT_EQ(2, x.at(1));
    fill(x.begin(), x.end(), 4);
    ASSERT_EQ(4, x.at(1));
    ASSERT_THROW(x.at(3), out_of_range);}

TYPED_TEST(Vector_Fixture, test_3) {
    using vector_type    = typename TestFixture::vector_type;
    using allocator_type = typename TestFixture::allocator_type;

    const vector_type x(3, 2, allocator_type());
    ASSERT_EQ(2, x.at(1));}

TYPED_TEST(Vector_Fixture, test_4) {
    using vector_type = typename TestFixture::vector_type;

    const vector_type x(3, 4);
    const vector_type y(6, 4);
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));}

TYPED_TEST(Vector_Fixture, test_5) {
    using vector_type = typename TestFixture::vector_type;

    const vector_type x(10, 2);
    const vector_type y(10, 2);
    ASSERT_TRUE(x == y);
    ASSERT_TRUE(!(x != y));
    ASSERT_TRUE(!(x <  y));
    ASSERT_TRUE(x <= y);
    ASSERT_TRUE(!(x >  y));
    ASSERT_TRUE(x >= y);}

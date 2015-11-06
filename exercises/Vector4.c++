// -----------
// Vector4.c++
// -----------

// http://www.cplusplus.com/reference/vector/vector/

#include <algorithm> // count
#include <stdexcept> // out_of_range
#include <vector>    // vector

#include "gtest/gtest.h"

#include "Vector4.h"

using namespace std;

using testing::Test;
using testing::Types;

template <typename T>
struct Vector_Fixture : Test {
    using vector_type = T;
    using value_type  = typename vector_type::value_type;};

typedef Types<
               vector<int>,
            my_vector<int>>
        vector_types;

TYPED_TEST_CASE(Vector_Fixture, vector_types);

TYPED_TEST(Vector_Fixture, test_1) {
    using vector_type = typename TestFixture::vector_type;

    const vector_type x;
    ASSERT_TRUE(x.empty());
    ASSERT_EQ(0, x.size());
    ASSERT_EQ(0, x.capacity());}

TYPED_TEST(Vector_Fixture, test_2) {
    using vector_type = typename TestFixture::vector_type;
    using value_type  = typename TestFixture::value_type;

    vector_type x(10);
    ASSERT_FALSE(x.empty());
    ASSERT_EQ(10, x.size());
    ASSERT_EQ(10, x.capacity());
    ASSERT_EQ(10, count(x.begin(), x.end(), value_type()));}

TYPED_TEST(Vector_Fixture, test_3) {
    using vector_type = typename TestFixture::vector_type;

    const vector_type x(10, 2);
    ASSERT_FALSE(x.empty());
    ASSERT_EQ(10, x.size());
    ASSERT_EQ(10, x.capacity());
    ASSERT_EQ(10, count(x.begin(), x.end(), 2));}

TYPED_TEST(Vector_Fixture, test_4) {
    using vector_type = typename TestFixture::vector_type;

    vector_type x(10);
    ASSERT_EQ(10, x.size());
    ASSERT_EQ(10, x.capacity());
    x.reserve(5);
    ASSERT_EQ(10, x.size());
    ASSERT_EQ(10, x.capacity());
    x.reserve(15);
    ASSERT_EQ(10, x.size());
    ASSERT_EQ(15, x.capacity());}

TYPED_TEST(Vector_Fixture, test_5) {
    using vector_type = typename TestFixture::vector_type;

    vector_type x(10);
    ASSERT_EQ(10, x.size());
    ASSERT_EQ(10, x.capacity());
    x.resize(5);
    ASSERT_EQ(5, x.size());
    ASSERT_EQ(10, x.capacity());
    x.resize(8);
    ASSERT_EQ(8, x.size());
    ASSERT_EQ(10, x.capacity());
    x.resize(15);
    ASSERT_EQ(15, x.size());
    #ifdef __APPLE__
    ASSERT_EQ(20, x.capacity());
    #else
    ASSERT_EQ(16, x.capacity());
    #endif
    x.resize(50);
    ASSERT_EQ(50, x.size());
    ASSERT_EQ(50, x.capacity());}

TYPED_TEST(Vector_Fixture, test_6) {
    using vector_type = typename TestFixture::vector_type;

    vector_type x(10);
    x[0] = 2;
    x[1] = 3;
    x[2] = 4;
    ASSERT_EQ(3, x[ 1]);
//  ASSERT_EQ(3, x[10]);
    try {
        ASSERT_EQ(3, x.at(10));
        ASSERT_TRUE(false);}
    catch (const out_of_range&)
        {}}

TYPED_TEST(Vector_Fixture, test_7) {
    using vector_type = typename TestFixture::vector_type;

    vector_type x;
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(2);
    x.push_back(3);
    ASSERT_EQ(5, x.size());
    ASSERT_EQ(8, x.capacity());
    x.pop_back();
    ASSERT_EQ(4, x.size());
    ASSERT_EQ(8, x.capacity());}

TYPED_TEST(Vector_Fixture, test_8) {
    using vector_type = typename TestFixture::vector_type;

    vector_type x;
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    ASSERT_EQ(3, x.size());
    ASSERT_EQ(4, x.capacity());
    const vector_type y(x);
    ASSERT_EQ(3, y.size());
    ASSERT_EQ(3, y.capacity());
    ASSERT_EQ(y, x);}

TYPED_TEST(Vector_Fixture, test_9) {
    using vector_type = typename TestFixture::vector_type;

    const vector_type x(10, 2);
    vector_type       y(20, 3);
    ASSERT_EQ(20, y.size());
    ASSERT_EQ(20, y.capacity());
    ASSERT_TRUE(x != y);
    y = x;
    ASSERT_EQ(10, y.size());
    ASSERT_EQ(20, y.capacity());
    ASSERT_EQ(y, x);}

TYPED_TEST(Vector_Fixture, test_10) {
    using vector_type = typename TestFixture::vector_type;

    const vector_type x(15, 2);
    vector_type       y(10, 3);
    ASSERT_EQ(10, y.size());
    ASSERT_EQ(10, y.capacity());
    y.push_back(3);
    ASSERT_EQ(11, y.size());
    ASSERT_EQ(20, y.capacity());
    ASSERT_TRUE(x != y);
    y = x;
    ASSERT_EQ(15, y.size());
    ASSERT_EQ(20, y.capacity());
    ASSERT_EQ(y, x);}

TYPED_TEST(Vector_Fixture, test_11) {
    using vector_type = typename TestFixture::vector_type;

    const vector_type x(20, 2);
    vector_type       y(10, 3);
    ASSERT_EQ(10, y.size());
    ASSERT_EQ(10, y.capacity());
    ASSERT_TRUE(x != y);
    y = x;
    ASSERT_EQ(20, y.size());
    ASSERT_EQ(20, y.capacity());
    ASSERT_EQ(y, x);}

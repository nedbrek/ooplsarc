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
    typedef T                                vector_type;
    typedef typename vector_type::value_type value_type;};

typedef Types<
               vector<int>,
            my_vector<int>>
        vector_types;

TYPED_TEST_CASE(Vector_Fixture, vector_types);

TYPED_TEST(Vector_Fixture, test_1) {
    typedef typename TestFixture::vector_type vector_type;

    const vector_type x;
    ASSERT_TRUE(x.empty());
    ASSERT_EQ(x.size(),     0);
    ASSERT_EQ(x.capacity(), 0);}

TYPED_TEST(Vector_Fixture, test_2) {
    typedef typename TestFixture::vector_type vector_type;
    typedef typename TestFixture::value_type  value_type;

    vector_type x(10);
    ASSERT_FALSE(x.empty());
    ASSERT_EQ(x.size(),                                10);
    ASSERT_EQ(x.capacity(),                            10);
    ASSERT_EQ(count(x.begin(), x.end(), value_type()), 10);}

TYPED_TEST(Vector_Fixture, test_3) {
    typedef typename TestFixture::vector_type vector_type;

    const vector_type x(10, 2);
    ASSERT_FALSE(x.empty());
    ASSERT_EQ(x.size(),                     10);
    ASSERT_EQ(x.capacity(),                 10);
    ASSERT_EQ(count(x.begin(), x.end(), 2), 10);}

TYPED_TEST(Vector_Fixture, test_4) {
    typedef typename TestFixture::vector_type vector_type;

    vector_type x(10);
    ASSERT_EQ(x.size(),     10);
    ASSERT_EQ(x.capacity(), 10);
    x.reserve(5);
    ASSERT_EQ(x.size(),     10);
    ASSERT_EQ(x.capacity(), 10);
    x.reserve(15);
    ASSERT_EQ(x.size(),     10);
    ASSERT_EQ(x.capacity(), 15);}

TYPED_TEST(Vector_Fixture, test_5) {
    typedef typename TestFixture::vector_type vector_type;

    vector_type x(10);
    ASSERT_EQ(x.size(),     10);
    ASSERT_EQ(x.capacity(), 10);
    x.resize(5);
    ASSERT_EQ(x.size(),      5);
    ASSERT_EQ(x.capacity(), 10);
    x.resize(8);
    ASSERT_EQ(x.size(),      8);
    ASSERT_EQ(x.capacity(), 10);
    x.resize(15);
    ASSERT_EQ(x.size(),     15);
    cout << x.capacity() << endl;
    ASSERT_GT(x.capacity(), 15);
    x.resize(50);
    ASSERT_EQ(x.size(),     50);
    ASSERT_EQ(x.capacity(), 50);}

TYPED_TEST(Vector_Fixture, test_6) {
    typedef typename TestFixture::vector_type vector_type;

    vector_type x(10);
    x[0] = 2;
    x[1] = 3;
    x[2] = 4;
    ASSERT_EQ(x[ 1], 3);
//  ASSERT_EQ(x[10], 3);
    try {
        ASSERT_EQ(x.at(10), 3);
        ASSERT_TRUE(false);}
    catch (const out_of_range&)
        {}}

TYPED_TEST(Vector_Fixture, test_7) {
    typedef typename TestFixture::vector_type vector_type;

    vector_type x;
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(2);
    x.push_back(3);
    ASSERT_EQ(x.size(),     5);
    ASSERT_EQ(x.capacity(), 8);
    x.pop_back();
    ASSERT_EQ(x.size(),     4);
    ASSERT_EQ(x.capacity(), 8);}

TYPED_TEST(Vector_Fixture, test_8) {
    typedef typename TestFixture::vector_type vector_type;

    vector_type x;
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    ASSERT_EQ(x.size(),     3);
    ASSERT_EQ(x.capacity(), 4);
    const vector_type y(x);
    ASSERT_EQ(y.size(),     3);
    ASSERT_EQ(y.capacity(), 3);
    ASSERT_EQ(x, y);}

TYPED_TEST(Vector_Fixture, test_9) {
    typedef typename TestFixture::vector_type vector_type;

    const vector_type x(10, 2);
    vector_type       y(20, 3);
    ASSERT_EQ(y.size(),     20);
    ASSERT_EQ(y.capacity(), 20);
    ASSERT_TRUE(x != y);
    y = x;
    ASSERT_EQ(y.size(),     10);
    ASSERT_EQ(y.capacity(), 20);
    ASSERT_EQ(x, y);}

TYPED_TEST(Vector_Fixture, test_10) {
    typedef typename TestFixture::vector_type vector_type;

    const vector_type x(15, 2);
    vector_type       y(10, 3);
    ASSERT_EQ(y.size(),     10);
    ASSERT_EQ(y.capacity(), 10);
    y.push_back(3);
    ASSERT_EQ(y.size(),     11);
    ASSERT_EQ(y.capacity(), 20);
    ASSERT_TRUE(x != y);
    y = x;
    ASSERT_EQ(y.size(),     15);
    ASSERT_EQ(y.capacity(), 20);
    ASSERT_EQ(x, y);}

TYPED_TEST(Vector_Fixture, test_11) {
    typedef typename TestFixture::vector_type vector_type;

    const vector_type x(20, 2);
    vector_type       y(10, 3);
    ASSERT_EQ(y.size(),     10);
    ASSERT_EQ(y.capacity(), 10);
    ASSERT_TRUE(x != y);
    y = x;
    ASSERT_EQ(y.size(),     20);
    ASSERT_EQ(y.capacity(), 20);
    ASSERT_EQ(x, y);}

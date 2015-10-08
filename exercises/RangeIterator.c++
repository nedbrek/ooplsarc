// -----------------
// RangeIterator.c++
// -----------------

#include <algorithm> // equal
#include <list>      // list

#include "gtest/gtest.h"

#include "RangeIterator.h"

using namespace std;

/*
    public:
        using iterator_category = input_iterator_tag;
        using value_type        = T;
        using difference_type   = ptrdiff_t;
        using pointer           = T*;
        using reference         = T&;
*/

TEST(Range_Iterator_Fixture, test_1) {
    Range_Iterator<int> b = 2;
    Range_Iterator<int> e = 2;
    ASSERT_EQ(b, e);}

TEST(Range_Iterator_Fixture, test_2) {
    Range_Iterator<int> b = 2;
    Range_Iterator<int> e = 3;
    ASSERT_NE(b, e);
    ASSERT_EQ(2, *b);
    ++b;
    ASSERT_EQ(b, e);}

TEST(Range_Iterator_Fixture, test_3) {
    Range_Iterator<int> b = 2;
    Range_Iterator<int> e = 4;
    ASSERT_NE(b, e);
    ASSERT_EQ(2, *b);
    ++b;
    ASSERT_NE(b, e);
    ASSERT_EQ(3, *b);
    b++;
    ASSERT_EQ(b, e);}

TEST(Range_Iterator_Fixture, test_4) {
    list<int> x = {2, 3, 4};
    ASSERT_TRUE(equal(Range_Iterator<int>(2), Range_Iterator<int>(5), x.begin()));}

/*
% g++ -pedantic -std=c++11 -Wall RangeIterator.c++ -o RangeIterator -lgtest_main



% RangeIterator
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from Range_Iterator_Fixture
[ RUN      ] Range_Iterator_Fixture.test_1
[       OK ] Range_Iterator_Fixture.test_1 (0 ms)
[ RUN      ] Range_Iterator_Fixture.test_2
[       OK ] Range_Iterator_Fixture.test_2 (0 ms)
[ RUN      ] Range_Iterator_Fixture.test_3
[       OK ] Range_Iterator_Fixture.test_3 (0 ms)
[ RUN      ] Range_Iterator_Fixture.test_4
[       OK ] Range_Iterator_Fixture.test_4 (0 ms)
[----------] 4 tests from Range_Iterator_Fixture (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 4 tests.
*/

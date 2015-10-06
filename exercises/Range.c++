// ---------
// Range.c++
// ---------

#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list

#include "gtest/gtest.h"

#include "Range.h"

using namespace std;

TEST(Range_Fixture, test_1) {
    Range<int> x(2, 2);
    Range<int>::iterator b = x.begin();
    Range<int>::iterator e = x.end();
    ASSERT_EQ(b, e);}

TEST(Range_Fixture, test_2) {
    Range<int> x(2, 3);
    Range<int>::iterator b = x.begin();
    Range<int>::iterator e = x.end();
    ASSERT_NE(b, e);
    ASSERT_EQ(2, *b);
    ++b;
    ASSERT_EQ(b, e);}

TEST(Range_Fixture, test_3) {
    Range<int> x(2, 4);
    Range<int>::iterator b = x.begin();
    Range<int>::iterator e = x.end();
    ASSERT_NE(b, e);
    ASSERT_EQ(2, *b);
    ++b;
    ASSERT_NE(b, e);
    ASSERT_EQ(3, *b);
    b++;
    ASSERT_EQ(b, e);}

TEST(Range_Fixture, test_4) {
    Range<int> x(2, 5);
    list<int>  y = {2, 3, 4};
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));}

/*
% g++ -pedantic -std=c++11 -Wall Range.c++ -o Range -lgtest_main



% Range
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from Range_Fixture
[ RUN      ] Range_Fixture.test_1
[       OK ] Range_Fixture.test_1 (0 ms)
[ RUN      ] Range_Fixture.test_2
[       OK ] Range_Fixture.test_2 (0 ms)
[ RUN      ] Range_Fixture.test_3
[       OK ] Range_Fixture.test_3 (0 ms)
[ RUN      ] Range_Fixture.test_4
[       OK ] Range_Fixture.test_4 (0 ms)
[----------] 4 tests from Range_Fixture (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 4 tests.
*/

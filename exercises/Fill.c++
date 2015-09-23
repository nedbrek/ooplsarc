// --------
// Fill.c++
// --------

#include <algorithm>  // all_of, fill
#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <list>       // list

#include "gtest/gtest.h"

#include "Fill.h"

using namespace std;

using testing::TestWithParam;
using testing::Values;

using Fill_List_Signature = std::function<void (list<int>::iterator, list<int>::iterator, const int&)>;

struct Fill_List_Fixture : TestWithParam<Fill_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Fill_List_Instantiation,
    Fill_List_Fixture,
    Values(
           fill<list<int>::iterator, int>,
        my_fill<list<int>::iterator, int>));

TEST_P(Fill_List_Fixture, test) {
    const size_t s = 3;
    const int    v = 5;
    list<int>    x(s);
    GetParam()(x.begin(), x.end(), v);
    ASSERT_TRUE(all_of(x.begin(), x.end(), [v] (int w) -> bool {return v == w;}));}

/*
% g++ -pedantic -std=c++11 -Wall Fill.c++ -o Fill -lgtest_main



% Fill
Running main() from gtest_main.cc
[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from Fill_List_Instantiation/Fill_List_Fixture
[ RUN      ] Fill_List_Instantiation/Fill_List_Fixture.test/0
[       OK ] Fill_List_Instantiation/Fill_List_Fixture.test/0 (0 ms)
[ RUN      ] Fill_List_Instantiation/Fill_List_Fixture.test/1
[       OK ] Fill_List_Instantiation/Fill_List_Fixture.test/1 (0 ms)
[----------] 2 tests from Fill_List_Instantiation/Fill_List_Fixture (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 2 tests.
*/

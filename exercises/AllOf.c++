// ---------
// AllOf.c++
// ---------

// http://www.cplusplus.com/reference/algorithm/all_of/

#include <algorithm>  // all_of
#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <list>       // list

#include "gtest/gtest.h"

#include "AllOf.h"

using namespace std;

using testing::TestWithParam;
using testing::Values;

using AllOf_List_Signature = function<bool (list<int>::const_iterator, list<int>::const_iterator, function<bool (int)>)>;

struct AllOf_List_Fixture : TestWithParam<AllOf_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    AllOf_List_Instantiation,
    AllOf_List_Fixture,
    Values(
           all_of<list<int>::const_iterator, function<bool (int)>>,
        my_all_of<list<int>::const_iterator, function<bool (int)>>));

TEST_P(AllOf_List_Fixture, test) {
    const list<int>       x = {2, 4, 6};
    ASSERT_TRUE(GetParam()(x.begin(), x.end(), [] (int v) -> bool {return (v % 2) == 0;}));}

/*
% g++ -pedantic -std=c++11 -Wall AllOf.c++ -o AllOf -lgtest_main



% AllOf
Running main() from gtest_main.cc
[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from AllOf_List_Instantiation/AllOf_List_Fixture
[ RUN      ] AllOf_List_Instantiation/AllOf_List_Fixture.test/0
[       OK ] AllOf_List_Instantiation/AllOf_List_Fixture.test/0 (0 ms)
[ RUN      ] AllOf_List_Instantiation/AllOf_List_Fixture.test/1
[       OK ] AllOf_List_Instantiation/AllOf_List_Fixture.test/1 (0 ms)
[----------] 2 tests from AllOf_List_Instantiation/AllOf_List_Fixture (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 2 tests.
*/

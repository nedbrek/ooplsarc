// --------
// Copy.c++
// --------

// http://www.cplusplus.com/reference/algorithm/copy/

#include <algorithm>  // copy, equal
#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <list>       // list
#include <vector>     // vector

#include "gtest/gtest.h"

#include "Copy.h"

using namespace std;

using testing::TestWithParam;
using testing::Values;

using Copy_List_Signature = function<vector<int>::iterator (list<int>::const_iterator, list<int>::const_iterator, vector<int>::iterator)>;

struct Copy_List_Fixture : TestWithParam<Copy_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Copy_List_Instantiation,
    Copy_List_Fixture,
    Values(
           copy<list<int>::const_iterator, vector<int>::iterator>,
        my_copy<list<int>::const_iterator, vector<int>::iterator>));

TEST_P(Copy_List_Fixture, test) {
    const list<int>       x = {2, 3, 4};
    vector<int>           y(5);
    const list<int>       z = {0, 2, 3, 4, 0};
    vector<int>::iterator p = GetParam()(x.begin(), x.end(), y.begin() + 1);
    ASSERT_EQ(p, y.begin() + 4);
    ASSERT_TRUE(equal(y.begin(), y.end(), z.begin()));}

/*
% g++ -pedantic -std=c++11 -Wall Copy.c++ -o Copy -lgtest_main



% Copy
Running main() from gtest_main.cc
[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from Copy_List_Instantiation/Copy_List_Fixture
[ RUN      ] Copy_List_Instantiation/Copy_List_Fixture.test/0
[       OK ] Copy_List_Instantiation/Copy_List_Fixture.test/0 (0 ms)
[ RUN      ] Copy_List_Instantiation/Copy_List_Fixture.test/1
[       OK ] Copy_List_Instantiation/Copy_List_Fixture.test/1 (0 ms)
[----------] 2 tests from Copy_List_Instantiation/Copy_List_Fixture (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 2 tests.
*/

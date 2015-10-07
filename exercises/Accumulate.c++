// --------------
// Accumulate.c++
// --------------

// http://www.cplusplus.com/reference/algorithm/accumulate/

#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <numeric>    // accumulate
#include <list>       // list

#include "gtest/gtest.h"

#include "Accumulate.h"

using namespace std;

using testing::TestWithParam;
using testing::Values;

using Accumulate_List_Signature = function<int (list<int>::const_iterator, list<int>::const_iterator, int, function<int (int, int)>)>;

struct Accumulate_List_Fixture : TestWithParam<Accumulate_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Accumulate_List_Instantiation,
    Accumulate_List_Fixture,
    Values(
           accumulate<list<int>::const_iterator, int, function<int (int, int)>>,
        my_accumulate<list<int>::const_iterator, int, function<int (int, int)>>));

TEST_P(Accumulate_List_Fixture, test_1) {
    const list<int> x = {2, 3, 4};
    ASSERT_EQ(9, GetParam()(x.begin(), x.end(), 0, [] (int v, int w) -> int {return v + w;}));}

TEST_P(Accumulate_List_Fixture, test_2) {
    const list<int> x = {2, 3, 4};
    ASSERT_EQ(-8, GetParam()(x.begin(), x.end(), 1, [] (int v, int w) -> int {return v - w;}));}

/*
% g++ -pedantic -std=c++11 -Wall Accumulate.c++ -o Accumulate -lgtest_main



% Accumulate
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from Accumulate_List_Instantiation/Accumulate_List_Fixture
[ RUN      ] Accumulate_List_Instantiation/Accumulate_List_Fixture.test_1/0
[       OK ] Accumulate_List_Instantiation/Accumulate_List_Fixture.test_1/0 (0 ms)
[ RUN      ] Accumulate_List_Instantiation/Accumulate_List_Fixture.test_1/1
[       OK ] Accumulate_List_Instantiation/Accumulate_List_Fixture.test_1/1 (0 ms)
[ RUN      ] Accumulate_List_Instantiation/Accumulate_List_Fixture.test_2/0
[       OK ] Accumulate_List_Instantiation/Accumulate_List_Fixture.test_2/0 (0 ms)
[ RUN      ] Accumulate_List_Instantiation/Accumulate_List_Fixture.test_2/1
[       OK ] Accumulate_List_Instantiation/Accumulate_List_Fixture.test_2/1 (0 ms)
[----------] 4 tests from Accumulate_List_Instantiation/Accumulate_List_Fixture (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 4 tests.
*/

// -------------
// Transform.c++
// -------------

// http://www.cplusplus.com/reference/algorithm/transform/

#include <algorithm>  // transform, equal
#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <list>       // list
#include <vector>     // vector

#include "gtest/gtest.h"

#include "Transform.h"

using namespace std;

using testing::TestWithParam;
using testing::Values;

using Transform_List_Signature = function<vector<int>::iterator (list<int>::const_iterator, list<int>::const_iterator, vector<int>::iterator, function<int (int)>)>;

struct Transform_List_Fixture : TestWithParam<Transform_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Transform_List_Instantiation,
    Transform_List_Fixture,
    Values(
           transform<list<int>::const_iterator, vector<int>::iterator, function<int (int)>>,
        my_transform<list<int>::const_iterator, vector<int>::iterator, function<int (int)>>));

TEST_P(Transform_List_Fixture, test) {
    const list<int>       x = {2, 3, 4};
    vector<int>           y(5);
    const list<int>       z = {0, 4, 9, 16, 0};
    vector<int>::iterator p = GetParam()(x.begin(), x.end(), y.begin() + 1, [] (int v) -> int {return v * v;});
    ASSERT_EQ(p, y.begin() + 4);
    ASSERT_TRUE(equal(y.begin(), y.end(), z.begin()));}

/*
% g++ -pedantic -std=c++11 -Wall Transform.c++ -o Transform -lgtest_main



% Transform
Running main() from gtest_main.cc
[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from Transform_List_Instantiation/Transform_List_Fixture
[ RUN      ] Transform_List_Instantiation/Transform_List_Fixture.test/0
[       OK ] Transform_List_Instantiation/Transform_List_Fixture.test/0 (0 ms)
[ RUN      ] Transform_List_Instantiation/Transform_List_Fixture.test/1
[       OK ] Transform_List_Instantiation/Transform_List_Fixture.test/1 (0 ms)
[----------] 2 tests from Transform_List_Instantiation/Transform_List_Fixture (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 2 tests.
*/

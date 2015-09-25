// ---------
// Equal.c++
// ---------

// http://www.cplusplus.com/reference/algorithm/equal/

#include <algorithm>  // equal
#include <functional> // function
#include <list>       // list
#include <vector>     // vector

#include "gtest/gtest.h"

#include "Equal.h"

using namespace std;

using testing::TestWithParam;
using testing::Values;

using Equal_List_Signature = function<bool (list<int>::const_iterator, list<int>::const_iterator, vector<int>::const_iterator)>;

struct Equal_List_Fixture : TestWithParam<Equal_List_Signature> {
    const list<int>   _x;
    const vector<int> _y;

    Equal_List_Fixture () :
            _x {2, 3, 4},
            _y {2, 3, 4}
        {}};

INSTANTIATE_TEST_CASE_P(
    Equal_List_Instantiation,
    Equal_List_Fixture,
    Values(
           equal<list<int>::const_iterator, vector<int>::const_iterator>,
        my_equal<list<int>::const_iterator, vector<int>::const_iterator>));

TEST_P(Equal_List_Fixture, test) {
	ASSERT_TRUE(GetParam()(_x.begin(), _x.end(), _y.begin()));}

/*
% g++ -pedantic -std=c++11 -Wall Equal.c++ -o Equal -lgtest_main



% Equal
Running main() from gtest_main.cc
[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from Equal_List_Instantiation/Equal_List_Fixture
[ RUN      ] Equal_List_Instantiation/Equal_List_Fixture.test/0
[       OK ] Equal_List_Instantiation/Equal_List_Fixture.test/0 (0 ms)
[ RUN      ] Equal_List_Instantiation/Equal_List_Fixture.test/1
[       OK ] Equal_List_Instantiation/Equal_List_Fixture.test/1 (0 ms)
[----------] 2 tests from Equal_List_Instantiation/Equal_List_Fixture (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 2 tests.
*/

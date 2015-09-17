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

using Equal_Array_Signature = function<bool (const int*, const int*, const int*)>;

struct Equal_Array_Fixture : TestWithParam<Equal_Array_Signature> {
    const int _a[3];
    const int _b[3];

    Equal_Array_Fixture () :
            _a {2, 3, 4},
            _b {2, 3, 4}
        {}};

INSTANTIATE_TEST_CASE_P(
    Equal_Array_Instantiation,
    Equal_Array_Fixture,
    Values(
           equal<const int*, const int*>,
        my_equal<const int*, const int*>));

TEST_P(Equal_Array_Fixture, test_1) {
	ASSERT_TRUE(GetParam()(_a, _a + 3, _b));}

TEST_P(Equal_Array_Fixture, test_2) {
	ASSERT_FALSE(GetParam()(_a, _a + 2, _b + 1));}



using Equal_Vector_Signature = function<bool (vector<int>::const_iterator, vector<int>::const_iterator, vector<int>::const_iterator)>;

struct Equal_Vector_Fixture : TestWithParam<Equal_Vector_Signature> {
    const vector<int> _x;
    const vector<int> _y;

    Equal_Vector_Fixture () :
            _x {2, 3, 4},
            _y {2, 3, 4}
        {}};

INSTANTIATE_TEST_CASE_P(
    Equal_Vector_Instantiation,
    Equal_Vector_Fixture,
    Values(
           equal<vector<int>::const_iterator, vector<int>::const_iterator>,
        my_equal<vector<int>::const_iterator, vector<int>::const_iterator>));

TEST_P(Equal_Vector_Fixture, test_1) {
	ASSERT_TRUE(GetParam()(_x.begin(), _x.end(), _y.begin()));}

TEST_P(Equal_Vector_Fixture, test_2) {
	ASSERT_FALSE(GetParam()(_x.begin(), _x.begin() + 1, _y.begin() + 1));}



using Equal_List_Signature = function<bool (list<int>::const_iterator, list<int>::const_iterator, list<int>::const_iterator)>;

struct Equal_List_Fixture : TestWithParam<Equal_List_Signature> {
    const list<int> _x;
    const list<int> _y;

    Equal_List_Fixture () :
            _x {2, 3, 4},
            _y {2, 3, 4}
        {}};

INSTANTIATE_TEST_CASE_P(
    Equal_List_Instantiation,
    Equal_List_Fixture,
    Values(
           equal<list<int>::const_iterator, list<int>::const_iterator>,
        my_equal<list<int>::const_iterator, list<int>::const_iterator>));

TEST_P(Equal_List_Fixture, test_1) {
	ASSERT_TRUE(GetParam()(_x.begin(), _x.end(), _y.begin()));}

TEST_P(Equal_List_Fixture, test_2) {
    auto b1 = _x.begin();
    auto b2 = _y.begin();
	ASSERT_FALSE(GetParam()(_x.begin(), ++b1, ++b2));}

/*
% g++ -pedantic -std=c++11 -Wall Equal.c++ -o Equal -lgtest_main



% Equal
Running main() from gtest_main.cc
[==========] Running 12 tests from 3 test cases.
[----------] Global test environment set-up.
[----------] 4 tests from Equal_Array_Instantiation/Equal_Array_Fixture
[ RUN      ] Equal_Array_Instantiation/Equal_Array_Fixture.test_1/0
[       OK ] Equal_Array_Instantiation/Equal_Array_Fixture.test_1/0 (0 ms)
[ RUN      ] Equal_Array_Instantiation/Equal_Array_Fixture.test_1/1
[       OK ] Equal_Array_Instantiation/Equal_Array_Fixture.test_1/1 (0 ms)
[ RUN      ] Equal_Array_Instantiation/Equal_Array_Fixture.test_2/0
[       OK ] Equal_Array_Instantiation/Equal_Array_Fixture.test_2/0 (0 ms)
[ RUN      ] Equal_Array_Instantiation/Equal_Array_Fixture.test_2/1
[       OK ] Equal_Array_Instantiation/Equal_Array_Fixture.test_2/1 (0 ms)
[----------] 4 tests from Equal_Array_Instantiation/Equal_Array_Fixture (0 ms total)

[----------] 4 tests from Equal_Vector_Instantiation/Equal_Vector_Fixture
[ RUN      ] Equal_Vector_Instantiation/Equal_Vector_Fixture.test_1/0
[       OK ] Equal_Vector_Instantiation/Equal_Vector_Fixture.test_1/0 (0 ms)
[ RUN      ] Equal_Vector_Instantiation/Equal_Vector_Fixture.test_1/1
[       OK ] Equal_Vector_Instantiation/Equal_Vector_Fixture.test_1/1 (0 ms)
[ RUN      ] Equal_Vector_Instantiation/Equal_Vector_Fixture.test_2/0
[       OK ] Equal_Vector_Instantiation/Equal_Vector_Fixture.test_2/0 (0 ms)
[ RUN      ] Equal_Vector_Instantiation/Equal_Vector_Fixture.test_2/1
[       OK ] Equal_Vector_Instantiation/Equal_Vector_Fixture.test_2/1 (0 ms)
[----------] 4 tests from Equal_Vector_Instantiation/Equal_Vector_Fixture (0 ms total)

[----------] 4 tests from Equal_List_Instantiation/Equal_List_Fixture
[ RUN      ] Equal_List_Instantiation/Equal_List_Fixture.test_1/0
[       OK ] Equal_List_Instantiation/Equal_List_Fixture.test_1/0 (0 ms)
[ RUN      ] Equal_List_Instantiation/Equal_List_Fixture.test_1/1
[       OK ] Equal_List_Instantiation/Equal_List_Fixture.test_1/1 (0 ms)
[ RUN      ] Equal_List_Instantiation/Equal_List_Fixture.test_2/0
[       OK ] Equal_List_Instantiation/Equal_List_Fixture.test_2/0 (0 ms)
[ RUN      ] Equal_List_Instantiation/Equal_List_Fixture.test_2/1
[       OK ] Equal_List_Instantiation/Equal_List_Fixture.test_2/1 (0 ms)
[----------] 4 tests from Equal_List_Instantiation/Equal_List_Fixture (0 ms total)

[----------] Global test environment tear-down
[==========] 12 tests from 3 test cases ran. (0 ms total)
[  PASSED  ] 12 tests.
*/

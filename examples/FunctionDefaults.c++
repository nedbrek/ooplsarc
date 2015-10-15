// --------------------
// FunctionDefaults.c++
// --------------------

// http://www.cplusplus.com/doc/tutorial/functions2/

#include <cassert>  // assert
#include <iostream> // cout, endl

int f (int i, int j, int k = 4);

void g1 () {
//  assert(f()        ==  9);  // error: too few arguments to function "int f(int, int, int)"
//  assert(f(2)       ==  9);  // error: too few arguments to function "int f(int, int, int)"
    assert(f(2, 3)    ==  9);
    assert(f(2, 3, 5) == 10);}

int f (int r, int s = 3, int t) {
    return r + s + t;}

void g2 () {
//  assert(f()        ==  9);  // error: too few arguments to function "int f(int, int, int)"
    assert(f(2)       ==  9);
    assert(f(2, 3)    ==  9);
    assert(f(2, 4, 5) == 11);}

int f (int x = 2, int y, int z);

void g3 () {
    assert(f()        ==  9);
    assert(f(3)       == 10);
    assert(f(3, 4)    == 11);
    assert(f(3, 4, 5) == 12);}

int h (int i) {
    return i;}

int h (int i, int j = 0) {
    return i + j;}

//int x (int i, int j = i) { // error: default argument references parameter 'i'
//    return i + j;}

int main () {
    using namespace std;
    cout << "FunctionDefaults.c++" << endl;

    g1();
    g2();
    g3();

//  h(10);                   // error: call to 'h' is ambiguous
    assert(h(11, 12) == 23);

    cout << "Done." << endl;
    return 0;}

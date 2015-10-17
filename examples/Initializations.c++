// -------------------
// Initializations.c++
// -------------------

// http://en.cppreference.com/w/cpp/language/value_initialization
// http://en.cppreference.com/w/cpp/language/initializer_list
// http://en.cppreference.com/w/cpp/utility/initializer_list

#include <cassert>          // assert
#include <initializer_list> // initializer_list
#include <iostream>         // cout, endl
#include <vector>           // vector

using namespace std;

struct A {
    int _i;

    A (int i) :
            _i (i)
        {}};

struct B {
    int _i;

    explicit B (int i) :
            _i (i)
        {}};

struct C {
    vector<int> _v;

    C (initializer_list<int> l) :
            _v (l)
        {}

    int size () {
        return _v.size();}};

int main () {
    cout << "Initializations.c++" << endl;

    {
    int i = 2;
    assert(i == 2);
    int j(3);
    assert(j == 3);
    int k{4};
    assert(k == 4);
    int m = {5};
    assert(m == 5);
    }

    {
    A x = 2;
    assert(&x == &x);
    A y(2);
    assert(&y == &y);
    A z{2};
    assert(&z == &z);
    A t = {2};
    assert(&t == &t);
    }

    {
//  B x = 2;          // error: no viable conversion from 'int' to 'B'
    B y(2);
    assert(&y == &y);
    B z{2};
    assert(&z == &z);
//  B t = {2};        // error: chosen constructor is explicit in copy-initialization
    }

    {
//  C x = 2;               // error: no viable conversion from 'int' to 'C'
//  C y(2);                // error: no matching constructor for initialization of 'C'
    C z{2};
    assert(z.size() == 1);
    C t = {2};
    assert(t.size() == 1);
    }

    {
//  vector<int> x = 2;     // error: no viable conversion from 'int' to 'vector<int>'
    vector<int> y(2);
    assert(y.size() == 2);
    vector<int> z{2};
    assert(z.size() == 1);
    vector<int> t = {2};
    assert(t.size() == 1);
    vector<int> u{2, 3, 4};
    assert(u.size() == 3);
    }

    cout << "Done." << endl;
    return 0;}

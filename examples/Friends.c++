// -----------
// Friends.c++
// -----------

#include <cassert>  // assert
#include <iostream> // cout, endl

// -
// f
// -

int f1 ();

template <typename T>
int f2 ();

template <typename T>
int f3 ();

template <typename T>
int f4 ();

// -
// A
// -

template <typename T>
class A {
    // global function f1
    friend int f1 ();

    // 'int' instance  of global function template f2
    friend int f2<int>();

    // T     instance  of global function template f3
    friend int f3<T>();

    // all   instances of global function template f4
    template <typename U>
    friend int f4(); // not f4<U>()!

    private:
        int i;

    public:
        A (int i) :
                i (i)
            {}};

// -
// f
// -

int f1 () {
    A<int> x = 2;
    return ++x.i;}

template <typename T>
int f2 () {
    A<int> x = 2;
    return ++x.i;}

template <typename T>
int f3 () {
    A<int> x = 2;
    return ++x.i;}

template <typename T>
int f4 () {
    A<int> x = 2;
    return ++x.i;}

// ----
// main
// ----

int main () {
    using namespace std;
    cout << "Friends.c++" << endl;

    assert(f1()         == 3); // f1               friend of A<int>

    assert(f2<int>()    == 3); // f2<int>          friend of A<int>
//  assert(f2<double>() == 3); // f2<double> not a friend of A<int>

    assert(f3<int>()    == 3); // f3<int>          friend of A<int>
//  assert(f3<double>() == 3); // f3<double> not a friend of A<int>

    assert(f4<int>()    == 3); // f4<int>          friend of A<int>
    assert(f4<double>() == 3); // f4<double>       friend of A<int>

    cout << "Done." << endl;
    return 0;}

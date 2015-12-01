// ------------------
// ClassVariables.c++
// ------------------

#include <cassert>  // assert
#include <iostream> // cout, endl

template <typename T>
struct A {
    static T v0;

//  static T v1 = 1;        // error: error: non-const static data member must be initialized out of line
    static T v1;

//  static const T cv0 = 0; // error: in-class initializer for static data member of type 'const double' requires 'constexpr' specifier
    static const T cv0;

    static const int cv1 = 1;};

template <typename T>
T A<T>::v0;

template <typename T>
T A<T>::v1 = v0 + 1;

//template <typename T> // error: default initialization of an object of const type 'const int'
//const T A<T>::cv0;

template <typename T>
const T A<T>::cv0 = T();

//template <typename T>
//const int A<T>::cv1 = cv0 + 1; // error: static data member 'cv1' already has an initializer

template <typename T>
const int A<T>::cv1;

int main () {
    using namespace std;
    cout << "ClassVariables.c++" << endl;

    assert(A<int>::v0    == 0);
    assert(A<double>::v0 == 0);

    assert(A<int>::v1    == 1);
    assert(A<double>::v1 == 1);

    assert(A<int>::cv0    == 0);
    assert(A<double>::cv0 == 0);

    assert(A<int>::cv1    == 1);
    assert(A<double>::cv1 == 1);

    assert(&A<int>::cv1 == &A<int>::cv1);
    assert(&A<int>::cv1 != &A<double>::cv1);

    A<int> x;
    A<int> y;
    assert(&x.cv1 == &y.cv1);

    cout << "Done." << endl;
    return 0;}

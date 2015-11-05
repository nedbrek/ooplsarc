// --------
// Move.c++
// --------

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

template <typename T>
struct A {
    explicit A(int) {
        cout << "A(int) ";}

    A (const A& rhs) {
        cout << "A(const A&) ";}

    A (A&&) {
        cout << "A(A&&) ";}

    A& operator = (const A&) {
        cout << "=(const A&) ";
        return *this;}

    A& operator = (A&&) {
        cout << "=(A&&) ";
        return *this;}

    ~A() {
        cout << "~A() ";}};

#include "Move.h"

template <typename T>
struct B {
    A<T> _x;

    explicit B (int s) :
            _x (s) {
        cout << "B(int) ";}

    B (const B& rhs) :
            _x (rhs._x) {
        cout << "B(const B&) ";}

    B& operator = (const B& rhs) {
        if (this == &rhs)
            return *this;
        _x = rhs._x;
        cout << "=(const B&) ";
        return *this;}

    ~B() {
        cout << "~B() ";}};

B<int> f (B<int> x) {
    return x;}

C<int> g (C<int> x) {
    return x;}

int main() {
    {
    cout << "ctor: ";
    B<int> x(f(B<int>(3))); // A(int) B(int) A(const A&) B(const B&) ~B() ~A()
    cout << endl;

    cout << "dtor: ";
    }                       // ~B() ~A()
    cout << endl << endl;



    {
    cout << "move: ";
    C<int> x(g(C<int>(3))); // A(int) C(int) A(A&&) C(C&&) ~C() ~A()
    cout << endl;

    cout << "dtor: ";
    }                       // ~C() ~A()
    cout << endl << endl;



    {
    cout << "ctor: ";
    B<int> x(2);            // A(int) B(int)
    cout << endl;

    cout << "asgn: ";
    x = B<int>(3);          // A(int) B(int) =(const A&) =(const B&) ~B() ~A()
    cout << endl;

    cout << "dtor: ";
    }                       // ~B() ~A()
    cout << endl << endl;



    {
    cout << "ctor: ";
    C<int> x(2);            // A(int) C(int)
    cout << endl;

    cout << "move: ";
    x = C<int>(3);          // A(int) C(int) =(A&&) =(C&&) ~C() ~A()
    cout << endl;

    cout << "dtor: ";
    }                       // ~C() ~A()
    cout << endl;

    return 0;}

/*
ctor: A(int) B(int) A(const A&) B(const B&) ~B() ~A()
dtor: ~B() ~A()

move: A(int) C(int) A(A&&) C(C&&) ~C() ~A()
dtor: ~C() ~A()

ctor: A(int) B(int)
asgn: A(int) B(int) =(const A&) =(const B&) ~B() ~A()
dtor: ~B() ~A()

ctor: A(int) C(int)
move: A(int) C(int) =(A&&) =(C&&) ~C() ~A()
dtor: ~C() ~A()
*/

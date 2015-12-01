// --------------
// Reflection.c++
// --------------

// http://www.cplusplus.com/reference/memory/shared_ptr/

#include <string> // string
#include <memory> // shared_ptr

#include "gtest/gtest.h"

#include "Reflection.h"

using namespace std;

struct A {
    virtual string f () = 0;};

struct B : A {
    static Reflection<A> r;

    string f () {
        return "B::f()";}};

Reflection<A> B::r("B", shared_ptr<A>(new B));

struct C : A {
    static Reflection<A> r;

    string f () {
        return "C::f()";}};

Reflection<A> C::r("C", shared_ptr<A>(new C));

TEST(Is_Prime_Fixture, test_1) {
    shared_ptr<A> p = Reflection<A>::only().find("B")->second;
    ASSERT_EQ("B::f()", p->f());}

TEST(Is_Prime_Fixture, test_2) {
    shared_ptr<A> p = Reflection<A>::only().find("C")->second;
    ASSERT_EQ("C::f()", p->f());}

// -------------
// SharedPtr.c++
// -------------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <memory>   // shared_ptr
#include <typeinfo> // bad_cast
#include <utility>  // !=

#include "gtest/gtest.h"

#include "Shapes.h"

using namespace std;
using rel_ops::operator!=;

using Shape       = shared_ptr<      AbstractShape>;
using Const_Shape = shared_ptr<const AbstractShape>;

TEST(Handle_Fixture, test_1) {
//  Const_Shape x = new Circle(2, 3, 4);
    Const_Shape x(new Circle(2, 3, 4));
//  x->move(5, 6);                       // doesn't compile
    ASSERT_EQ(3.14 * 4 * 4, x->area());
//  x->radius();                         // doesn't compile
    if (const Circle* const p = dynamic_cast<const Circle*>(x.get()))
        ASSERT_EQ(4, p->radius());
    try {
        const Circle& r = dynamic_cast<const Circle&>(*x.get());
        ASSERT_EQ(4, r.radius());}
    catch (const bad_cast& e) {
        assert(false);}
    ASSERT_TRUE(x.unique());
    ASSERT_EQ(1, x.use_count());}

TEST(Handle_Fixture, test_2) {
    Shape x(new Circle(2, 3, 4));
    x->move(5, 6);
    ASSERT_EQ(*Shape(new Circle(5, 6, 4)), *x);
    ASSERT_EQ(3.14 * 4 * 4, x->area());
//  x.radius();                                                              // doesn't compile
    if (const Circle* const p = dynamic_cast<const Circle*>(x.operator->()))
        ASSERT_EQ(4, p->radius());
    try {
        const Circle& r = dynamic_cast<const Circle&>(x.operator*());
        ASSERT_EQ(4, r.radius());}
    catch (const bad_cast& e) {
        assert(false);}
    ASSERT_TRUE(x.unique());
    ASSERT_EQ(1, x.use_count());}

TEST(Handle_Fixture, test_3) {
    const Shape x(new Circle(2, 3, 4));
//        Shape y = x;
          Shape y(x);
    ASSERT_EQ(*x, *y);
    ASSERT_FALSE(x.unique());
    ASSERT_EQ(2, x.use_count());
    ASSERT_FALSE(y.unique());
    ASSERT_EQ(2, y.use_count());
    y->move(5, 6);
    ASSERT_EQ(*Shape(new Circle(5, 6, 4)), *x);
    ASSERT_EQ(*Shape(new Circle(5, 6, 4)), *y);
    ASSERT_FALSE(x.unique());
    ASSERT_EQ(2, x.use_count());
    ASSERT_FALSE(y.unique());
    ASSERT_EQ(2, y.use_count());
    ASSERT_EQ(3.14 * 4 * 4, y->area());}

TEST(Handle_Fixture, test_4) {
    const Shape x(new Circle(2, 3, 4));
          Shape y(x);
    ASSERT_EQ(*x, *y);
    ASSERT_FALSE(x.unique());
    ASSERT_EQ(2, x.use_count());
    ASSERT_FALSE(y.unique());
    ASSERT_EQ(2, y.use_count());
    y = Shape(x->clone());
    y->move(5, 6);
    ASSERT_EQ(*Shape(new Circle(2, 3, 4)), *x);
    ASSERT_EQ(*Shape(new Circle(5, 6, 4)), *y);
    ASSERT_TRUE(x.unique());
    ASSERT_EQ(1, x.use_count());
    ASSERT_TRUE(y.unique());
    ASSERT_EQ(1, y.use_count());
    ASSERT_EQ(3.14 * 4 * 4, y->area());}

TEST(Handle_Fixture, test_5) {
    const Shape x(new Circle(2, 3, 4));
          Shape y(new Circle(2, 3, 5));
    ASSERT_NE(*x, *y);
    y = x;
    ASSERT_EQ(*x, *y);
    ASSERT_FALSE(x.unique());
    ASSERT_EQ(2, x.use_count());
    ASSERT_FALSE(y.unique());
    ASSERT_EQ(2, y.use_count());
    y->move(5, 6);
    ASSERT_EQ(*Shape(new Circle(5, 6, 4)), *x);
    ASSERT_EQ(*Shape(new Circle(5, 6, 4)), *y);
    ASSERT_FALSE(x.unique());
    ASSERT_EQ(2, x.use_count());
    ASSERT_FALSE(y.unique());
    ASSERT_EQ(2, y.use_count());
    ASSERT_EQ(3.14 * 4 * 4, y->area());}

TEST(Handle_Fixture, test_6) {
    const Shape x(new Circle(2, 3, 4));
          Shape y(new Circle(2, 3, 5));
    ASSERT_NE(*x, *y);
    y = x;
    ASSERT_EQ(*x, *y);
    ASSERT_FALSE(x.unique());
    ASSERT_EQ(2, x.use_count());
    ASSERT_FALSE(y.unique());
    ASSERT_EQ(2, y.use_count());
    y = Shape(x->clone());
    y->move(5, 6);
    ASSERT_EQ(*Shape(new Circle(2, 3, 4)), *x);
    ASSERT_EQ(*Shape(new Circle(5, 6, 4)), *y);
    ASSERT_TRUE(x.unique());
    ASSERT_EQ(1, x.use_count());
    ASSERT_TRUE(y.unique());
    ASSERT_EQ(1, y.use_count());
    ASSERT_EQ(3.14 * 4 * 4, y->area());}

/*
int main () {
    cout << "SharedPtr.c++" << endl;

    {
    Const_Shape x(new Circle(2, 3, 4));
//  x->move(5, 6);                                                    // doesn't compile
    assert(x->area() == (3.14 * 4 * 4));
//  assert(x->radius() == 4);                                         // doesn't compile
    if (const Circle* const q = dynamic_cast<const Circle*>(x.get()))
        assert(q->radius() == 4);
    try {
        const Circle& r = dynamic_cast<const Circle&>(*x.get());
        assert(r.radius() == 4);}
    catch (const bad_cast& e) {
        assert(false);}
    assert(x.unique());
    assert(x.use_count() == 1);
    }

    {
    const Shape x(new Circle(2, 3, 4));
    x->move(5, 6);
    assert(x->area() == (3.14 * 4 * 4));
//  assert(x->radius() == 4);                                   // doesn't compile
    if (const Circle* const q = dynamic_cast<Circle*>(x.get()))
        assert(q->radius() == 4);
    try {
        const Circle& r = dynamic_cast<Circle&>(*x.get());
        assert(r.radius() == 4);}
    catch (const bad_cast& e) {
        assert(false);}
    assert(x.unique());
    assert(x.use_count() == 1);
    }

    {
    const Shape x(new Circle(2, 3, 4));
          Shape y = x;
    assert(x == y);
    assert(!x.unique());
    assert(x.use_count() == 2);
    assert(!y.unique());
    assert(y.use_count() == 2);
    y->move(5, 6);
    assert(x == y);
    assert(!x.unique());
    assert(x.use_count() == 2);
    assert(!y.unique());
    assert(y.use_count() == 2);
    y = Shape(y->clone());
    assert(x != y);
    assert(x.unique());
    assert(x.use_count() == 1);
    assert(y.unique());
    assert(y.use_count() == 1);
    y->move(5, 6);
    }

    {
    const Shape x(new Circle(2, 3, 4));
          Shape y(new Circle(2, 3, 5));
    assert(x != y);
    y = x;
    assert(x == y);
    assert(!x.unique());
    assert(x.use_count() == 2);
    assert(!y.unique());
    assert(y.use_count() == 2);
    y->move(5, 6);
    assert(x == y);
    assert(!x.unique());
    assert(x.use_count() == 2);
    assert(!y.unique());
    assert(y.use_count() == 2);
    y = Shape(y->clone());
    assert(x != y);
    assert(x.unique());
    assert(x.use_count() == 1);
    assert(y.unique());
    assert(y.use_count() == 1);
    y->move(5, 6);
    }

    cout << "Done." << endl;
    return 0;}
*/

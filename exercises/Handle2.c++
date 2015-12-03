// -----------
// Handle2.c++
// -----------

#include <typeinfo> // bad_cast
#include <utility>  // !=

#include "gtest/gtest.h"

#include "Shapes.h"
#include "Handle2.h"

using namespace std;
using rel_ops::operator!=;

typedef Handle<AbstractShape> Shape;

TEST(Handle_Fixture, test_1) {
    const Shape x = new Circle(2, 3, 4);
//  x->move(5, 6);                                                           // doesn't compile
    ASSERT_EQ(3.14 * 4 * 4, x->area());
//  x->radius();                                                             // doesn't compile
    if (const Circle* const p = dynamic_cast<const Circle*>(x.operator->()))
        ASSERT_EQ(4, p->radius());
    try {
        const Circle& r = dynamic_cast<const Circle&>(x.operator*());
        ASSERT_EQ(4, r.radius());}
    catch (const bad_cast& e) {
        assert(false);}}

TEST(Handle_Fixture, test_2) {
    Shape x = new Circle(2, 3, 4);
    x->move(5, 6);
    ASSERT_EQ(new Circle(5, 6, 4), x);
    ASSERT_EQ(3.14 * 4 * 4, x->area());
//  x.radius();                                                              // doesn't compile
    if (const Circle* const p = dynamic_cast<const Circle*>(x.operator->()))
        ASSERT_EQ(4, p->radius());
    try {
        const Circle& r = dynamic_cast<const Circle&>(x.operator*());
        ASSERT_EQ(4, r.radius());}
    catch (const bad_cast& e) {
        assert(false);}}

TEST(Handle_Fixture, test_3) {
    const Shape x = new Circle(2, 3, 4);
          Shape y = x;
    ASSERT_EQ(x, y);
    y->move(5, 6);
    ASSERT_EQ(new Circle(2, 3, 4), x);
    ASSERT_EQ(new Circle(5, 6, 4), y);
    ASSERT_EQ(3.14 * 4 * 4, y->area());}

TEST(Handle_Fixture, test_4) {
    const Shape x = new Circle(2, 3, 4);
          Shape y = new Circle(2, 3, 5);
    ASSERT_NE(x, y);
    y = x;
    ASSERT_EQ(x, y);}

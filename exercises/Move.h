// ------
// Move.h
// ------

#ifndef Move_h
#define Move_h

#include <utility> // move

template <typename T>
struct C {
    A<T> _x;

    explicit C (int s) :
            _x (s) {
        cout << "C(int) ";}

    C (const C& rhs) :
            _x (rhs._x) {
        cout << "C(const C&) ";}

    C (C&& rhs) :
            _x (move(rhs._x)) {
        cout << "C(C&&) ";}

    C& operator = (const C& rhs) {
        _x = rhs._x;
        cout << "=(const C&) ";
        return *this;}

    C& operator = (C&& rhs) {
        _x = move(rhs._x);
        cout << "=(C&&) ";
        return *this;}

    ~C() {
        cout << "~C() ";}};

#endif // Move_h

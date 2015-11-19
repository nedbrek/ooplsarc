// ---------
// Shapes1.h
// ---------

#ifndef Shapes1_h
#define Shapes1_h

#include <utility> // !=

using std::rel_ops::operator!=;

class Circle : public Shape {
    friend bool operator == (const Circle& lhs, const Circle& rhs) {
        return (static_cast<const Shape&>(lhs) == rhs) && (lhs._r == rhs._r);}

    friend std::istream& operator >> (std::istream& lhs, Circle& rhs) {
        return lhs >> static_cast<Shape&>(rhs) >> rhs._r;}

    friend std::ostream& operator << (std::ostream& lhs, const Circle& rhs) {
        return lhs << static_cast<const Shape&>(rhs) << " " << rhs._r;}

    private:
        int _r;

    public:
        Circle (int x, int y, int r) :
                Shape (x, y),
                _r    (r)
            {}

        Circle             (const Circle&)  = default;
        Circle             (      Circle&&) = default;
        ~Circle            ()               = default;
        Circle& operator = (const Circle&)  = default;
        Circle& operator = (      Circle&&) = default;

        double area () const {
            return 3.14 * _r * _r;}

        int radius () const {
            return _r;}};

#endif // Shapes1_h

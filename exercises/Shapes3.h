// ---------
// Shapes3.h
// ---------

#ifndef Shapes3_h
#define Shapes3_h

#include <utility> // !=

using std::rel_ops::operator!=;

class Circle : public AbstractShape {
    private:
        int _r;

    protected:
        virtual bool equals (const AbstractShape& rhs) const {
            if (const Circle* const p = dynamic_cast<const Circle*>(&rhs))
                return AbstractShape::equals(*p) && (_r == p->_r);
            return false;}

        virtual std::istream& read (std::istream& in) {
            return AbstractShape::read(in) >> _r;}

        virtual std::ostream& write (std::ostream& out) const {
            return AbstractShape::write(out) << " " << _r;}

    public:
        Circle (int x, int y, int r) :
                AbstractShape (x, y),
                _r            (r)
            {}

        Circle             (const Circle&)  = default;
        Circle             (      Circle&&) = default;
        ~Circle            ()               = default;
        Circle& operator = (const Circle&)  = default;
        Circle& operator = (      Circle&&) = default;

        virtual double area () const {
            return 3.14 * _r * _r;}

        virtual Circle* clone () const {
            return new Circle(*this);}

        int radius () const {
            return _r;}};

#endif // Shapes3_h

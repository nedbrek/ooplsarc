// ---------
// Handle1.h
// ---------

#ifndef Handle1_h
#define Handle1_h

#include <algorithm> // swap

using namespace std;

template <typename T>
class Handle {
    friend bool operator == (const Handle& lhs, const Handle& rhs) {
        if (!lhs._p && !rhs._p)
            return true;
        if (!lhs._p || !rhs._p)
            return false;
        return (*lhs._p == *rhs._p);}

    public:
        typedef T                 value_type;

        typedef value_type*       pointer;
        typedef const value_type* const_pointer;

        typedef value_type&       reference;
        typedef const value_type& const_reference;

    private:
        pointer _p;

    protected:
        pointer get () {
            return _p;}

        const_pointer get () const {
            return _p;}

    public:
        Handle (pointer p) {
            _p = p;}

        Handle (const Handle& rhs) {
            if (!rhs._p)
                _p = 0;
            else
                _p = rhs._p->clone();}

        ~Handle () {
            delete _p;}

        Handle& operator = (Handle rhs) {
            swap(rhs);
            return *this;}

        void swap (Handle& rhs) {
            std::swap(_p, rhs._p);}};

#endif // Handle1_h

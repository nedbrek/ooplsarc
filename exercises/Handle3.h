// ---------
// Handle3.h
// ---------

#ifndef Handle3_h
#define Handle3_h

#include <algorithm> // swap
#include <cassert>   // assert
#include <cstddef>   // size_t

using namespace std;

template <typename T>
class Handle {
    friend bool operator == (const Handle& lhs, const Handle& rhs) {
        if (!lhs.get() && !rhs.get())
            return true;
        if (!lhs.get() || !rhs.get())
            return false;
        return (*lhs.get() == *rhs.get());}

    public:
        typedef T                 value_type;

        typedef value_type*       pointer;
        typedef const value_type* const_pointer;

        typedef value_type&       reference;
        typedef const value_type& const_reference;

    private:
        struct count {
            std::size_t _c;
            pointer     _q;

            count (pointer q) :
                    _c (1),
                    _q (q) {
                assert(_q);}

            ~count () {
                assert(_c == 1);
                delete _q;}};

        count* _p;

    protected:
        pointer get () {
            if (!unique()) {
                --_p->_c;
                _p = new count(_p->_q->clone());}
            return _p->_q;}

        const_pointer get () const {
            return _p->_q;}

    public:
        Handle (pointer q) {
            _p = new count(q);}

        Handle (const Handle& rhs) {
            _p = rhs._p;
            ++_p->_c;}

        ~Handle () {
            if (unique())
                delete _p;
            else
                --_p->_c;}

        Handle& operator = (Handle that) {
            swap(that);
            return *this;}

        void swap (Handle& that) {
            std::swap(_p, that._p);}

        bool unique () const {
            return use_count() == 1;}

        int use_count () const {
            return _p->_c;}};

#endif // Handle3_h

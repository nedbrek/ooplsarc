// ---------
// Vector4.h
// ---------

#ifndef Vector_h
#define Vector_h

#include <algorithm> // copy, equal, lexicographical_compare, max, swap
#include <cassert>   // assert
#include <memory>    // allocator
#include <stdexcept> // out_of_range
#include <utility>   // !=, <=, >, >=

#include "Memory.h"  // my_destroy, my_uninitialized_copy, my_uninitialized_fill

/*
namespace std     {
namespace rel_ops {

template <typename T>
inline bool operator != (const T& lhs, const T& rhs) {
    return !(lhs == rhs);}

template <typename T>
inline bool operator <= (const T& lhs, const T& rhs) {
    return !(rhs < lhs);}

template <typename T>
inline bool operator > (const T& lhs, const T& rhs) {
    return (rhs < lhs);}

template <typename T>
inline bool operator >= (const T& lhs, const T& rhs) {
    return !(lhs < rhs);}

} // rel_ops
} // std;
*/

using namespace std::rel_ops;

template <typename T, typename A = std::allocator<T> >
class my_vector {
    public:
        using allocator_type  = A;
        using value_type      = typename allocator_type::value_type;

        using size_type       = typename allocator_type::size_type;
        using difference_type = typename allocator_type::difference_type;

        using       pointer   = typename allocator_type::pointer;
        using const_pointer   = typename allocator_type::const_pointer;

        using       reference = typename allocator_type::reference;
        using const_reference = typename allocator_type::const_reference;

        using       iterator  = typename allocator_type::pointer;
        using const_iterator  = typename allocator_type::const_pointer;

    public:
        friend bool operator == (const my_vector& lhs, const my_vector& rhs) {
            return (lhs.size() == rhs.size()) && std::equal(lhs.begin(), lhs.end(), rhs.begin());}

        friend bool operator < (const my_vector& lhs, const my_vector& rhs) {
            return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());}

        friend void swap (my_vector& x, my_vector& y) {
            x.swap(y);}

    private:
        allocator_type _a;

        pointer _b;
        pointer _e; // size
        pointer _l; // capacity

    private:
        bool valid () const {
            return (!_b && !_e && !_l) || ((_b <= _e) && (_e <= _l));}

        my_vector (const my_vector& rhs, size_type c) :
                _a (rhs._a) {
            assert(c >= rhs.size());
            _b = _a.allocate(c);
            _e = _b + rhs.size();
            _l = _b + c;
            my_uninitialized_copy(_a, rhs.begin(), rhs.end(), begin());
            assert(valid());}

    public:
        explicit my_vector (size_type s = 0, const_reference v = value_type(), const allocator_type& a = allocator_type()) :
                _a (a),
                _b (s == 0 ? nullptr : _a.allocate(s)),
                _e (s == 0 ? nullptr : _b + s),
                _l (s == 0 ? nullptr : _b + s) {
            my_uninitialized_fill(_a, begin(), end(), v);
            assert(valid());}

        my_vector (const my_vector& rhs) :
                _a (rhs._a) {
            _b = _a.allocate(rhs.size());
            _e = _l = _b + rhs.size();
            my_uninitialized_copy(_a, rhs.begin(), rhs.end(), begin());
            assert(valid());}

        ~my_vector () {
            if (!empty()) {
                clear();
                _a.deallocate(_b, capacity());}
            assert(valid());}

        my_vector& operator = (const my_vector& rhs) {
            if (this == &rhs)
                return *this;
            if (rhs.size() == size())
                std::copy(rhs.begin(), rhs.end(), begin());
            else if (rhs.size() < size()) {
                std::copy(rhs.begin(), rhs.end(), begin());
                resize(rhs.size());}
            else if (rhs.size() <= capacity()) {
                std::copy(rhs.begin(), rhs.begin() + size(), begin());
                _e = my_uninitialized_copy(_a, rhs.begin() + size(), rhs.end(), end());}
            else {
                clear();
                reserve(rhs.size());
                _e = my_uninitialized_copy(_a, rhs.begin(), rhs.end(), begin());}
            assert(valid());
            return *this;}

        reference operator [] (size_type i) {
            return begin()[i];}

        const_reference operator [] (size_type i) const {
            return const_cast<my_vector&>(*this)[i];}

        reference at (size_type i) throw (std::out_of_range) {
            if (i >= size())
                throw std::out_of_range("vector");
            return (*this)[i];}

        const_reference at (size_type i) const {
            return const_cast<my_vector&>(*this).at(i);}

        reference back () {
            assert(!empty());
            return *(end() - 1);}

        const_reference back () const {
            return const_cast<my_vector&>(*this).back();}

        iterator begin () {
            return _b;}

        const_iterator begin () const {
            return const_cast<my_vector&>(*this).begin();}

        size_type capacity () const {
            return begin() == nullptr ? 0 : _l - _b;}

        void clear () {
            resize(0);
            assert(valid());}

        bool empty () const {
            return size() == 0;}

        iterator end () {
            return _e;}

        const_iterator end () const {
            return const_cast<my_vector&>(*this).end();}

        reference front () {
            assert(!empty());
            return *begin();}

        const_reference front () const {
            return const_cast<my_vector&>(*this).front();}

        void pop_back () {
            assert(!empty());
            resize(size() - 1);
            assert(valid());}

        void push_back (const_reference v) {
            resize(size() + 1, v);
            assert(valid());}

        void reserve (size_type c) {
            if (c > capacity()) {
                my_vector x(*this, c);
                swap(x);}
            assert(valid());}

        void resize (size_type s, const_reference v = value_type()) {
            if (s == size())
                return;
            if (s < size())
                _e = my_destroy(_a, begin() + s, end());
            else if (s <= capacity())
                _e = my_uninitialized_fill(_a, end(), begin() + s, v);
            else {
                #ifdef __APPLE__
                reserve(std::max(2 * capacity(), s));
                #else
                reserve(std::max(2 * size(), s));
                #endif
                resize(s, v);}
            assert(valid());}

        size_type size () const {
            return begin() == nullptr ? 0 : _e - _b;}

        void swap (my_vector& rhs) {
            if (_a == rhs._a) {
                std::swap(_b, rhs._b);
                std::swap(_e, rhs._e);
                std::swap(_l, rhs._l);}
            else {
                my_vector x(*this);
                *this = rhs;
                rhs   = x;}
            assert(valid());}};

#endif // Vector_h

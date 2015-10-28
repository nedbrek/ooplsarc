// ---------
// Vector2.h
// ---------

#include <algorithm> // equal, lexicographical_compare
#include <cstddef>   // ptrdiff_t, size_t
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

template <typename T, typename A = std::allocator<T>>
class my_vector {
    friend bool operator == (const my_vector& lhs, const my_vector& rhs) {
        return (lhs.size() == rhs.size()) && std::equal(lhs.begin(), lhs.end(), rhs.begin());}

    friend bool operator < (const my_vector& lhs, const my_vector& rhs) {
        return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());}

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

    private:
        A             _a;
        const pointer _b;
        const pointer _e;

    public:
        explicit my_vector (size_type s = 0, const_reference v = T(), const A& a = A()) :
                _a (a),
                _b (s == 0 ? nullptr : _a.allocate(s)),
                _e (s == 0 ? nullptr : _b + s) {
            my_uninitialized_fill(_a, _b, _e, v);}

        ~my_vector () {
            my_destroy(_a, begin(), end());
            _a.deallocate(begin(), size());}

        reference operator [] (size_type i) {
            return begin()[i];}

        const_reference operator [] (size_type i) const {
            return (*const_cast<my_vector<T>*>(this))[i];}

        reference at (size_type i) {
            if (i >= size())
                throw std::out_of_range("my_vector::at index out of range");
            return (*this)[i];}

        const_reference at (size_type i) const {
            return const_cast<my_vector<T>*>(this)->at(i);}

        pointer begin () {
            return _b;}

        const_pointer begin () const {
            return const_cast<my_vector<T>*>(this)->begin();}

        pointer end () {
            return _e;}

        const_pointer end () const {
            return const_cast<my_vector<T>*>(this)->end();}

        size_type size () const {
            return (begin() == nullptr) ? 0 : end() - begin();}};

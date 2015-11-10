// -----------
// Allocator.h
// -----------

#include <cassert>  // assert
#include <cstddef>  // ptrdiff_t, size_t
#include <iostream> // cout, endl
#include <new>      // new

/*
namespace std {

void* operator new (size_t, void* p) {
    return p;}

} // std
*/

template <typename T>
struct My_Allocator {
    using value_type = T;

    using size_type       = std::size_t;
    using difference_type = std::ptrdiff_t;

    using       pointer   =       value_type*;
    using const_pointer   = const value_type*;

    using       reference =       value_type&;
    using const_reference = const value_type&;

    friend bool operator == (const My_Allocator&, const My_Allocator&) {
        return true;}

    friend bool operator != (const My_Allocator&, const My_Allocator&) {
        return false;}

    My_Allocator             ()                     = default;
    My_Allocator             (const My_Allocator&)  = default;
    My_Allocator             (      My_Allocator&&) = default;
    ~My_Allocator            ()                     = default;
    My_Allocator& operator = (const My_Allocator&)  = default;
    My_Allocator& operator = (      My_Allocator&&) = default;

    pointer allocate (size_type n) {
        return static_cast<pointer>(operator new(n * sizeof(value_type)));}

    void construct (pointer p, const_reference v) {
        new (p) value_type(v);}

    void deallocate (pointer p, size_type) {
        assert(p);
        operator delete(p);}

    void destroy (pointer p) {
        p->~value_type();}

    template <typename U>
    struct rebind {
        typedef My_Allocator<U> other;};};

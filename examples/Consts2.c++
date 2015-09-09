// -----------
// Consts2.c++
// -----------

#include <cassert>  // assert
#include <iostream> // cout, endl

int main () {
    using namespace std;
    cout << "Consts2.c++" << endl;

    // reference to a read/write, many-location pointer
    // mutable reference, mutable int, mutable pointer
    {
    int i = 2;
    typedef int* pointer;
    pointer  p = &i;
    pointer& r = p;
    ++*r;
    assert(i == 3);
    r = 0;
    assert(p == 0);
    }

    // const reference to a read/write, many-location pointer
    // immutable reference, mutable int, mutable pointer
    {
    int i = 2;
    typedef int* pointer;
          pointer  p = &i;
    const pointer& r = p;
    ++*r;
    assert(i == 3);
//  r = 0;                 // error: assignment of read-only reference 'r'
    p = 0;
    assert(r == 0);
    }

    // reference to a read-only, many-location pointer
    // mutable reference, immutable int, mutable pointer
    {
    int i = 2;
    typedef const int* pointer_to_constant;
    pointer_to_constant  p = &i;
    pointer_to_constant& r = p;
//  ++*r;                                   // error: increment of read-only location
//  ++*p;                                   // error: increment of read-only location
    r = 0;
    assert(p == 0);
    }

    // const reference to a read-only, many-location pointer
    // immutable reference, immutable int, mutable pointer
    {
    int i = 2;
    typedef const int* pointer_to_constant;
          pointer_to_constant  p = &i;
    const pointer_to_constant& r = p;
//  ++*r;                                   // error: increment of read-only location
//  ++*p;                                   // error: increment of read-only location
//  r = 0;                                  // error: assignment of read-only reference 'r'
    p = 0;
    assert(r == 0);
    }

    // reference to a read/write, one-location pointer
    // mutable reference, mutable int, immmutable pointer
    {
    int i = 2;
    typedef int* const constant_pointer;
    constant_pointer  p = &i;
    constant_pointer& r = p;
    ++*r;
    assert(i == 3);
//  r = 0;                               // error: assignment of read-only reference 'r'
//  p = 0;                               // error: assignment of read-only reference 'p'
    }

    // reference to a read-only, one-location pointer
    // mutable reference, immutable int, immmutable pointer
    {
    int i = 2;
    typedef const int* const constant_pointer_to_constant;
    constant_pointer_to_constant  p = &i;
    constant_pointer_to_constant& r = p;
//  ++*r;                                                  // error: increment of read-only location
//  ++*p;                                                  // error: increment of read-only location
//  r = 0;                                                 // error: assignment of read-only reference 'r'
//  p = 0;                                                 // error: assignment of read-only reference 'p'
    }

    // reference to read-only,  many-location pointer referring to read/write, many-location pointer
    {
    int i = 2;
    typedef       int* pointer;
    typedef const int* pointer_to_constant;
    pointer              p  = &i;
//  pointer_to_constant& r  = p;            // error: invalid initialization of reference of type ‘const int*&’ from expression of type ‘int*’
    }

    cout << "Done." << endl;
    return 0;}

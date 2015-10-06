// ------------
// Accumulate.h
// ------------

#ifndef Accumulate_h
#define Accumulate_h

template <typename II, typename T, typename BF>
T my_accumulate (II b, II e, T v, BF f) {
    while (b != e) {
        v = f(v, *b);
        ++b;}
    return v;}

#endif // Accumulate_h

// -----------
// Transform.h
// -----------

#ifndef Transform_h
#define Transform_h

template <typename II, typename OI, typename UF>
OI my_transform (II b, II e, OI x, UF f) {
    while (b != e) {
        *x = f(*b);
        ++b;
        ++x;}
    return x;}

#endif // Transform_h

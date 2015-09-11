// ---------------
// StackVsHeap.c++
// ---------------

// http://www.cplusplus.com/reference/new/

#include <cassert>  // assert
#include <iostream> // cout, endl

int f (int n) {
    if (n == 0)
        return 0;
    return 1 + f(n - 1);}

int main () {
    using namespace std;
    cout << "StackVsHeap.c++" << endl;

    {
    assert(f(1234567L) == 1234567L);   // 12345678L will fail
    }

    {
    #ifdef __APPLE__
        int* a = new int[12345678912345L]; // 123456789123456L will fail
    #else
        int* a = new int[1234567891L];     // 12345678912L will fail
    #endif
    assert(a == a);
    }

    return 0;}

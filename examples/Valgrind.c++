// ------------
// Valgrind.c++
// ------------

// http://valgrind.org

#include <cassert>  // assert
#include <iostream> // cout, endl

int main () {
    using namespace std;
    cout << "Valgrind.c++" << endl;

    int* p = new int;
    assert(p == p);

    cout << "Done." << endl;
    return 0;}

/*
% valgrind --version
valgrind-3.10.0.SVN



% g++ -pedantic -std=c++11 -Wall Valgrind.c++ -o Valgrind
...



% valgrind Valgrind
==11721== Memcheck, a memory error detector
==11721== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==11721== Using Valgrind-3.10.0.SVN and LibVEX; rerun with -h for copyright info
==11721== Command: Valgrind
==11721==
Valgrind.c++
Done.
==11721==
==11721== HEAP SUMMARY:
==11721==     in use at exit: 4 bytes in 1 blocks
==11721==   total heap usage: 1 allocs, 0 frees, 4 bytes allocated
==11721==
==11721== LEAK SUMMARY:
==11721==    definitely lost: 4 bytes in 1 blocks
==11721==    indirectly lost: 0 bytes in 0 blocks
==11721==      possibly lost: 0 bytes in 0 blocks
==11721==    still reachable: 0 bytes in 0 blocks
==11721==         suppressed: 0 bytes in 0 blocks
==11721== Rerun with --leak-check=full to see details of leaked memory
==11721==
==11721== For counts of detected and suppressed errors, rerun with: -v
==11721== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/

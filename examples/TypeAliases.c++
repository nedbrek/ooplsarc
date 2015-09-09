// ---------------
// TypeAliases.c++
// ---------------

// http://en.cppreference.com/w/cpp/language/type_alias

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <deque>    // deque
#include <stack>    // stack

using namespace std;

template <typename T>
struct my_stack_1 {
    typedef stack<T, deque<T>> type;};

template <typename T>
using my_stack_2 = stack<T, deque<T>>;



template <typename T>
class My_Stack {
    private:
        stack<T, deque<T>> _x;

    public:
        int size () const {
            return _x.size();}};

template <typename T>
class My_Stack_1 {
    private:
        typename my_stack_1<T>::type _x;

    public:
        int size () const {
            return _x.size();}};

template <typename T>
class My_Stack_2 {
    private:
        my_stack_2<T> _x;

    public:
        int size () const {
            return _x.size();}};

int main () {
    cout << "TypeAliases.c++" << endl;

    {
    stack<int, deque<int>> x;
    assert(x.size() == 0);
    }

    {
    my_stack_1<int>::type x;
    assert(x.size() == 0);
    }

    {
    my_stack_2<int> x;
    assert(x.size() == 0);
    }



    {
    My_Stack<int> x;
    assert(x.size() == 0);
    }

    {
    My_Stack_1<int> x;
    assert(x.size() == 0);
    }

    {
    My_Stack_2<int> x;
    assert(x.size() == 0);
    }

    cout << "Done." << endl;
    return 0;}

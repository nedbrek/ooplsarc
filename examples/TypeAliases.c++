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
class My_Container {
    private:
        stack<T, deque<T>> _x;

    public:
        int size () const {
            return _x.size();}};



template <typename T>
struct my_stack_1 {
    typedef stack<T, deque<T>> type;};

template <typename T>
class My_Container_1 {
    private:
        typename my_stack_1<T>::type _x;

    public:
        int size () const {
            return _x.size();}};



template <typename T>
using my_stack_2 = stack<T, deque<T>>;

template <typename T>
class My_Container_2 {
    private:
        my_stack_2<T> _x;

    public:
        int size () const {
            return _x.size();}};

int main () {
    cout << "TypeAliases.c++" << endl;

    {
    My_Container<int> x;
    assert(x.size() == 0);
    }

    {
    My_Container_1<int> x;
    assert(x.size() == 0);
    }

    {
    My_Container_2<int> x;
    assert(x.size() == 0);
    }

    cout << "Done." << endl;
    return 0;}

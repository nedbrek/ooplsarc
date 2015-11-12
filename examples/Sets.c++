// --------
// Sets.c++
// --------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <set>      // set
#include <utility>  // pair

int main () {
    using namespace std;
    cout << "Set.c++" << endl;

    typedef set<int>           set_type;
    typedef set_type::iterator iterator;

    {
    set_type x;
    assert(x.empty());
    assert(x.size() == 0);
    }

    {
    set_type x;
    x.insert(2);
    x.insert(3);
    x.insert(4);
    set_type y = x;
    assert(x == y);
    y.erase(3);
    assert(x.size()  == 3);
    assert(x.find(3) == ++x.begin());
    assert(y.size()  == 2);
    assert(y.find(3) == y.end());
    }

    {
    set_type x;
    x.insert(2);
    x.insert(3);
    x.insert(4);
    set_type y;
    y.insert(4);
    y.insert(2);
    y = x;
    assert(x == y);
    y.erase(3);
    assert(x.size()  == 3);
    assert(x.find(3) == ++x.begin());
    assert(y.size()  == 2);
    assert(y.find(3) == y.end());
    }

    {
    set_type x;
    x.insert(2);
    x.insert(3);
    x.insert(4);
    set_type y;
    y.insert(4);
    y.insert(2);
    x.swap(y);
    assert(x.size()  == 2);
    assert(x.find(3) == x.end());
    assert(y.size()  == 3);
    assert(y.find(3) == ++y.begin());
    }

    {
    set_type x;
    x.insert(2);
    x.insert(3);
    x.insert(4);
    assert(*x.find(3) == 3);
//  *x.find(3) = 4;          // doesn't compile
    }

    {
    set_type x;
    pair<iterator, bool> p = x.insert(2);
    assert(p.first  == x.begin());
    assert(p.second == true);
    pair<iterator, bool> q = x.insert(2);
    assert(q.first  == x.begin());
    assert(q.second == false);
    }

    {
    set_type x;
    x.insert(2);
    x.insert(3);
    x.insert(4);
    set_type y;
    y.insert(2);
    y.insert(3);
    y.insert(4);
    assert(x == y);
    assert(x <= y);
    assert(x >= y);
    assert(!(x != y));
    assert(!(x <  y));
    assert(!(x >  y));
    }

    cout << "Done." << endl;
    return 0;}

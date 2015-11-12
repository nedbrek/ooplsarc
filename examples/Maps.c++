// --------
// Maps.c++
// --------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <map>      // map
#include <utility>  // pair

int main () {
    using namespace std;
    cout << "Maps.c++" << endl;

    typedef map<int, int>         map_type;
    typedef map_type::iterator    iterator;
    typedef map_type::mapped_type mapped_type;
    typedef map_type::value_type  value_type;

    {
    map_type x;
    assert(x.empty());
    assert(x.size() == 0);
    }

    {
    map_type x;
    x.insert(value_type(2, 5));
    x.insert(value_type(3, 6));
    x.insert(value_type(4, 7));
    map_type y = x;
    assert(x == y);
    y.erase(3);
    assert(x.size()  == 3);
    assert(x.find(3) == ++x.begin());
    assert(y.size()  == 2);
    assert(y.find(3) == y.end());
    }

    {
    map_type x;
    x.insert(value_type(2, 5));
    x.insert(value_type(3, 6));
    x.insert(value_type(4, 7));
    map_type y;
    y.insert(value_type(4, 7));
    y.insert(value_type(2, 5));
    y = x;
    assert(x == y);
    y.erase(3);
    assert(x.size()  == 3);
    assert(x.find(3) == ++x.begin());
    assert(y.size()  == 2);
    assert(y.find(3) == y.end());
    }

    {
    map_type x;
    x.insert(value_type(2, 5));
    x.insert(value_type(3, 6));
    x.insert(value_type(4, 7));
    map_type y;
    y.insert(value_type(4, 7));
    y.insert(value_type(2, 5));
    x.swap(y);
    assert(x.size()  == 2);
    assert(x.find(3) == x.end());
    assert(y.size()  == 3);
    assert(y.find(3) == ++y.begin());
    }

    {
    map_type x;
    x.insert(value_type(2, 5));
    x.insert(value_type(3, 6));
    x.insert(value_type(4, 7));
    assert(x.find(3)->first  == 3);
//  x.find(3)->first = 4;           // doesn't compile
    assert(x.find(3)->second == 6);
    x.find(3)->second = 7;
    assert(x.find(3)->second == 7);
    }

    {
    map_type x;
    pair<iterator, bool> p = x.insert(value_type(2, 5));
    assert(x.find(2)->second == 5);
    assert(p.first           == x.begin());
    assert(p.second          == true);
    pair<iterator, bool> q = x.insert(value_type(2, 6));
    assert(x.find(2)->second == 5);
    assert(q.first           == x.begin());
    assert(q.second          == false);
    }

    {
    map_type x;
    x.insert(value_type(2, 5));
    x.insert(value_type(3, 6));
    x.insert(value_type(4, 7));
    assert(x[3] == 6);
    x[3] = 7;
    assert(x[3] == 7);
    }

    {
    map_type x;
    x.insert(value_type(2, 5));
    assert(x[3] == mapped_type());
    x[3] = 6;
    assert(x[3] == 6);
    assert(x.size() == 2);
    x[4] = 7;
    assert(x[4] == 7);
    assert(x.size() == 3);
    }

    {
    map_type x;
    x.insert(value_type(2, 5));
    x.insert(value_type(3, 6));
    x.insert(value_type(4, 7));
    map_type y;
    y.insert(value_type(2, 5));
    y.insert(value_type(3, 6));
    y.insert(value_type(4, 7));
    assert(x == y);
    assert(x <= y);
    assert(x >= y);
    assert(!(x != y));
    assert(!(x <  y));
    assert(!(x >  y));
    }

    cout << "Done." << endl;
    return 0;}

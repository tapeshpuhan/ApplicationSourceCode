/*
Task Description
interval_map<K,V> is a data structure that efficiently associates intervals of keys of type K with values of type V. Your task is to implement the assign member function of this data structure, which is outlined below.
interval_map<K, V> is implemented on top of std::map. In case you are not entirely sure which functions std::map provides, what they do and which guarantees they provide, we provide an excerpt of the C++ standard here: 
Each key-value-pair (k,v) in the std::map means that the value v is associated with the interval from k (including) to the next key (excluding) in the std::map.
Example: the std::map (0,'A'), (3,'B'), (5,'A') represents the mapping
0 -> 'A'
1 -> 'A'
2 -> 'A'
3 -> 'B'
4 -> 'B'
5 -> 'A'
6 -> 'A'
7 -> 'A'
... all the way to numeric_limits<int>::max()
The representation in the std::map must be canonical, that is, consecutive map entries must not have the same value: ..., (0,'A'), (3,'A'), ... is not allowed. Initially, the whole range of K is associated with a given initial value, passed to the constructor of the interval_map<K,V> data structure.
Key type K
besides being copyable and assignable, is less-than comparable via operator<
is bounded below, with the lowest value being std::numeric_limits<K>::lowest()
does not implement any other operations, in particular no equality comparison or arithmetic operators
Value type V
besides being copyable and assignable, is equality-comparable via operator==
does not implement any other operations
*/

#include <map>
#include <limits>
#include <ctime>
#include <iostream>
#include <map>
#include <limits>
#include <cassert>
#include <vector>
#include <stdlib.h>
template<typename K, typename V>
class interval_map {
	std::map<K,V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val) {
        m_map.insert(m_map.end(),std::make_pair(std::numeric_limits<K>::lowest(),val));
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
        !( keyBegin < keyEnd )
        {
            return ;
        }
        auto end_index = keyEnd;
        if(keyEnd > std::numeric_limits<K>::max())
        {
            end_index = std::numeric_limits<K>::max();
        }
        for(const auto& interval =  keyBegin; interval < end_index ; ++interval)
        {
            m_map.emplace({interval,val});
        }
        
// INSERT YOUR SOLUTION HERE
    }

    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        return ( --m_map.upper_bound(key) )->second;
    }
   void print_map()
    {
        std::cout<<"\nMap Interval"<<std::endl;
        for(auto& at: m_map)
        {
            std::cout<<at.first<<" : "<<at.second<<std::endl;
        }
    }
};

int main()
{
int value = 30;
interval_map<int, int> obj(value);
obj.print_map();
obj.assign(10,15,100);
    return 0;
}

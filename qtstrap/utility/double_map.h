#ifndef QTSTRAP_UTILITY_DOUBLE_MAP_H
#define QTSTRAP_UTILITY_DOUBLE_MAP_H

#include <map>

namespace qtstrap
{

namespace utl
{

template <typename Key, typename Value, class Container = std::map<Key, Value> >
class double_map
{
public:
    double_map();
}; // class double_map

} // namespace utl

} // namespace qtstrap

#endif // QTSTRAP_UTILITY_DOUBLE_MAP_H

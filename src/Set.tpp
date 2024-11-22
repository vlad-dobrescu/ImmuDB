#include "../include/immutable/Set.h"
#include "../include/immutable/HashMap.h"

template <typename T>
immutable::Set<T>::Set() : map(), setSize(0) {}

template <typename T>
immutable::Set<T>::Set(immutable::HashMap<T,bool> newMap, size_t newSize) : map(newMap), setSize(newSize) {}

template <typename T>
immutable::Set<T>::Set(const Set<T> &other) : map(other.map), setSize(other.setSize) {}

template <typename T>
immutable::Set<T> immutable::Set<T>::insert(const T &value) const {
  if(map.exists(value))
    return *this;

  immutable::HashMap<T,bool> newMap = map.insert(value, true);
  return Set<T>(newMap, setSize + 1);
}

template <typename T>
immutable::Set<T> immutable::Set<T>::del(const T &value) const {
  if(!map.exists(value))
    return *this;

  immutable::HashMap<T,bool> newMap = map.del(value);
  return Set<T>(newMap, setSize - 1);
}

template <typename T>
bool immutable::Set<T>::exists(const T &value) const {
  if(map.exists(value))
    return true;
  else
    return false;
}

template <typename T>
bool immutable::Set<T>::isEmpty() const {
  if(map.isEmpty())
    return true;
  else  
    return false;
}

template <typename T>
size_t immutable::Set<T>::size() const {
    return setSize;
}
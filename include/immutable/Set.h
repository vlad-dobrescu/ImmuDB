#ifndef SET_H
#define SET_H
#include "HashMap.h"

namespace immutable {
  template <typename T>
  class Set {
    public:
      Set();
      Set(const Set<T> &other);

      Set<T> insert(const T& value) const;
      Set<T> del(const T& value) const;
      bool exists(const T& value) const;
      bool isEmpty() const;
      size_t size() const;

    private:
      HashMap<T, bool> map;
      size_t setSize;

      Set(HashMap<T,bool> map, size_t setSize);
  };
}

#include "../../src/Set.tpp"

#endif
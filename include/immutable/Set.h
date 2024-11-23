#ifndef SET_H
#define SET_H
#include <string>
namespace immutable {

  template <typename T>
  class Set {
    public:
      Set();
      Set(const Set<T>& other);

      Set<T> insert(const T& value) const;
      Set<T> del(const T& value) const;
      bool exists(const T& value) const;
      bool isEmpty() const;
      long size() const; 

    private:
      class Node {
        public:
          T value;
          Node* next;

          Node(const T& val) : value(val), next(nullptr) {}
      };

      Node* head;
      size_t setSize;

      Set(Node* h, size_t s);

      Node* copyList(Node* list) const;
    
      void deleteList(Node* list) const;

  };
}

#include "../../src/Set.tpp"

#endif

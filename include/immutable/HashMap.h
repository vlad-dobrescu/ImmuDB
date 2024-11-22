#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <vector>

namespace immutable {
  template <typename K, typename V>
  class HashMap {
    public:
      HashMap();
      HashMap(const HashMap<K,V> & other);
      ~HashMap();

      HashMap<K,V> insert(const K &key, const V &value) const;
      HashMap<K,V> del(const K &key) const;
      V getValue(const K &key) const;
      bool exists(const K &key) const;
      bool isEmpty() const;

    private:
      class Node {
        public:
          K key;
          V value;
          Node* next;

          Node(K k, V v) : key(k), value(v), next(nullptr) {}
      };

      std::vector<Node*> bucketList;
      size_t bucketsCount;
      HashMap(std::vector<Node*> list, size_t count);

      Node* copyList(Node *list) const;
      void deleteList(Node *list) const;
  };
}

#include "../../src/HashMap.tpp"

#endif
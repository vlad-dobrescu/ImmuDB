#ifndef QUEUE_H
#define QUEUE_H
#include <string>
namespace immutable {

  template <typename T>
  class Queue {
    public:
      Queue();
      Queue(const Queue<T> &other);    

      Queue<T> enqueue(const T &value) const;
      Queue<T> dequeue() const;
      T front() const;
      bool isEmpty() const;
    
    private:
      class Node {
        public:
          const T value;
          Node *next;

          Node(const T &val) : value(val), next(nullptr) {}
      };

      Node *frontFirst;
      Node *backFirst;

      Queue(Node *frontList, Node *rearList);
      Node *reverse(Node *node) const;

      Node* copyList(Node* list) const;

  };
}

#include "Queue.tpp"

#endif
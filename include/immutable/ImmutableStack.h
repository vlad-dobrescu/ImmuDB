#ifndef IMMUTABLE_STACK_H
#define IMMUTABLE_STACK_H

namespace immutable {
template <typename T>
class ImmutableStack {
  public:
    ImmutableStack();
    ImmutableStack(const ImmutableStack& other);
    ~ImmutableStack();

    ImmutableStack<T> push(const T &value) const;
    ImmutableStack<T> pop();
    T top() const;
    bool isEmpty();

  private:
    class Node {
      public:
        const T value;
        Node *next;

        Node(const T& val) : value(val), next(nullptr) {}
    };

    Node *topNode;

};

}
#include "../../src/ImmutableStack.tpp"

#endif

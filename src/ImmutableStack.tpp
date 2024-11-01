#include "../include/immutable/ImmutableStack.h"

template <typename T>
immutable::ImmutableStack<T>::ImmutableStack() : topNode(nullptr) {}

template <typename T>
immutable::ImmutableStack<T>::ImmutableStack(const ImmutableStack<T> &other) {
  if( other.topNode == nullptr ) return;

  topNode = new Node( other.topNode->value );

  Node* currThis = topNode;
  Node* currOther = other.topNode->next;

  while( currOther ) {
    currThis->next = new Node( currOther->value );

    currOther = currOther->next;
    currThis = currThis->next;
  }
}

template <typename T>
immutable::ImmutableStack<T>::~ImmutableStack() {
    Node* current = topNode;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

template <typename T>
immutable::ImmutableStack<T> immutable::ImmutableStack<T>::push(const T &value) const {
    Node* newTop = new Node(value);
    newTop->next = topNode;

    immutable::ImmutableStack<T> newStack;
    newStack.topNode = newTop;
    return newStack;
}

template <typename T>
T immutable::ImmutableStack<T>::top() const {
    if (topNode == nullptr) {
        throw std::out_of_range("Stack is empty"); 
    }
    return topNode->value;
}

template <typename T>
immutable::ImmutableStack<T> immutable::ImmutableStack<T>::pop() {
    if (topNode == nullptr) {
        throw std::out_of_range("Stack is empty");
    }

    Node* newTop = topNode->next;
    immutable::ImmutableStack<T> newStack;
    newStack.topNode = newTop;

    return newStack;
}

template <typename T>
bool immutable::ImmutableStack<T>::isEmpty() {
    return topNode == nullptr;
}

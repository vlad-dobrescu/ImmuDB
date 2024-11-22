#include "../include/immutable/Stack.h"

template <typename T>
immutable::Stack<T>::Stack() : topNode(nullptr) {}

template <typename T>
immutable::Stack<T>::Stack(const Stack<T> &other) : topNode(nullptr) {
    if (other.topNode == nullptr)
        return;

    topNode = new Node(other.topNode->value);
    Node *thisNode = topNode;
    Node *otherNode = other.topNode->next;

    while (otherNode) {
        thisNode->next = new Node(otherNode->value);
        thisNode = thisNode->next;
        otherNode = otherNode->next;
    }
}

template <typename T>
immutable::Stack<T>::~Stack() {
    Node *current = topNode;
    while (current) {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

template <typename T>
immutable::Stack<T> immutable::Stack<T>::push(const T &value) const {
    Node *newTop = new Node(value);

    if (topNode != nullptr) {
        Node *current = topNode;
        Node *newCurrent = newTop;

        while (current->next != nullptr) {
            newCurrent->next = new Node(current->next->value);
            newCurrent = newCurrent->next;
            current = current->next;
        }
    }

    Stack<T> newStack;
    newStack.topNode = newTop;
    return newStack;
}


template <typename T>
immutable::Stack<T> immutable::Stack<T>::pop() const {
    if (topNode == nullptr) {
        throw std::out_of_range("Stack is empty");
    }

    Stack<T> newStack;
    if (topNode->next != nullptr) {
        newStack.topNode = new Node(topNode->next->value);
        Node *current = topNode->next->next;
        Node *newCurrent = newStack.topNode;

        while (current) {
            newCurrent->next = new Node(current->value);
            newCurrent = newCurrent->next;
            current = current->next;
        }
    } else {
        newStack.topNode = nullptr;  
    }
    return newStack;
}


template <typename T>
T immutable::Stack<T>::top() const {
    if (topNode == nullptr) {
        throw std::out_of_range("Stack is empty");
    }
    return topNode->value;
}

template <typename T>
bool immutable::Stack<T>::isEmpty() const {
    return topNode == nullptr;
}

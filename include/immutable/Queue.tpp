#include "Queue.h"
#include <stdexcept>
#include <iostream>

template <typename T>
immutable::Queue<T>::Queue() : frontFirst(nullptr), backFirst(nullptr) {}

template <typename T>
immutable::Queue<T>::Queue(const Queue<T>& other) : frontFirst(copyList(other.frontFirst)), backFirst(copyList(other.backFirst)) {}

template <typename T>
immutable::Queue<T>::Queue(Node* frontList, Node* rearList)
    : frontFirst(frontList), backFirst(rearList) {}

template <typename T>
typename immutable::Queue<T>::Node* immutable::Queue<T>::copyList(Node* list) const {
    if (!list) {
        return nullptr;
    }

    Node* head = new Node(list->value);
    Node* current = head;
    Node* temp = list->next;

    while (temp) {
        current->next = new Node(temp->value);
        current = current->next;
        temp = temp->next;
    }

    return head;
}

template <typename T>
typename immutable::Queue<T>::Node* immutable::Queue<T>::reverse(Node* node) const {
    Node* prev = nullptr;
    while (node) {
        Node* newNode = new Node(node->value);
        newNode->next = prev;
        prev = newNode;
        node = node->next;
    }
    return prev;
}

template <typename T>
immutable::Queue<T> immutable::Queue<T>::enqueue(const T& value) const {
    Node* newNode = new Node(value);

    if (isEmpty()) {
        return Queue(newNode, nullptr);
    }

    Node* newBack = new Node(value);
    newBack->next = backFirst;

    return Queue(copyList(frontFirst), newBack);
}

template <typename T>
immutable::Queue<T> immutable::Queue<T>::dequeue() const {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }

    if (frontFirst) {
        return Queue(frontFirst->next, copyList(backFirst));
    }

    Node* reversedBack = reverse(backFirst);
    return Queue(reversedBack->next, nullptr);
}

template <typename T>
T immutable::Queue<T>::front() const {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }

    if (frontFirst) {
        return frontFirst->value;
    }

    Node* reversedBack = reverse(backFirst);
    T frontValue = reversedBack->value;
    delete reversedBack;
    return frontValue;
}

template <typename T>
bool immutable::Queue<T>::isEmpty() const {
    return frontFirst == nullptr && backFirst == nullptr;
}
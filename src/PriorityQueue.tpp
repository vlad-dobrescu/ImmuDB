#include "../include/immutable/PriorityQueue.h"
#include <stdexcept>

template <typename T>
immutable::PriorityQueue<T>::PriorityQueue() : head(nullptr) {}

template <typename T>
immutable::PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& other) 
    : head(copyList(other.head)) {}

template <typename T>
immutable::PriorityQueue<T>::~PriorityQueue() {
    delete head;
}

template <typename T>
immutable::PriorityQueue<T>::PriorityQueue(Node* newHead) : head(newHead) {}

template <typename T>
typename immutable::PriorityQueue<T>::Node* immutable::PriorityQueue<T>::copyList(Node* list) const {
    if (!list) return nullptr;

    Node* head = new Node(list->value, nullptr);
    Node* newList = head;
    Node* oldList = list->next;

    while (oldList) {
        newList->next = new Node(oldList->value, nullptr);
        newList = newList->next;
        oldList = oldList->next;
    }
    return head;
}

template <typename T>
immutable::PriorityQueue<T> immutable::PriorityQueue<T>::insert(const T& value) const {
    Node* newHead = nullptr;
    Node* newNode = new Node(value, nullptr);
    Node* current = head;

    if (!current || value < current->value) {
        newNode->next = current;
        newHead = newNode;
    } else {
        newHead = new Node(current->value, nullptr);
        Node* newCurrent = newHead;

        while (current->next && current->next->value <= value) {
            newCurrent->next = new Node(current->next->value, nullptr);
            current = current->next;
            newCurrent = newCurrent->next;
        }

        newNode->next = current->next;
        newCurrent->next = newNode;
    }

    return PriorityQueue<T>(newHead);
}

template <typename T>
immutable::PriorityQueue<T> immutable::PriorityQueue<T>::removeMin() const {
    if (!head) {
        throw std::out_of_range("PriorityQueue is empty");
    }

    Node* newHead = copyList(head->next);
    return PriorityQueue<T>(newHead);
}

template <typename T>
T immutable::PriorityQueue<T>::peekMin() const {
    if (!head) {
        throw std::out_of_range("PriorityQueue is empty");
    }
    return head->value;
}

template <typename T>
bool immutable::PriorityQueue<T>::isEmpty() const {
    return head == nullptr;
}

#include "Set.h"
#include <iostream>

template <typename T>
immutable::Set<T>::Set() : head(nullptr), setSize(0) {}

template <typename T>
immutable::Set<T>::Set(const Set<T>& other) : head(copyList(other.head)), setSize(other.setSize) {}

template <typename T>
immutable::Set<T>::Set(Node* head, size_t setSize) : head(head), setSize(setSize) {}

template <typename T>
immutable::Set<T> immutable::Set<T>::insert(const T& value) const {
    if (exists(value)) {
        return *this;
    }

    Node* newHead = new Node(value);
    newHead->next = head;
    return Set(newHead, setSize + 1);
}

template <typename T>
bool immutable::Set<T>::exists(const T& value) const {
    Node* current = head;
    while (current) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
immutable::Set<T> immutable::Set<T>::del(const T& value) const {
    if (!exists(value)) {
        return *this;
    }

    Node* newHead = nullptr;
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        if (current->value == value) {
            if (prev) {
                prev->next = current->next;
            } else {
                newHead = current->next;
            }
            delete current;
            break;
        }

        prev = current;
        current = current->next;
    }

    return Set(head, setSize - 1);
}

template <typename T>
bool immutable::Set<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
long immutable::Set<T>::size() const {
    return setSize;
}

template <typename T>
typename immutable::Set<T>::Node* immutable::Set<T>::copyList(Node* list) const {
    if (!list) {
        return nullptr;
    }

    Node* newHead = new Node(list->value);
    Node* current = newHead;
    Node* temp = list->next;

    while (temp) {
        current->next = new Node(temp->value);
        current = current->next;
        temp = temp->next;
    }

    return newHead;
}

template <typename T>
void immutable::Set<T>::deleteList(Node* list) const {
    while (list) {
        Node* temp = list->next;
        delete list;
        list = temp;
    }
}

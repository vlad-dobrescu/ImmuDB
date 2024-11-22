#include "../include/immutable/Queue.h"

template <typename T>
immutable::Queue<T>::Queue() : frontFirst(nullptr), backFirst(nullptr) {}

template <typename T>
immutable::Queue<T>::Queue(const Queue<T> &other) : frontFirst(nullptr), backFirst(nullptr) {
    
    if (other.frontFirst != nullptr) {
        frontFirst = new Node(other.frontFirst->value);
        Node *thisNode = frontFirst;
        Node *otherNode = other.frontFirst->next;

        while (otherNode) {
            thisNode->next = new Node(otherNode->value);
            thisNode = thisNode->next;
            otherNode = otherNode->next;
        }
    }

    if (other.backFirst != nullptr) {
        backFirst = new Node(other.backFirst->value);
        Node *thisNode = backFirst;
        Node *otherNode = other.backFirst->next;

        while (otherNode) {
            thisNode->next = new Node(otherNode->value);
            thisNode = thisNode->next;
            otherNode = otherNode->next;
        }
    }
}

template <typename T>
immutable::Queue<T>::~Queue() {
    Node *current = frontFirst;
    while (current) {
        Node *next = current->next;
        delete current;
        current = next;
    }

    current = backFirst;
    while (current) {
        Node *next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
immutable::Queue<T>::Queue(Node *frontList, Node *rearList)
    : frontFirst(frontList), backFirst(rearList) {}

template <typename T>
immutable::Queue<T> immutable::Queue<T>::enqueue(const T &value) const {
    Node *newBack = new Node(value);
    if (backFirst == nullptr) {
        return Queue(frontFirst, newBack);
    } else {
        Node *newBackFirst = new Node(backFirst->value);
        Node *current = newBackFirst;
        Node *other = backFirst->next;

        while (other) {
            current->next = new Node(other->value);
            current = current->next;
            other = other->next;
        }

        current->next = newBack;
        return Queue(frontFirst, newBackFirst);
    }
}

template <typename T>
immutable::Queue<T> immutable::Queue<T>::dequeue() const {
    if (frontFirst == nullptr && backFirst == nullptr) {
        throw std::out_of_range("Queue is empty");
    }

    if (frontFirst != nullptr) {
        Node *newFront = frontFirst->next;
        return Queue(newFront, backFirst);
    } else {
        Node *reversedBack = reverse(backFirst);
        return Queue(reversedBack->next, nullptr);
    }
}

template <typename T>
T immutable::Queue<T>::front() const {
    if (frontFirst == nullptr && backFirst == nullptr) {
        throw std::out_of_range("Queue is empty");
    }

    if (frontFirst != nullptr) {
        return frontFirst->value;
    }

    Node *reversedBack = reverse(backFirst);
    return reversedBack->value;
}

template <typename T>
bool immutable::Queue<T>::isEmpty() const {
    return frontFirst == nullptr && backFirst == nullptr;
}

template <typename T>
typename immutable::Queue<T>::Node *immutable::Queue<T>::reverse(Node *node) const {
    Node *prev = nullptr;
    while (node != nullptr) {
        Node *nextNode = node->next;
        Node *newNode = new Node(node->value);
        newNode->next = prev;
        prev = newNode;
        node = nextNode;
    }
    return prev;
}
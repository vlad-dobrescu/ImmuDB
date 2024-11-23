#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

namespace immutable {

template <typename T>
class PriorityQueue {
public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue<T>& other);
    ~PriorityQueue();

    PriorityQueue<T> insert(const T& value) const;
    PriorityQueue<T> removeMin() const;
    T peekMin() const;
    bool isEmpty() const;

private:
    class Node {
    public:
        T value;
        Node* next;

        Node(const T& val, Node* nxt) : value(val), next(nxt) {}
    };

    Node* head;

    PriorityQueue(Node* newHead);

    Node* copyList(Node* list) const;
    void deleteList(Node* list) const;
};

} 

#include "PriorityQueue.tpp"

#endif

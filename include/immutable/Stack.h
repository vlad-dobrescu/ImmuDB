#ifndef STACK_H
#define STACK_H

namespace immutable {

template <typename T>
class Stack {
public:
    Stack();
    Stack(const Stack &other);
    ~Stack();

    Stack<T> push(const T &value) const;
    Stack<T> pop() const;
    T top() const;        
    bool isEmpty() const;

private:
    class Node {
    public:
        const T value;
        Node *next;

        Node(const T &val) : value(val), next(nullptr) {}
    };

    Node *topNode;             
};

} 

#include "../../src/Stack.tpp"

#endif

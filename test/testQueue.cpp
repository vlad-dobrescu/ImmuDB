#include <iostream>
#include "../include/immutable/Queue.h"

int main() {
    immutable::Queue<int> queue;

    immutable::Queue<int> queue1 = queue.enqueue(10);
    immutable::Queue<int> queue2 = queue1.enqueue(20);
    immutable::Queue<int> queue3 = queue2.enqueue(30);

    std::cout << "Front of queue3: " << queue3.front() << std::endl;
    std::cout << "Front of queue2: " << queue2.front() << std::endl;
    std::cout << "Front of queue1: " << queue1.front() << std::endl;

    immutable::Queue<int> queue4 = queue3.dequeue();
    std::cout << "Front of queue4 (after dequeue): " << queue4.front() << std::endl;
    std::cout << "Front of queue3 (unchanged): " << queue3.front() << std::endl;

    std::cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}

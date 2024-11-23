#include <gtest/gtest.h>
#include "../include/immutable/Queue.h"

// Test: Enqueue and Front
TEST(QueueTest, EnqueueAndFront) {
    immutable::Queue<int> queue;
    immutable::Queue<int> queue1 = queue.enqueue(10);
    immutable::Queue<int> queue2 = queue1.enqueue(20);
    immutable::Queue<int> queue3 = queue2.enqueue(30);

    EXPECT_EQ(queue3.front(), 10); 
    EXPECT_EQ(queue2.front(), 10); 
    EXPECT_EQ(queue1.front(), 10); 
}

// Test: Dequeue and Front
TEST(QueueTest, DequeueAndFront) {
    immutable::Queue<int> queue;
    immutable::Queue<int> queue1 = queue.enqueue(10);
    immutable::Queue<int> queue2 = queue1.enqueue(20);
    immutable::Queue<int> queue3 = queue2.enqueue(30);

    immutable::Queue<int> queue4 = queue3.dequeue();
    EXPECT_EQ(queue4.front(), 20); 
    EXPECT_EQ(queue3.front(), 10); 

    immutable::Queue<int> queue5 = queue4.dequeue();
    EXPECT_EQ(queue5.front(), 30); 
}

// Test: IsEmpty
TEST(QueueTest, IsEmpty) {
    immutable::Queue<int> queue;
    EXPECT_TRUE(queue.isEmpty()); 

    immutable::Queue<int> queue1 = queue.enqueue(10);
    EXPECT_FALSE(queue1.isEmpty());

    immutable::Queue<int> queue2 = queue1.dequeue();
    EXPECT_TRUE(queue2.isEmpty()); 
}

// Test: Front on Empty Queue
TEST(QueueTest, FrontOnEmptyQueue) {
    immutable::Queue<int> queue;
    EXPECT_THROW(queue.front(), std::out_of_range); // Accessing front on empty queue should throw
}

// Test: Dequeue on Empty Queue
TEST(QueueTest, DequeueOnEmptyQueue) {
    immutable::Queue<int> queue;
    EXPECT_THROW(queue.dequeue(), std::out_of_range); // Dequeuing from an empty queue should throw
}

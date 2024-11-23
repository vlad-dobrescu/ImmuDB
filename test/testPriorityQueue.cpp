#include "../include/immutable/PriorityQueue.h"
#include <gtest/gtest.h>

TEST(PriorityQueueTest, InsertAndPeekMin) {
    immutable::PriorityQueue<int> pq;
    auto pq1 = pq.insert(10);
    auto pq2 = pq1.insert(5);
    auto pq3 = pq2.insert(20);
    auto pq4 = pq3.insert(15);

    EXPECT_EQ(pq4.peekMin(), 5);
}

TEST(PriorityQueueTest, RemoveMin) {
    immutable::PriorityQueue<int> pq;
    auto pq1 = pq.insert(10);
    auto pq2 = pq1.insert(5);
    auto pq3 = pq2.insert(20);
    auto pq4 = pq3.insert(15);
    auto pq5 = pq4.removeMin();

    EXPECT_EQ(pq5.peekMin(), 10);
}

TEST(PriorityQueueTest, IsEmpty) {
    immutable::PriorityQueue<int> pq;
    EXPECT_TRUE(pq.isEmpty());

    auto pq1 = pq.insert(10);
    EXPECT_FALSE(pq1.isEmpty());
}


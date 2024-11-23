#include <iostream>
#include "../include/immutable/HashMap.h"
#include <gtest/gtest.h>

// Test: Insert and Retrieve Values
TEST(HashMapTest, InsertAndRetrieve) {
    immutable::HashMap<std::string, int> map;
    auto map1 = map.insert("Alice", 30);
    auto map2 = map1.insert("Bob", 25);

    EXPECT_EQ(map2.getValue("Alice"), 30);
    EXPECT_EQ(map2.getValue("Bob"), 25);
    EXPECT_THROW(map2.getValue("Charlie"), std::out_of_range);
}

// Test: Update Existing Key
TEST(HashMapTest, UpdateKey) {
    immutable::HashMap<std::string, int> map;
    auto map1 = map.insert("Alice", 30);
    auto map2 = map1.insert("Alice", 40);

    EXPECT_EQ(map2.getValue("Alice"), 40);
}

// Test: Existence of Keys
TEST(HashMapTest, KeyExistence) {
    immutable::HashMap<std::string, int> map;
    auto map1 = map.insert("Alice", 30);
    auto map2 = map1.insert("Bob", 25);

    EXPECT_TRUE(map2.exists("Alice"));
    EXPECT_TRUE(map2.exists("Bob"));
    EXPECT_FALSE(map2.exists("Charlie"));
}

// Test: Deletion of Key
TEST(HashMapTest, DeleteKey) {
    immutable::HashMap<std::string, int> map;
    auto map1 = map.insert("Alice", 30);
    auto map2 = map1.del("Alice");

    EXPECT_FALSE(map2.exists("Alice"));
    EXPECT_THROW(map2.getValue("Alice"), std::out_of_range);
}

// Test: IsEmpty
TEST(HashMapTest, IsEmpty) {
    immutable::HashMap<std::string, int> map;
    EXPECT_TRUE(map.isEmpty());

    auto map1 = map.insert("Alice", 30);
    EXPECT_FALSE(map1.isEmpty());
}

#include <gtest/gtest.h>
#include "../include/immutable/Set.h"

TEST(SetTest, InsertAndExists) {
    immutable::Set<int> set;
    immutable::Set<int> set1 = set.insert(10);
    immutable::Set<int> set2 = set1.insert(20);
    immutable::Set<int> set3 = set2.insert(30);
    immutable::Set<int> set4 = set3.del(20);

    EXPECT_TRUE(set4.exists(10));
    EXPECT_FALSE(set4.exists(20));
    EXPECT_TRUE(set4.exists(30));
}

TEST(SetTest, Size) {
    immutable::Set<int> set;
    immutable::Set<int> set1 = set.insert(10);
    immutable::Set<int> set2 = set1.insert(20);
    immutable::Set<int> set3 = set2.insert(30);
    immutable::Set<int> set4 = set3.del(20);

    EXPECT_EQ(set4.size(), 2);
}

TEST(SetTest, Immutability) {
    immutable::Set<int> set;
    immutable::Set<int> set1 = set.insert(10); 
    immutable::Set<int> set2 = set1.insert(20);
    immutable::Set<int> set3 = set2.insert(30);
    immutable::Set<int> set4 = set3.del(20);   

    EXPECT_TRUE(set1.exists(10));        
    EXPECT_FALSE(set1.exists(20));       
    EXPECT_EQ(set1.size(), 1);           

    EXPECT_FALSE(set3.exists(20));       
    EXPECT_EQ(set3.size(), 3);           
}

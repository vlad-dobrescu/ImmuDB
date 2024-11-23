#include <gtest/gtest.h>
#include "../include/immutable/Stack.h"

TEST(StackTest, PushAndTop) {
    immutable::Stack<int> stack;
    
    // Pushing elements onto the stack
    immutable::Stack<int> stack1 = stack.push(10);
    immutable::Stack<int> stack2 = stack1.push(20);
    immutable::Stack<int> stack3 = stack2.push(30);

    // Test top of the stack
    EXPECT_EQ(stack3.top(), 30);
    EXPECT_EQ(stack2.top(), 20);
    EXPECT_EQ(stack1.top(), 10);
}

TEST(StackTest, PopAndTop) {
    immutable::Stack<int> stack;
    
    // Pushing elements onto the stack
    immutable::Stack<int> stack1 = stack.push(10);
    immutable::Stack<int> stack2 = stack1.push(20);
    immutable::Stack<int> stack3 = stack2.push(30);

    // Pop from the stack
    immutable::Stack<int> stack4 = stack3.pop();

    // Check top element after popping
    EXPECT_EQ(stack4.top(), 20); 
    EXPECT_NE(stack3.top(), stack4.top()); 
}

TEST(StackTest, IsEmpty) {
    immutable::Stack<int> stack;

    // Check if the stack is empty
    EXPECT_TRUE(stack.isEmpty());

    // Push an element onto the stack
    immutable::Stack<int> stack1 = stack.push(10);
    EXPECT_FALSE(stack1.isEmpty());

    // Pop the element and check again
    immutable::Stack<int> stack2 = stack1.pop();
    EXPECT_TRUE(stack2.isEmpty());
}

TEST(StackTest, TopOnEmptyStack) {
    immutable::Stack<int> stack;

    // Test that top throws an exception when stack is empty
    EXPECT_THROW(stack.top(), std::out_of_range);
}

TEST(StackTest, PopOnEmptyStack) {
    immutable::Stack<int> stack;

    // Test that pop throws an exception when stack is empty
    EXPECT_THROW(stack.pop(), std::out_of_range);
}

#include <iostream>
#include "../include/immutable/ImmutableStack.h"

int main() {
    // Step 1: Create an original stack and push elements
    immutable::ImmutableStack<int> originalStack;
    originalStack = originalStack.push(10);
    originalStack = originalStack.push(20);
    originalStack = originalStack.push(30);

    // Step 2: Create a copy of the original stack
    immutable::ImmutableStack<int> copiedStack = originalStack;

    // Step 3: Verify that both stacks have the same top element
    std::cout << "Original stack top: " << originalStack.top() << std::endl;
    std::cout << "Copied stack top: " << copiedStack.top() << std::endl;

    // Check if the top elements are equal
    if (originalStack.top() == copiedStack.top()) {
        std::cout << "Copy constructor test passed: Tops are the same after copying." << std::endl;
    } else {
        std::cout << "Copy constructor test failed: Tops are different after copying." << std::endl;
    }

    // Step 4: Pop an element from the original stack and check that the copied stack is unchanged
    originalStack = originalStack.pop();
    std::cout << "After popping from original stack..." << std::endl;
    std::cout << "New original stack top: " << originalStack.top() << std::endl;
    std::cout << "Copied stack top remains: " << copiedStack.top() << std::endl;

    // Verify that the copied stack's top is still the original top
    if (copiedStack.top() == 30) {
        std::cout << "Independence test passed: Copied stack remains unchanged." << std::endl;
    } else {
        std::cout << "Independence test failed: Copied stack changed after modifying original stack." << std::endl;
    }

    return 0;
}

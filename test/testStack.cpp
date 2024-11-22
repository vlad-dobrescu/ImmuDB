#include <iostream>
#include "../include/immutable/Stack.h"

int main() {
    immutable::Stack<int> stack;

    immutable::Stack<int> stack1 = stack.push(10);
    immutable::Stack<int> stack2 = stack1.push(20);
    immutable::Stack<int> stack3 = stack2.push(30);

    std::cout << "Top of stack3: " << stack3.top() << std::endl;
    std::cout << "Top of stack2: " << stack2.top() << std::endl;
    std::cout << "Top of stack1: " << stack1.top() << std::endl;

    immutable::Stack<int> stack4 = stack3.pop();
    if (!stack4.isEmpty()) {
        std::cout << "Top of stack4 (after popping): " << stack4.top() << std::endl;
    } else {
        std::cout << "Stack4 is empty after popping." << std::endl;
    }

    std::cout << "Top of stack3 (unchanged): " << stack3.top() << std::endl;
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}

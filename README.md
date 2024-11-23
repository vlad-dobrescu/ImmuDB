# ImmuDS: Immutable Data Structures Library

**Version**: 1.0.0  
**License**: MIT  
**Author**: Vlad Dobrescu <dobrescu.vlad10@gmail.com>  

ImmuDS is a C++ library providing immutable data structures for safe and functional-style programming. The library supports the creation and manipulation of immutable stacks, sets, queues, hashmaps, and priority queues.

---

## **Features**
### **Stack**
- **push**: Creates a new stack with a new top node.  
  *Usage*: `stack = stack.push(value);`
- **top**: Returns the value of the top node.  
  *Usage*: `stack.top();`
- **pop**: Returns a new stack without the previous top node.  
  *Usage*: `stack = stack.pop();`
- **isEmpty**: Checks if the stack is empty.  
  *Usage*: `stack.isEmpty();`
- **Constructor**: Initializes an empty stack.  
  *Usage*: `immutable::Stack<int> stack;`
- **Copy Constructor**: Deep copies a stack into a new one.  
  *Usage*: `immutable::Stack<int> newStack = oldStack;`
- **Destructor**: Ensures proper cleanup without recursive deletion, maintaining immutability.

---

## **Getting Started**

### **Install the Library**
#### Using Conan
1. Add the remote to Conan:
   ```bash
   conan remote add your_artifactory "https://trialzxzkyv.jfrog.io/artifactory/api/conan/first-conan"
   conan user -p <your_password_or_token> -r your_artifactory <your_username>
   ```

2. Install the library in your project:
   - Add the following to your `conanfile.txt`:
     ```txt
     [requires]
     immuds/1.0.0@vlad/stable

     [generators]
     CMakeDeps
     CMakeToolchain
     ```
   - Run:
     ```bash
     conan install . --build=missing
     ```

---

## **Example Usage**

### **CMake Project**
**1. Create a `CMakeLists.txt`**
```cmake
cmake_minimum_required(VERSION 3.15)
project(ExampleProject)

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

find_package(immuds REQUIRED)

add_executable(example main.cpp)
target_link_libraries(example PRIVATE immuds::immuds)
```

**2. Write Your Code in `main.cpp`**
```cpp
#include <immutable/Stack.h>
#include <iostream>

int main() {
    // Initialize the stack
    immutable::Stack<int> stack;

    // Push values onto the stack
    stack = stack.push(10).push(20).push(30);

    // Access and print the top value
    std::cout << "Top of stack: " << stack.top() << std::endl;

    // Pop a value off the stack
    stack = stack.pop();
    std::cout << "New top after pop: " << stack.top() << std::endl;

    // Check if the stack is empty
    if (stack.isEmpty()) {
        std::cout << "The stack is empty." << std::endl;
    } else {
        std::cout << "The stack is not empty." << std::endl;
    }

    return 0;
}
```

**3. Build and Run the Project**
- Run the following commands:
  ```bash
  mkdir build && cd build
  cmake ..
  cmake --build .
  ./example
  ```

---

## **Contributing**
Contributions are welcome! Please submit a pull request or open an issue if you find any bugs or have suggestions for improvements.

## **License**
This project is licensed under the MIT License. See the `LICENSE` file for details.

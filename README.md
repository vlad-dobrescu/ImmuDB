# **ImmuDS: Immutable Data Structures Library**

**Version**: 1.0.0  
**License**: MIT  
**Author**: Vlad Dobrescu  

**ImmuDS** is a modern C++ library offering immutable data structures for functional-style and thread-safe programming. It includes efficient and easy-to-use implementations of **stacks**, **sets**, **queues**, **hashmaps**, and **priority queues**.

---

## **Available Data Structures and Methods**

| **Data Structure**   | **Methods**                                                                                  |
|-----------------------|---------------------------------------------------------------------------------------------|
| **Stack**             | `push(const T& value)`, `pop()`, `top()`, `isEmpty()`, `Constructor`, `Copy Constructor`    |
| **Queue**             | `enqueue(const T& value)`, `dequeue()`, `front()`, `isEmpty()`, `Constructor`, `Copy Constructor` |
| **HashMap**           | `insert(const K& key, const V& value)`, `del(const K& key)`, `getValue(const K& key)`, `exists(const K& key)`, `isEmpty()`, `Constructor`, `Copy Constructor` |
| **Set**               | `insert(const T& value)`, `del(const T& value)`, `exists(const T& value)`, `isEmpty()`, `size()`, `Constructor`, `Copy Constructor` |
| **PriorityQueue**     | `insert(const T& value)`, `removeMin()`, `peekMin()`, `isEmpty()`, `Constructor`, `Copy Constructor` |

---

## **Installation Options**

### **Option 1: Using Conan Package Manager**

#### **Step 1: Add Conan Remote**
```bash
conan remote add your_artifactory "https://trialzxzkyv.jfrog.io/artifactory/api/conan/first-conan"
conan user -p <your_password_or_token> -r your_artifactory <your_username>
```

#### **Step 2: Install the Library**
Add the following to your `conanfile.txt`:
```txt
[requires]
immuds/1.0.0@vlad/stable

[generators]
CMakeDeps
CMakeToolchain
```

Run:
```bash
conan install . --build=missing
```

#### **Step 3: Use in a CMake Project**
Create a `CMakeLists.txt`:
```cmake
cmake_minimum_required(VERSION 3.15)
project(ExampleProject)

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

find_package(immuds REQUIRED)

add_executable(example main.cpp)
target_link_libraries(example PRIVATE immuds::immuds)
```

#### **Step 4: Write Your Code (`main.cpp`)**
```cpp
#include <immutable/Stack.h>
#include <iostream>

int main() {
    // Initialize the stack
    immutable::Stack<int> stack;

    // Push values onto the stack
    stack = stack.push(10);
    stack = stack.push(30);

    // Access and print the top value
    std::cout << "Top of stack: " << stack.top() << std::endl;

    // Pop a value off the stack
    stack = stack.pop();
    std::cout << "New top after pop: " << stack.top() << std::endl;

    return 0;
}
```

#### **Step 5: Build and Run**
Run the following commands:
```bash
mkdir build && cd build
cmake ..
cmake --build .
./example
```

---

### **Option 2: Clone and Use Without a Package Manager**

#### **Step 1: Clone the Repository**
```bash
git clone https://github.com/vlad-dobrescu/ImmuDS.git
```

#### **Step 2: Include Headers in Your Project**
Directly add the `include/` directory to your compiler's include path.

#### **Step 3: Compile Your Code**
Here’s an example of compiling a project with `g++`:
```bash
g++ -std=c++11 -I/path/to/ImmuDS/include main.cpp -o example
./example
```

---

## **Unit Testing**
Unit tests are available in the `/test` directory and are written using the **GoogleTest framework**. To run the tests:

1. Ensure GoogleTest is installed or add it to your project as a submodule:
   ```bash
   git submodule add https://github.com/google/googletest.git test/googletest
   ```

2. Build and run the tests:
   ```bash
   mkdir test_build && cd test_build
   cmake ../test
   cmake --build .
   ./runTests
   ```

---

## **Contributing**
Contributions are welcome! Please submit a pull request or open an issue if you find any bugs or have suggestions for improvements.

## **License**
This project is licensed under the MIT License. See the `LICENSE` file for details.

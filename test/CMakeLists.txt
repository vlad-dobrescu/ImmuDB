# Manually add all test source files in the test directory
set(TEST_SOURCES
    "${CMAKE_SOURCE_DIR}/test/testMap.cpp"
    "${CMAKE_SOURCE_DIR}/test/testPriorityQueue.cpp"
    "${CMAKE_SOURCE_DIR}/test/testQueue.cpp"
    "${CMAKE_SOURCE_DIR}/test/testSet.cpp"
    "${CMAKE_SOURCE_DIR}/test/testStack.cpp"
)

# Create the executable for the tests
add_executable(runTests ${TEST_SOURCES})

# Find the GTest package
find_package(GTest REQUIRED)

# Link the tests with the ImmuDS library and GTest
target_link_libraries(runTests PRIVATE ImmuDS GTest::GTest GTest::Main)

# Enable testing
include_directories(${GTEST_INCLUDE_DIRS})

# Register the test with CTest
add_test(NAME runTests COMMAND runTests)

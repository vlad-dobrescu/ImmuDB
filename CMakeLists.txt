cmake_minimum_required(VERSION 3.10)

# Project name and version
project(ImmuDS VERSION 1.0.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Add source files for the ImmuDS static library
set(SRC_FILES
    src/HashMap.tpp
    src/PriorityQueue.tpp
    src/Queue.tpp
    src/Set.tpp
    src/Stack.tpp
    src/HashMap.cpp
    src/PriorityQueue.cpp
    src/Queue.cpp
    src/Set.cpp
    src/Stack.cpp
)

# Create the static library
add_library(ImmuDS STATIC ${SRC_FILES})

# Install target
install(TARGETS ImmuDS DESTINATION lib)

# Install the headers
install(DIRECTORY include/immutable DESTINATION include)

# Ensure CMake knows to use the C++ linker for the static library
set_target_properties(ImmuDS PROPERTIES LINKER_LANGUAGE CXX)

# Package configuration
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_BINARY_DIR}/ImmuDSConfigVersion.cmake"
    VERSION 1.0.0
    COMPATIBILITY AnyNewerVersion
)

# Install package configuration files
install(FILES "${CMAKE_BINARY_DIR}/ImmuDSConfigVersion.cmake"
        DESTINATION lib/cmake/ImmuDS)



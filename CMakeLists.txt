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
    include/immutable/HashMap.tpp
    include/immutable/PriorityQueue.tpp
    include/immutable/Queue.tpp
    include/immutable/Set.tpp
    include/immutable/Stack.tpp
    include/immutable/HashMap.cpp
    include/immutable/PriorityQueue.cpp
    include/immutable/Queue.cpp
    include/immutable/Set.cpp
    include/immutable/Stack.cpp
)

# Create the static library
add_library(ImmuDS STATIC ${SRC_FILES})

# Ensure CMake knows to use the C++ linker for the static library
set_target_properties(ImmuDS PROPERTIES LINKER_LANGUAGE CXX)


install(DIRECTORY include/immutable DESTINATION include FILES_MATCHING PATTERN "*.h" PATTERN "*.tpp")


# Install the static library
install(TARGETS ImmuDS
        EXPORT ImmuDSTargets
        DESTINATION lib)

# Install the CMake package configuration files
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${CMAKE_BINARY_DIR}/ImmuDSConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/ImmuDSConfig.cmake.in
    ${CMAKE_BINARY_DIR}/ImmuDSConfig.cmake
    @ONLY
)

install(FILES
    "${CMAKE_BINARY_DIR}/ImmuDSConfig.cmake"
    "${CMAKE_BINARY_DIR}/ImmuDSConfigVersion.cmake"
    DESTINATION lib/cmake/ImmuDS
)

install(EXPORT ImmuDSTargets
        FILE ImmuDSTargets.cmake
        NAMESPACE ImmuDS::
        DESTINATION lib/cmake/ImmuDS)

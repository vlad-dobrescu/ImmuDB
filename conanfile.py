from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps
from conan.tools.files import copy

class ImmuDS(ConanFile):
    name = "immuds"
    version = "1.0.0"
    license = "MIT"
    author = "Vlad Dobrescu <dobrescu.vlad10@gmail.com>"
    url = "https://github.com/vlad-dobrescu/ImmuDS"
    description = "A C++ library of immutable data structures"
    topics = ("c++", "immutable", "data structures")
    settings = "os", "compiler", "build_type", "arch"
    requires = "gtest/1.10.0"  
    generators = "CMakeToolchain", "CMakeDeps"
    
    def layout(self):
        self.folders.build = "build"
        self.folders.generators = "build/generators"

    def source(self):
        copy(self, "*", self.source_folder, self.build_folder)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["ImmuDS"]

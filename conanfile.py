from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps
from conan.tools.files import copy, export_conandata_patches, get

class ImmuDS(ConanFile):
    name = "immuds"
    version = "1.0.0"
    license = "MIT"
    author = "Vlad Dobrescu <dobrescu.vlad10@gmail.com>"
    url = "https://github.com/vlad-dobrescu/ImmuDS"
    description = "A C++ library of immutable data structures"
    topics = ("c++", "immutable", "data structures")
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"
    
    def layout(self):
        self.folders.build = "build"
        self.folders.generators = "build/generators"
        self.folders.source = "."


    def source(self):
        get(self, url="https://github.com/vlad-dobrescu/ImmuDS/archive/refs/heads/main.zip", strip_root=True)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["ImmuDS"]

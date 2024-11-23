from conan import ConanFile
from conan.tools.cmake import CMake

print(ConanFile)
class ImmuDS(ConanFile):
    name = "immuds"
    version = "1.0.0"
    license = "MIT"
    author = "Vlad Dobrescu <dobrescu.vlad10@gmail.com>"
    url = "https://github.com/yourusername/ImmuDS"
    description = "A C++ library of immutable data structures"
    topics = ("c++", "immutable", "data structures")
    settings = "os", "compiler", "build_type", "arch" 
    generators = "cmake"
    
    def source(self):
        self.run("git clone https://github.com/vlad-dobrescu/ImmuDS.git")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["ImmuDS"]

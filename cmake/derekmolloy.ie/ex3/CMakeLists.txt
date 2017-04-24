cmake_minimum_required(VERSION 2.8.9)
project(directory_test)
set(CMAKE_BUILD_TYPE Release)

# bring the heahders, such as Student.h into the project
include_directories(include)

# however, the file(GLOB...) allows for wildcards additions:
file(GLOB SOURCES "src/*.cpp")

# generate the shared library from the sources
add_library(testStudent SHARED ${SOURCES})

# set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
install(TARGETS testStudent DESTINATION /usr/lib)

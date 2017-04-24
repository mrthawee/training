cmake_minimum_required(VERSION 2.8.9)
project(directory_test)
set(CMAKE_BUILD_TYPE Release)

# bring the headers, such as Student.h into the project
include_directories(include)

# however, the file(GLOB...) allows the wildcard additions:
file(GLOB SOURCES "src/*.cpp")

# generate the static library from the sources
add_library(testStudent STATIC ${SOURCES})

# set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
install(TARGETS testStudent DESTINATION /usr/lib)

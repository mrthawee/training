cmake_minimum_required(VERSION 2.8.9)
project(TestLibrary)


# for the static library
set ( PROJECT_LINK_LIBS libtestStudent.a )
link_directories ( ../ex4/build )

# for the shared library
#set ( PROJECT_LINK_LIBS libtestStudent.so )
#link_directories( ../ex3/build )

include_directories ( ../ex3/include/ )

# in order to install Student.h in to /usr/include or /usr/local/include
#install(FILES "${PROJECT_SOURCE_DIR}/include/Student.h" DESTINATION include)
# then 'sudo make install' will handle that`

add_executable(libtest libtest.cpp)
target_link_libraries( libtest ${PROJECT_LINK_LIBS} )

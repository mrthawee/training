cmake_minimum_required(VERSION 2.8.9)
project(TestLibrary)

include_directories ( ../inc/ )

#add_executable(libtest ../app/libtest.cpp ../src/Student.cpp)
file (GLOB KBSTRANCODE "../src/*.cpp")
#add_executable(libtest ../app/libtest.cpp ${KBSTRANCODE})
file (GLOB KB_UTESTS "../utest/*.cpp")
add_executable(libtest ${KB_UTESTS} ${KBSTRANCODE})

cmake_minimum_required(VERSION 3.21)
project(C__Workplace)

set(CMAKE_CXX_STANDARD 14)

file (GLOB_RECURSE files *.cpp)

foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file})
endforeach ()


cmake_minimum_required(VERSION 3.10)

project(RealFunctionAPI)

set (SOURCES
real_function.cpp
binary_operation_function.cpp
polynomial.cpp
sum_function.cpp
)

set (HEADERS
real_function.h
binary_operation_function.h
polynomial.h
sum_function.h

)

add_library(RealFunctionAPI ${SOURCES} ${HEADERS})
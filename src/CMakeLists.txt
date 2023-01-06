
cmake_minimum_required(VERSION 3.10)

project(driver)

add_subdirectory(RealFunctionAPI)

add_executable(driver driver.cpp)

target_include_directories(driver PRIVATE RealFunction)

target_link_libraries(driver RealFunctionAPI)

project(RFAPI_test)

add_executable(driver tester.cpp)

target_include_directories(driver 
    PRIVATE ${CMAKE_SOURCE_DIR}/lib/RealFunctionAPI/include
)

target_link_libraries(driver 
    PRIVATE RealFunctionAPI
)
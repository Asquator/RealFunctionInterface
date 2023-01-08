

set (SOURCES
    src/real_function.cpp
    src/binary_operation_function.cpp
    src/polynomial.cpp
    src/sum_function.cpp
    src/product_function.cpp
    src/difference_function.cpp
    src/fraction_function.cpp

)

add_library(RealFunctionAPI ${SOURCES})

target_include_directories(RealFunctionAPI PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/RealFunctionAPI                    
)
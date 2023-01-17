

set (SOURCES
src/real_math.cpp
src/real_function.cpp
src/binary_operation_function.cpp
src/sum_function.cpp
src/product_function.cpp
src/difference_function.cpp
src/fraction_function.cpp
src/negated_function.cpp
src/polynomial.cpp
src/special_function.cpp
)


add_library(RealFunctionAPI ${SOURCES})

target_include_directories(RealFunctionAPI 
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/RealFunctionAPI     
PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src  
)

include_directories(PRIVATE src)
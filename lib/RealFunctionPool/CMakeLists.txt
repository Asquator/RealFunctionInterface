
set (SOURCES

)


add_library(RealFunctionPool ${SOURCES})

target_link_libraries(RealFunctionPool PRIVATE RealFunctionLogic)

target_include_directories(RealFunctionPool 
PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/RealFunctionPool
PRIVATE ${CMAKE_SOURCE_DIR}/lib/RealFunctionLogic/include
)
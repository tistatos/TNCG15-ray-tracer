cmake_minimum_required(VERSION 2.8.12.2)
SET (PROJECT_NAME TNCG15_monte_carlo_rt)

project(${PROJECT_NAME})

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_CXX_DIR ${PROJECT_SOURCE_DIR}/src)

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please make a build directory" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
  message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
  message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

#compiler flags
SET(CMAKE_CXX_FLAGS "-std=c++11")

if(CMAKE_COMPILER_IS_GNUCXX)
add_definitions(
  -g
  -Wall
)
endif()

include_directories(
	${PROJECT_INCLUDE_DIR}
)

add_subdirectory(${PROJECT_CXX_DIR})
add_executable(${PROJECT_NAME} ${MAIN_SOURCE})
#target_link_libraries(${PROJECT_NAME} ${ALL_LIBS})

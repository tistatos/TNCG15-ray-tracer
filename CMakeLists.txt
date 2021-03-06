cmake_minimum_required(VERSION 2.8.12.2)
SET (PROJECT_NAME TNCG15)

project(${PROJECT_NAME} C CXX)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_CXX_DIR ${PROJECT_SOURCE_DIR}/src)
set(PROJECT_EXT_DIR ${PROJECT_SOURCE_DIR}/external)
set(PROJECT_TEST_DIR ${PROJECT_SOURCE_DIR}/test)

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please make a build directory" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
  message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
  message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

find_package(OpenMP)

#compiler flags
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-std=c++11 ${OpenMP_CXX_FLAGS}")

if(CMAKE_COMPILER_IS_GNUCXX)
add_definitions(
  -g
  -Wall
 -D_CRT_SECURE_NO_WARNINGS
)
add_definitions(-D_UNIX)
endif()

add_subdirectory( ${PROJECT_EXT_DIR} )

set(EXT_DEPS
  glm
)

set(ext_includes
  ${GLM_INCLUDE_DIR}
)

include_directories(
  ${ext_includes}
  ${PROJECT_INCLUDE_DIR}
)

add_subdirectory(${PROJECT_CXX_DIR})
add_executable(${PROJECT_NAME} ${MAIN_SOURCE})
add_dependencies(${PROJECT_NAME} ${EXT_DEPS})

add_library(${PROJECT_NAME}_lib ${MAIN_SOURCE})
add_dependencies(${PROJECT_NAME}_lib ${EXT_DEPS})

enable_testing()

set(EXT_DEPS
  glm
  pthread
  googletest
  gtest
)

set(PROJECT_TEST_NAME ${PROJECT_NAME}_test)

include_directories(${ext_includes})
include_directories(${GTEST_INCLUDE_DIRS})
add_subdirectory(${PROJECT_SOURCE_DIR}/test)

add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
add_dependencies(${PROJECT_TEST_NAME} ${EXT_DEPS})

set(Suffix ".a")
set(Pthread "-pthread")

target_link_libraries(${PROJECT_TEST_NAME} ${PROJECT_NAME}_lib)

target_link_libraries(${PROJECT_TEST_NAME}
			 debug ${GTEST_LIBS_DIR}/googlemock/gtest/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${Suffix}
			 optimized ${GTEST_LIBS_DIR}/googlemock/gtest/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${Suffix}
)

target_link_libraries(${PROJECT_TEST_NAME}
			 debug ${GTEST_LIBS_DIR}/googlemock/gtest/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${Suffix}
			 optimized ${GTEST_LIBS_DIR}/googlemock/gtest/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${Suffix}
			 ${Pthread}
)

add_test(MCtest ${PROJECT_TEST_NAME})

cmake_minimum_required(VERSION 3.9.2)

include("vendor/gate/cmake/HunterGate.cmake")

huntergate(
        URL "https://github.com/ruslo/hunter/archive/v0.23.31.tar.gz"
        SHA1 "3d94b8522541c4c8eaac606f4c47d09322a8019c"
)

project(Evolution::Edit)

set(EXECUTABLE_NAME "Evolution")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS 
"${CMAKE_CXX_FLAGS} -std=c++11 -O1 -fsanitize=address -Wall -Wextra -Wno-unused-command-line-argument -Wshadow -Wnon-virtual-dtor -pedantic"
)

file(GLOB SFML_LIBS ${CMAKE_SOURCE_DIR}/build/sfml/lib/*)
file(GLOB GTEST_LIBS ${CMAKE_SOURCE_DIR}/build/gtest/libgtest*)

# CLASSES
file(GLOB_RECURSE CLASSES_SOURCES src/classes/*.cpp)
add_library(classes ${CLASSES_SOURCES})
hunter_add_package(Boost COMPONENTS system filesystem)
find_package(Boost CONFIG REQUIRED system filesystem)

string(APPEND CMAKE_CXX_FLAGS " -pedantic -Wall -Wextra")
string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-command-line-argument")
string(APPEND CMAKE_CXX_FLAGS " -Wshadow -Wnon-virtual-dtor")

target_link_libraries(classes ${SFML_LIBS} Boost::filesystem Boost::system)
target_include_directories(classes PUBLIC src -fsanitize=address)
target_include_directories(classes PUBLIC vendor/sfml/include)

# GAME
set(SOURCES src/main.cpp)
add_executable(game ${SOURCES})
target_link_libraries(game classes)
target_include_directories(game PUBLIC src)
target_include_directories(game PUBLIC ${CMAKE_SOURCE_DIR}/vendor/sfml/include)

# TESTS
file(GLOB_RECURSE TEST_SOURCES src/tests/*.cpp)
add_executable(tests ${TEST_SOURCES})

target_link_libraries(tests ${GTEST_LIBS})
target_link_libraries(tests classes)
target_include_directories(tests PUBLIC vendor/sfml/include vendor/gtest/include)
target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR}/src)

add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)
include_directories(${SFML_INCLUDE_DIR} ${Boost_INCLUDE_DIRS})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})

add_custom_target(NAME run_tests COMMAND tests)

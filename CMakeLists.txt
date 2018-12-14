cmake_minimum_required(VERSION 3.9.2)
project(Mario::Edit)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB SFML_LIBS ${CMAKE_SOURCE_DIR}/build/sfml/lib/*)
file(GLOB GTEST_LIBS ${CMAKE_SOURCE_DIR}/build/gtest/libgtest*)

# CLASSES
file(GLOB_RECURSE CLASSES_SOURCES project/sourses/*.cpp)
add_library(classes ${CLASSES_SOURCES})
target_link_libraries(classes ${SFML_LIBS})
target_include_directories(classes PUBLIC project)
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
target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR}/project)

add_custom_target(NAME run_tests COMMAND tests)

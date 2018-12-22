cmake_minimum_required(VERSION 3.5.1)
include("tools/gate/cmake/HunterGate.cmake")

HunterGate(
        URL "https://github.com/ruslo/hunter/archive/v0.23.31.tar.gz"
        SHA1 "3d94b8522541c4c8eaac606f4c47d09322a8019c"
)

project(MarioEdit)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

hunter_add_package(nlohmann_json)
find_package(nlohmann_json CONFIG REQUIRED)

hunter_add_package(Boost COMPONENTS system filesystem)
find_package(Boost CONFIG REQUIRED system filesystem)

if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()

file(GLOB SFML_LIBS ${CMAKE_SOURCE_DIR}/build/sfml/lib/*)
file(GLOB GTEST_LIBS ${CMAKE_SOURCE_DIR}/build/gtest/libgtest*)

# CLASSES
file(GLOB_RECURSE CLASSES_SOURCES src/classes/*.cpp)
add_library(classes ${CLASSES_SOURCES})
target_link_libraries(classes ${SFML_LIBS})
target_include_directories(classes PUBLIC src)
target_include_directories(classes PUBLIC vendor/sfml/include)

# GAME
set(SOURCES src/main.cpp)
find_package(Threads REQUIRED)
add_executable(game ${SOURCES})
target_link_libraries(game classes ${CMAKE_THREAD_LIBS_INIT}
        nlohmann_json::nlohmann_json
        Boost::system
        Boost::filesystem)
target_include_directories(game PUBLIC src)
target_include_directories(game PUBLIC ${CMAKE_SOURCE_DIR}/vendor/sfml/include)

# TESTS
file(GLOB_RECURSE TEST_SOURCES src/tests/*.cpp)
add_executable(tests ${TEST_SOURCES})

target_link_libraries(tests ${GTEST_LIBS})
target_link_libraries(tests classes 
        nlohmann_json::nlohmann_json
        Boost::system
        Boost::filesystem)
target_include_directories(tests PUBLIC vendor/sfml/include vendor/gtest/include)
target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR}/src)

add_custom_target(NAME run_tests COMMAND tests)

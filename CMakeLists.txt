cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include("vendor/gate/cmake/HunterGate.cmake")

HunterGate(
        URL "https://github.com/ruslo/hunter/archive/v0.23.31.tar.gz"
        SHA1 "3d94b8522541c4c8eaac606f4c47d09322a8019c"
)

project(evolution)
string(APPEND CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unused-command-line-argument -Wnon-virtual-dtor -pedantic")

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

hunter_add_package(nlohmann_json)
find_package(nlohmann_json CONFIG REQUIRED)

hunter_add_package(Boost COMPONENTS system filesystem)
find_package(Boost CONFIG REQUIRED system filesystem)


set(EXECUTABLE_NAME "Evolution")

add_executable(evolution_tests
        src/main.cpp
        src/classes/Map.cpp
        src/classes/Evolution.cpp
        src/classes/Keyboard.cpp
        src/classes/Hexagon.cpp
        src/classes/Pixel.cpp
        src/classes/Link.cpp
        src/classes/Brain.cpp
        src/classes/Neuron.cpp
        src/classes/TrainAlgorithm.cpp
        src/classes/Button.cpp
        src/classes/Keyboard_test.cpp
        src/classes/Brain_tests.cpp)

add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)

set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/vendor/sfml")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/vendor/sfml/cmake/Modules")
find_package(SFML REQUIRED system window graphics network audio)
include_directories(/usr/local/include)

target_link_libraries(evolution_tests
        GTest::main
        nlohmann_json::nlohmann_json
        Boost::system
        Boost::filesystem
        ${SFML_LIBRARIES})

enable_testing()
add_test(NAME tests COMMAND evolution_tests)

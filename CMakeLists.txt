cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include("tools/gate/cmake/HunterGate.cmake")

huntergate(
        URL "https://github.com/ruslo/hunter/archive/v0.23.34.tar.gz"
        SHA1 "70287b1ffa810ee4e952052a9adff9b4856d0d54"
)

project(template)
string(APPEND CMAKE_CXX_FLAGS " -pedantic -Wall -Wextra")
string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-command-line-argument")
string(APPEND CMAKE_CXX_FLAGS " -Wshadow -Wnon-virtual-dtor")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

hunter_add_package(nlohmann_json)
find_package(nlohmann_json CONFIG REQUIRED)

hunter_add_package(Boost COMPONENTS system filesystem)
find_package(Boost CONFIG REQUIRED system filesystem)

add_executable(tests
        project/main.cpp
        project/sourses/Map.cpp
        project/sourses/Evolution.cpp
        project/sourses/Keyboard.cpp
        project/sourses/Hexagon.cpp
        project/sourses/Pixel.cpp
        project/sourses/Link.cpp
        project/sourses/Brain.cpp
        project/sourses/Neuron.cpp
        project/sourses/TrainAlgorithm.cpp
        project/sourses/Button.cpp
        project/tests/Keyboard_test.cpp
        project/tests/Brain_tests.cpp)
add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)

set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/tools/sfml")




target_include_directories(tests
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/project/include
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/project/sourses
        PUBLIC ${SFML_DIR}/include
        )
target_link_libraries(tests PUBLIC
        sfml-graphics
        GTest::main
        nlohmann_json::nlohmann_json
        Boost::system
        Boost::filesystem)

enable_testing()
add_test(NAME unit_tests COMMAND tests)
include_directories(SYSTEM
    ./
)
cmake_minimum_required (VERSION 2.8)
set (CMAKE_CXX_FLAGS "-std=c++11")
set(SFML_DIR "SFML-2.3.2/share/SFML/cmake/Modules")
set(CMAKE_MODULE_PATH "SFML-2.3.2/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED system window graphics network audio)

add_executable(executable main.cpp)

if(SFML_FOUND)
    message("Sfml found!")
    include_directories (${SFML_INCLUDE_DIR})
    target_link_libraries(executable ${SFML_LIBRARIES})
endif()

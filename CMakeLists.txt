cmake_minimum_required(VERSION 3.9)

include_directories(SYSTEM
    ./
)

ADD_DEFINITIONS(
    -std=c++11
)

# enum your files
add_executable(executable
    main.cpp
)
set(SFML_DIR "SFML/cmake")
set(CMAKE_MODULE_PATH "SFML/cmake" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED system window graphics network audio)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
endif()
target_link_libraries(executable ${SFML_LIBRARIES})

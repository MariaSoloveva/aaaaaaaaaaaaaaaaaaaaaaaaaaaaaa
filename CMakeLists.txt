cmake_minimum_required(VERSION 3.9)

include_directories(SYSTEM
    ./
)

ADD_DEFINITIONS(
    -std=c++14
)

# enum your files
add_executable(executable
    main.cpp
)
set(SFML_DIR "SFML")
set(SFML_DIR "SFML")
find_package(SFML REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

set(CMAKE_MODULE_PATH "SFML" ${CMAKE_MODULE_PATH})
target_link_libraries(executable)

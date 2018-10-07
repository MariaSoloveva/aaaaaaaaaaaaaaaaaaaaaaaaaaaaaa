cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 14)

set(SFML_DIR "SFML-2.3.2/share/SFML/cmake/Modules")
set(CMAKE_MODULE_PATH "SFML-2.3.2/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    add_executable(executable
    main.cpp
)
    target_link_libraries(executable ${SFML_LIBRARIES})
endif()

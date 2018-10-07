project (evolution)
cmake_minimum_required(VERSION 3.9)

include_directories(SYSTEM
    ./
)
 ADD_DEFINITIONS(
    -std=c++11
)

/*set(SFML_DIR "SFML-2.3.2/share/SFML/cmake/Modules")
set(CMAKE_MODULE_PATH "SFML-2.3.2/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    add_executable(executable
    main.cpp
)
    target_link_libraries(executable ${SFML_LIBRARIES})
endif()*/

cmake_minimum_required (VERSION 2.8)

set (CMAKE_CXX_FLAGS "-std=c++11")

find_package(SFML 2.0 REQUIRED audio graphics network system window)

include_directories (${SFML_INCLUDE_DIR})
link_libraries (${SFML_LIBRARIES})

include_directories (EVOLUTION_INCLUDES)
add_executable (evolution $EVOLUTION_SOURCES})
target_link_libraries (evolution ${SFML_LIBRARIES})

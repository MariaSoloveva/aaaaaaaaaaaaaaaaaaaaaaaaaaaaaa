project (evolution)
include_directories(SYSTEM
    ./
)
 ADD_DEFINITIONS(
    -std=c++11
)

cmake_minimum_required (VERSION 2.8)

set (CMAKE_CXX_FLAGS "-std=c++11")

find_package(SFML 2.0 REQUIRED audio graphics network system window)

include_directories (${SFML_INCLUDE_DIR})
link_libraries (${SFML_LIBRARIES})

include_directories (EVOLUTION_INCLUDES)
add_executable (evolution $EVOLUTION_SOURCES})
target_link_libraries (evolution ${SFML_LIBRARIES})

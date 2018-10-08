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
    message(${SFML_INCLUDE_DIR})
    message(${SFML_LIBRARIES})
    include_directories ("/usr/include")
    target_link_libraries(executable "/usr/lib/x86_64-linux-gnu/libsfml-system.so/usr/lib/x86_64-linux-gnu/libsfml-window.so/usr/lib/x86_64-linux-gnu/libsfml-graphics.so/usr/lib/x86_64-linux-gnu/libsfml-network.so/usr/lib/x86_64-linux-gnu/libsfml-audio.so")
endif()

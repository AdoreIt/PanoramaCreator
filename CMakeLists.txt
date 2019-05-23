cmake_minimum_required(VERSION 3.0.0)

project(panorama_creator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(panorama_creator ${SOURCES})

find_package(OpenCV 3.4.6 REQUIRED)
find_package(RapidJSON REQUIRED)

target_link_libraries(panorama_creator
    PRIVATE ${OpenCV_LIBS})
    
target_include_directories(panorama_creator
    PRIVATE ${RapidJSON_INCLUDE_DIR}
    PRIVATE ${OpenCV_INCLUDE_DIRS}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

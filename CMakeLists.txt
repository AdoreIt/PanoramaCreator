cmake_minimum_required(VERSION 3.0.0)

project(panorama_creator)

include_directories(include)
file(GLOB SOURCES 
    "src/*.cpp")

add_executable(panorama_creator ${SOURCES})

find_package(OpenCV 3.4.6 REQUIRED)

target_link_libraries(panorama_creator
    PRIVATE ${OpenCV_LIBS})
    
target_include_directories(panorama_creator
    PRIVATE ${OpenCV_INCLUDE_DIRS})

#add_subdirectory(src)
    

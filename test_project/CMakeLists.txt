cmake_minimum_required(VERSION 3.0.0)

project(opencv_test)

add_executable(opencv_test
	main.cpp)

find_package(OpenCV 3.4.6 REQUIRED)

target_link_libraries(opencv_test
	PRIVATE ${OpenCV_LIBS})

target_include_directories(opencv_test
	PRIVATE ${OpenCV_INCLUDE_DIRS})
  

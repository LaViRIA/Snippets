project (Ecualizacion)
cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 14)
find_package (OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable (ecualizacion src/ecualizacion.cpp)
target_link_libraries(ecualizacion ${OpenCV_LIBS})

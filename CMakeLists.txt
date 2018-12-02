cmake_minimum_required(VERSION 2.8)

# Project name
project(DIP_HW05)

# Find OpenCV package and include it
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# Set C++ 11
set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

# Project sources
set( SOURCE_DIR src )
set( PROJECT_SOURCES
        ${SOURCE_DIR}/common.h
        ${SOURCE_DIR}/common.cpp
        ${SOURCE_DIR}/BaseProcessor.h
        ${SOURCE_DIR}/BaseProcessor.cpp
        ${SOURCE_DIR}/EdgeDetector.cpp
        ${SOURCE_DIR}/EdgeDetector.h
        ${SOURCE_DIR}/filters/BaseFilters.cpp
        ${SOURCE_DIR}/filters/BaseFilters.h
        ${SOURCE_DIR}/filters/GradientFilters.cpp
        ${SOURCE_DIR}/filters/GradientFilters.h
        ${SOURCE_DIR}/filters/SobelFilter.cpp
        ${SOURCE_DIR}/filters/SobelFilter.h
        src/filters/PrewittFilter.cpp src/filters/PrewittFilter.h src/filters/RobertsFilter.cpp src/filters/RobertsFilter.h src/filters/ScharrFilter.cpp src/filters/ScharrFilter.h)

# The main program
add_executable( DIP_HW05 ${SOURCE_DIR}/main.cpp ${PROJECT_SOURCES} )

# Add link libraries
target_link_libraries( DIP_HW05 ${OpenCV_LIBS} )

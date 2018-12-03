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
set( SOURCE_FILTERS_DIR src/filters )
set( PROJECT_SOURCES
        ${SOURCE_DIR}/common.h
        ${SOURCE_DIR}/common.cpp
        ${SOURCE_DIR}/BaseProcessor.h
        ${SOURCE_DIR}/BaseProcessor.cpp
        ${SOURCE_DIR}/EdgeDetector.cpp
        ${SOURCE_DIR}/EdgeDetector.h
        ${SOURCE_FILTERS_DIR}/BaseFilters.cpp
        ${SOURCE_FILTERS_DIR}/BaseFilters.h
        ${SOURCE_FILTERS_DIR}/GradientFilters.cpp
        ${SOURCE_FILTERS_DIR}/GradientFilters.h
        ${SOURCE_FILTERS_DIR}/SobelFilter.cpp
        ${SOURCE_FILTERS_DIR}/SobelFilter.h
        ${SOURCE_FILTERS_DIR}/PrewittFilter.cpp
        ${SOURCE_FILTERS_DIR}/PrewittFilter.h
        ${SOURCE_FILTERS_DIR}/RobertsFilter.cpp
        ${SOURCE_FILTERS_DIR}/RobertsFilter.h
        ${SOURCE_FILTERS_DIR}/ScharrFilter.cpp
        ${SOURCE_FILTERS_DIR}/ScharrFilter.h src/filters/MarrHildrethFilters.cpp src/filters/MarrHildrethFilters.h src/filters/LaplaceFilter.cpp src/filters/LaplaceFilter.h src/filters/LoGFilter.cpp src/filters/LoGFilter.h)

# The main program
add_executable( DIP_HW05 ${SOURCE_DIR}/main.cpp ${PROJECT_SOURCES} )

# Add link libraries
target_link_libraries( DIP_HW05 ${OpenCV_LIBS} )

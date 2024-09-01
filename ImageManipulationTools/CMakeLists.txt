cmake_minimum_required(VERSION 3.28)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#------------------Add CPM for easier package installs----------
set(CPM_DOWNLOAD_LOCATION ${CMAKE_BINARY_DIR}/CPM.cmake)
file(DOWNLOAD
        https://github.com/cpm-cmake/CPM.cmake/releases/latest/download/cpm.cmake
        ${CPM_DOWNLOAD_LOCATION})
include(${CPM_DOWNLOAD_LOCATION})

find_package(QT NAMES Qt6 Widgets PythonLibs REQUIRED COMPONENTS)


#------------------PYTHON hooks (Using Pybind11)----------------
include_directories(${PYTHON_INCLUDE_DIRS})
CPMAddPackage("gh:pybind/pybind11#v2.13.5")
pybind11_add_module(image_processing_py imageprocessing.cpp)

target_include_directories(image_processing_py
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(image_processing_py PUBLIC
    ${PYTHON_LIBRARIES}
    Qt6::Widgets
    pybind11::pybind11
)


#------------------C++ hooks----------------
add_library(image_processing_cpp imageprocessing.cpp)

target_include_directories(image_processing_cpp
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(image_processing_cpp PUBLIC
    ${PYTHON_LIBRARIES}
    Qt6::Widgets
    pybind11::pybind11
)

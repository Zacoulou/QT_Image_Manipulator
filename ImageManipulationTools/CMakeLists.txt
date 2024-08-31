find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)

add_library(image_processing imageprocessing.cpp)

target_include_directories(image_processing
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(image_processing PRIVATE
    Qt6::Widgets)

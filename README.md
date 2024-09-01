# QT_Image_Manipulator
An image manipulation tool that supports both a QT GUI and Python CLI for performing simple image operations including grayscale, vertical flip, and calculating average pixel value. Project uses Cmake and Pybind11 to create a C++ library with Python bindings so that the same backend code can be shared between the C++ QT GUI and the Python script.

# QT Setup
### Requirements
- QT6 + QTCreator
- CMake 3.28+
- GCC 13 C++ compiler
- CPM (Automatically fetched via CMakeLists)
- Pybind11 (Automatically fetched via CMakeLists)
### Setup
1. Import project into QTCreator
2. If needed, modify kit to include GCC C++ compiler
3. Build & Run

# Python Setup
### Requirements
- Python3
- prettytable
- Pillow
### Setup
1. Follow QT Setup steps first because the generated .so file is required for the python script to execute
2. Copy the image_processing_py .so library from the build/ folder to the same directory as the image_manipulation.py script
3. Ensure image_manipulation.py is marked as executable
4. Run `./image_manipulation.py <source_image_directory> <destination_image_directory>`

# CMakeLists.txt in the PNG_Reader directory

# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.16.3)

# Define the library target called "PNG_Reader"
add_library(PNG_Reader
    PNG_Reader.hpp
)

set_target_properties(PNG_Reader PROPERTIES LINKER_LANGUAGE CXX)
# Specify include directories for libpng
find_package(PNG REQUIRED)
target_include_directories(PNG_Reader PUBLIC ${PNG_INCLUDE_DIRS})

# Link against libpng
target_link_libraries(PNG_Reader PUBLIC ${PNG_LIBRARIES})
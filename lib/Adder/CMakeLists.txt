# CMakeLists.txt in the Adder directory

# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.16.3)

# Define the library target called "Adder"
add_library(Adder
    adder.cpp
    # Remove the 'adder.h' entry from here
)

# Include directories if needed (to make the 'adder.h' file available)
target_include_directories(Adder PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}  # Include the 'Adder' directory
)
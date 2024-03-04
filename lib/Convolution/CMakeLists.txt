# CMakeLists.txt in the Convolution directory

# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.16.3)

# Define the library target called "Convolution"
add_library(Convolution
    Plan_1d_FFT.hpp
    Plan_2d_FFT.hpp
)

set_target_properties(Convolution PROPERTIES LINKER_LANGUAGE CXX)

# Specify FFTW3 library and include directories
set(FFTW3_INCLUDE_DIR /usr/include)
set(FFTW3_LIBRARY_DIR /usr/lib/x86_64-linux-gnu)

# Include directories
include_directories(${FFTW3_INCLUDE_DIR})

# Include directories if needed (to make the 'Convolution.hpp' file available)
target_include_directories(Convolution PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}  # Include the 'Convolution' directory
    ${FFTW3_INCLUDE_DIR}          # Include FFTW3 header directory
)
target_link_libraries(
    Convolution PUBLIC 
    ${FFTW3_LIBRARY_DIR}/libfftw3.so.3.6.10
)

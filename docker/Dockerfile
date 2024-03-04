FROM gcc:latest

RUN apt-get -y update && apt-get install -y

RUN apt-get -y install gcc
RUN apt-get -y install cmake
RUN apt-get -y install vim


COPY fftw3.h /usr/include/fftw3.h
# Copy library files to this directory
cp /usr/include/fftw3.h .

# build the docker image
docker build . -t johngrotke/hello-world -f docker/Dockerfile
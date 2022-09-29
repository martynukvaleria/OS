
g++ -c -o libs/numbers.o Numbers/numbers.cpp
ar rcs libs/libnumbers.a libs/numbers.o

g++ -c -fpic -o libs/vector.o Vector/Vector.cpp -B static -L libs -lnumbers
g++ -shared -o libs/libvector.so libs/vector.o

export LD_LIBRARY_PATH="libs"

g++ -o libs/a.out Main/main.cpp -B dynamic -L libs -lvector  -B static -L libs -lnumbers

./libs/a.out

export LD_LIBRARY_PATH=""

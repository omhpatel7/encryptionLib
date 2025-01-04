# Target to build all examples and the RC4 library
all: rc4 example

# Build the 'example' executable from 'example.o'
example: example.o
	gcc example.o -o example -Wall -O2

# Compile 'example.c' into the object file 'example.o'
example.o: example.c
	gcc -c -O2 -Wall example.c

# Build the RC4 shared library from 'rc4.o'
rc4: rc4.o
	gcc rc4.o -o rc4.so -O2 -Wall -fPIC -shared -ldl -D_GNU_SOURCE

# Compile 'rc4.c' into the object file 'rc4.o'
rc4.o: rc4.c
	gcc -c -O2 -Wall rc4.c

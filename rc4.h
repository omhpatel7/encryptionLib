/* rc4.h */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define rc4_decrypt(x, y) rc4_encrypt(x, y)

struct s_arcfour{
    /* data */
};

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

Arcfour *rc4_init(int8*, int16);
int8 rc4Byte(void);
int8 *rc4_encrypt(int8*, int16);
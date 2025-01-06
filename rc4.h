/* rc4.h */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>

typedef struct s_arcfour Arcfour;
typedef unsigned char int8;
typedef unsigned char uchar;
typedef unsigned short int int16;
typedef unsigned int int32;

#define export __attribute__((visibility("default")))
#define rc4_decrypt(x, y) rc4_encrypt(x, y)
#define rc4_uninit(x) free(x)

struct s_arcfour{
    int16 i, j, k;
    int16 s[256];
};

export Arcfour *rc4_init(uchar*, int16);
uchar rc4Byte(Arcfour*);
export uchar *rc4_encrypt(Arcfour *p, int8 *ct, int16 size);

/* rc4.h */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>

#define rc4_decrypt(x, y) rc4_encrypt(x, y)

struct s_arcfour{
    int x;
};

typedef struct s_arcfour Arcfour;
typedef unsigned char uchar;
typedef unsigned short int int16;
typedef unsigned int int32;

Arcfour *rc4_init(uchar*, int16);
uchar rc4Byte(void);
uchar *rc4_encrypt(uchar*, int16);
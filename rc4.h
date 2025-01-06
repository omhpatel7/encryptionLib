/* rc4.h */

/* Include necessary standard headers */
#define _GNU_SOURCE  // Define _GNU_SOURCE for enabling GNU extensions
#include <stdio.h>   // Standard input/output
#include <stdlib.h>  // Memory allocation and process control
#include <string.h>  // String manipulation functions
#include <unistd.h>  // Unix system calls
#include <assert.h>  // Assert for debugging
#include <errno.h>   // Error codes

/* Typedefs to simplify types */
typedef struct s_arcfour Arcfour;  // Define Arcfour as a type for struct s_arcfour
typedef unsigned char int8;       // Define int8 as an unsigned char (8 bits)
typedef unsigned char uchar;      // Define uchar as an unsigned char (8 bits)
typedef unsigned short int int16; // Define int16 as an unsigned short (16 bits)
typedef unsigned int int32;       // Define int32 as an unsigned int (32 bits)

/* Define 'export' to set visibility for shared library functions */
#define export __attribute__((visibility("default")))

/* Macro to simplify rc4_decrypt (as it uses rc4_encrypt) */
#define rc4_decrypt(x, y) rc4_encrypt(x, y)

/* Macro to free the memory allocated for Arcfour struct */
#define rc4_uninit(x) free(x)

/* Struct for RC4 cipher state */
struct s_arcfour {
    int16 i, j, k;      // Indices for the RC4 state machine
    int16 s[256];       // State array used in RC4 algorithm (size 256)
};

/* Function prototypes */

/**
 * Initializes the RC4 cipher with the given key.
 *
 * @param key The key to initialize the cipher.
 * @param size The length of the key.
 * @return A pointer to an initialized Arcfour structure.
 */
export Arcfour *rc4_init(uchar* key, int16 size);

/**
 * Returns the next byte of the keystream for RC4 encryption.
 *
 * @param p Pointer to an initialized Arcfour structure.
 * @return The next byte from the RC4 keystream.
 */
uchar rc4Byte(Arcfour* p);

/**
 * Encrypts or decrypts the given data using the RC4 cipher.
 *
 * @param p Pointer to an initialized Arcfour structure.
 * @param ct The data to be encrypted or decrypted.
 * @param size The size of the data.
 * @return The encrypted or decrypted data.
 */
export uchar *rc4_encrypt(Arcfour *p, int8 *ct, int16 size);

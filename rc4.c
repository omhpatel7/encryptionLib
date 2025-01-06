/* rc4.c */

#include <rc4.h>

export Arcfour *rc4_init(int8 *key, int16 size) {
    Arcfour *p = malloc(sizeof(Arcfour));  // allocate memory
    if (!p) {  // check if malloc failed
        perror("malloc failed");
        exit(1);  // exit if memory allocation failed
    }
    int8 temp1;
    int8 temp2;

    int16 x;

    // Initialize the state array (s)
    for (x = 0; x < 256; x++) {
        p->s[x] = x;  // Initialize to the identity permutation
    }

    p->i = p->j = p->k = 0;

    // Key-scheduling algorithm (KSA)
    for (p->i = 0; p->i < 256; p->i++) {
        temp1 = p->i % size;   // Ensure no overflow
        temp2 = (p->j + p->s[p->i] + key[temp1]) % 256;  // Proper range
        p->j = temp2;

        // Swap elements in the state array
        int16 swap = p->s[p->i];
        p->s[p->i] = p->s[p->j];
        p->s[p->j] = swap;
    }

    // Reset indices for encryption
    p->i = p->j = 0;

    return p;
}

int8 rc4Byte(Arcfour *p) {
    int16 temp;
    p->i = (p->i + 1) % 256;
    p->j = (p->j + p->s[p->i]) % 256;

    // Swap
    temp = p->s[p->i];
    p->s[p->i] = p->s[p->j];
    p->s[p->j] = temp;

    // Generate keystream byte
    int16 t = (p->s[p->i] + p->s[p->j]) % 256;
    return p->s[t];
}


export int8 *rc4_encrypt(Arcfour *p, int8 *ct, int16 size) {
    int8 *output = malloc(size);
    if (!output) {
        perror("malloc failed");
        exit(1);
    }

    for (int16 x = 0; x < size; x++) {
        output[x] = ct[x] ^ rc4Byte(p);
    }

    // printf("Ciphertext (Hex): ");
    for (int16 x = 0; x < size; x++) {
        // printf("%02x ", (unsigned char)output[x]);
    }

    return output;
}


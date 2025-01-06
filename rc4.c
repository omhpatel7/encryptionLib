/* rc4.c */

#include <rc4.h>

Arcfour *rc4_init(int8 *key, int16 size) {
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
        temp1 = p->i % size;  // Wrap key index if needed
        temp2 = p->j + p->s[p->i] + key[temp1];
        p->j = temp2 % 256;

        // Swap elements in the state array
        temp1 = p->s[p->i];
        p->s[p->i] = p->s[p->j];
        p->s[p->j] = temp1;
    }

    // Reset indices for encryption
    p->i = p->j = 0;

    return p;
}

int8 rc4Byte(Arcfour *p) {
    int8 temp;
    p->i++;
    p->j += p->s[p->i];
    temp = p->s[p->i];
    p->s[p->i] = p->s[p->j];
    p->s[p->j] = temp;
    temp = p->s[p->i] + p->s[p->j];
    return p->s[temp];
}

int8 *rc4_encrypt(Arcfour *p, int8 *ct, int16 size) {
    int16 x;
    int8 *pt = malloc(size);  // allocate memory
    if (!pt) {  // check if malloc failed
        perror("malloc failed");
        exit(1);  // exit if memory allocation failed
    }

    for (x = 0; x < size; x++) {
        pt[x] = ct[x] ^ rc4Byte(p);  // XOR the plaintext with the keystream
    }

    return pt;
}

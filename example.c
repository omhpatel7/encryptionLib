/* exmaple.c */

#include <rc4.h>
#include <time.h>

#define F fflush(stdout)
int main(void);

void printbin(uchar *text, const int16 size) {
    int16 i;

    assert(size > 0);

    for (i = 0; i < size; i++) {
        if (i && i % 2 == 0) {
            printf(" ");
        }
        printf("%.02x", text[i]);
    }
    printf("\n");
}


int main() {
    Arcfour *rc4;
    int16 skey, stext;

    uchar *key, *from, *encrypted, *decrypted;

    key = from = encrypted = decrypted = NULL;  // Initialize pointers
    skey = stext = 0;

    // Step 1: Generate a random key
    srand(time(NULL));  // Seed the random number generator
    skey = 8;  // Key length (e.g., 8 bytes)
    key = malloc(skey + 1);  // Allocate memory for the key (+1 for null-termination)
    if (!key) {
        fprintf(stderr, "Memory allocation for key failed\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < skey; i++) {
        key[i] = (uchar)(rand() % 256);  // Random byte between 0-255
    }
    key[skey] = '\0';  // Null-terminate (not strictly needed for RC4 but useful for printing)

    // printf("Generated Key: ");
    // printbin(key, skey);  // Display the key in hexadecimal

    from = (uchar *)"Hello, World!";
    stext = strlen((const char *)from);

    // Allocate memory for encrypted and decrypted
    encrypted = malloc(stext + 1);  // +1 for null terminator
    decrypted = malloc(stext + 1);  // +1 for null terminator

    if (!encrypted || !decrypted) {
        fprintf(stderr, "Memory allocation failed\n");
        free(key);
        free(encrypted);
        free(decrypted);
        return EXIT_FAILURE;
    }

    printf("Encrypting ...\n"); F;
    rc4 = rc4_init((int8 *)key, skey);
    if (!rc4) {
        fprintf(stderr, "Failed to initialize RC4\n");
        free(key);
        free(encrypted);
        free(decrypted);
        return EXIT_FAILURE;
    }

    // Copy plain text to encrypted and encrypt it
    memcpy(encrypted, from, stext);
    encrypted[stext] = '\0';  // Null-terminate
    rc4_encrypt(rc4, encrypted, stext);
    printf("Encrypted text: ");
    printbin((uchar *)encrypted, stext);

    rc4_uninit(rc4);  // Free the RC4 state

    printf("\n");
    // Reinitialize RC4 for decryption
    printf("Decrypting ...\n"); F;
    rc4 = rc4_init((int8 *)key, skey);
    if (!rc4) {
        fprintf(stderr, "Failed to initialize RC4\n");
        free(key);
        free(encrypted);
        free(decrypted);
        return EXIT_FAILURE;
    }

    // Copy encrypted text to decrypted and decrypt it
    memcpy(decrypted, encrypted, stext);
    decrypted[stext] = '\0';  // Null-terminate
    rc4_encrypt(rc4, decrypted, stext);  // RC4 decrypts by re-encrypting
    printf("Decrypted text: '%s'\n", decrypted);

    rc4_uninit(rc4);  // Free the RC4 state

    // Clean up memory
    free(key);
    free(encrypted);
    free(decrypted);

    return 0;
}
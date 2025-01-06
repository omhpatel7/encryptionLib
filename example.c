/* exmaple.c */

#include <rc4.h>

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

    key = from = encrypted = decrypted = 0;
    from = key;

    skey = stext = 0;

    key = (uchar *)"8&=pFE!c";
    skey = strlen((const char *)key);

    from = (uchar *)"Hello, World!";
    stext = strlen((const char *)from);

    printf("Encrypting ...\n"); F;
    rc4 = rc4_init((int8 *)key, skey);

    if (!rc4) {
        fprintf(stderr, "Failed to initialize RC4\n");
        return EXIT_FAILURE;
    }

    printf("Done!\n");

    printf("'%s' -> ", from);
    printf(" ");
    encrypted = rc4_encrypt(rc4, from, stext);
    printf("'%s'\n", encrypted);

    printbin((uchar *)rc4->s, 256);  // Print the full state array
    return 0;


}
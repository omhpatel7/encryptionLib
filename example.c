/* exmaple.c */

#include <rc4.h>

#define F fflush(stdout)
int main(void);

void printbin(uchar *text, const int16 size) {
    int16 i;
    uchar *p;

    assert(size > 0);

    for (i = size, p = text; i; i--, p++) {
        if (!((i + 1) % 2)) {
            printf(" ");
        }
        printf("%.02x", *p);
    }
    printf("\n");

    return;
}

int main() {
    // Arcfour *rc4 = NULL;
    int16 skey, stext;

    uchar *key, *from, *encrypted, *decrypted;

    key = from = encrypted = decrypted = 0;
    from = key;

    skey = stext = 0;

    key = (uchar *)"8&=pFE!c";
    skey = strlen((const char *)key);

    from = (uchar *)"Hello, World!";
    stext = strlen((const char *)from);

    printf("Encrypting ...\n");
    // rc4 = rc4_init((uchar *)key, skey); F;

    /*if (!rc4) {
        fprintf(stderr, "Failed to initialize RC4\n");
        return EXIT_FAILURE;
    }*/

    printf("Done!\n");

    printf("'%s' -> ", from);
    // encrypted = rc4_encrypt(from, stext); F;

    printbin((uchar *)key, skey);
    return 0;


}
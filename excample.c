/* exmaple.c */

#include <rc4.h>

#define F fflush(stdout)
int main(void);

int main() {
    Arcfour *rc4;
    int16 skey, stext;

    char *key, *from, *encrypted, *decrypted;

    key = "8&=pFE!c";
    skey = strlen(key);

    from = "Hello, World!";
    stext = strlen(from);

    printf("Encrypting ...\n");
    rc4 = rc4_init(key, skey); F;
    printf("Encrypting Done!\n");

    printf("'%s' -> ", from);
    encrypted = rc4_encrypt(from, stext); F;
}
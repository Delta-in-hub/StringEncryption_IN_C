#ifndef StringEncryption
#define StringEncryption

#define MAX_BUF 256

void EncryptString(const unsigned char *string, int *code);

void DecryptString(const int *code, char *string);

#endif

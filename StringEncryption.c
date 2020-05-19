#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StringEncryption.h"

unsigned char getBit(unsigned char, int);
unsigned char setBit(unsigned char, int);
unsigned char clearBit(unsigned char, int);
unsigned char encode(unsigned char, unsigned char, int);

unsigned char encode(unsigned char pt, unsigned char key, int count)
{
    unsigned char result; // declaring our return variable
    result = pt;          // setting it equal to our input paramater
    int i;
    if ((count % 3) == 0)
    { // if counter mod 3 = 0
        for (i = 0; i < 8; i += 2)
        {                                                       // loop through all other bits starting at 0
            if (((getBit(pt, i)) ^ (getBit(key, i))) == 0)      // if the input xor the key bit = 0
                result = clearBit(result, i);                   // set it to 0
            else if (((getBit(pt, i)) ^ (getBit(key, i))) == 1) // if the input xor the key bit = 1
                result = setBit(result, i);                     // set it to 1
        }
    }
    else if ((count % 3) == 1)
    { // if the counter mod 3 = 1
        for (i = 1; i < 8; i += 2)
        {                                                       // loop through all other bits starting at 1
            if (((getBit(pt, i)) ^ (getBit(key, i))) == 0)      // if the input xor the key bit = 0
                result = clearBit(result, i);                   // set it to 0
            else if (((getBit(pt, i)) ^ (getBit(key, i))) == 1) // if the input xor the key bit = 1
                result = setBit(result, i);                     // set it to 1
        }
    }
    else if ((count % 3) == 2)
    { // if the counter mod 3 = 2
        for (i = 0; i < 8; i++)
        {                                                       // loop through all other bits starting at 1
            if (((getBit(pt, i)) ^ (getBit(key, i))) == 0)      // if the input xor the key bit = 0
                result = clearBit(result, i);                   // set it to 0
            else if (((getBit(pt, i)) ^ (getBit(key, i))) == 1) // if the input xor the key bit = 1
                result = setBit(result, i);                     // set it to 1
        }
    }
    return result; // return our new Encrypted bit
}

/*
  Function:  getBit
  Purpose:   retrieve value of bit at specified position
       in:   character from which a bit will be returned
       in:   position of bit to be returned
   return:   value of bit n in character c (0 or 1)
*/
unsigned char getBit(unsigned char c, int n)
{
    c = (c & (1 << n)) >> n;
    return c;
}

/*
  Function:  setBit
  Purpose:   set specified bit to 1
       in:   character in which a bit will be set to 1
       in:   position of bit to be set to 1
   return:   new value of character c with bit n set to 1
*/
unsigned char setBit(unsigned char c, int n)
{
    c = c | (1 << n);
    return c;
}

/*
  Function:  clearBit
  Purpose:   set specified bit to 0
       in:   character in which a bit will be set to 0
       in:   position of bit to be set to 0
   return:   new value of character c with bit n set to 0
*/
unsigned char clearBit(unsigned char c, int n)
{
    c = c & (~(1 << n));
    return c;
}

void EncryptString(const unsigned char *string, int *code)
{
    unsigned char input[MAX_BUF];
    strcpy(input, string);
    strcat(input, "\n");
    int i;
    unsigned char out;
    for (i = 0; i < strlen(input) - 1; i++)
    {
        out = encode(input[i], yourkey, i);
        code[i] = out;
    }
    code[i] = -1;
}

void DecryptString(const int *code, char *string)
{
    int i;
    unsigned char out;
    for (i = 0; i >= 0; i++)
    {
        if (code[i] == -1)
            break;
        out = encode(code[i], yourkey, i);
        string[i] = out;
    }
    string[i] = 0;
}

#include "StringEncryption.h"
#include <stdio.h>
#include <string.h>

int main()
{
    unsigned char str[] = {"I want to have a try."};
    int nums[MAX_BUF];
    char temp[MAX_BUF];
    EncryptString(str, nums);
    DecryptString(nums, temp);
    if (strcmp(str, temp) == 0)
        printf("1");
    return 0;
}

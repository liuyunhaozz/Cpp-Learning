#include<stdio.h>



int main()
{

    int val = 0x1221412;
    char *p = (char *) &val;
    printf("%x %x %x %x", p[0], p[1], p[2], p[3]);
}
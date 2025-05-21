#include <stdio.h>
#include <stdlib.h>
#define INTSIZE 32

int main()
{
    unsigned int n, cnt = 0;
    printf("Enter an unsigned integer: ");
    scanf("%u", &n);
    while(n != 0)
    {
        n = n & (n-1);
        cnt++;
    }
    if ((INTSIZE - cnt) % 2)
        printf("The number of 0 digits is odd. \n");
    else
        printf("The number of 0 digits is even. \n");
    return 0;
}
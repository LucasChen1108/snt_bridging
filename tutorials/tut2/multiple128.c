#include <stdio.h>

int main()
{
    int x, mul = 1;
    printf("Give me an integer: ");
    scanf("%d", &x);
    if ((x & 0x0078))
        printf("Is not the multiple of 128.\n");
    else
        printf("Is the multiple of 128.\n");
    return 0;
}

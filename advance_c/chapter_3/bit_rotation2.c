#include <stdio.h>
#include <stdlib.h>

int rotate_l(int x, int n)
{
    int truncate;
    for (int i = 0; i < n; i++)
    {
        truncate = x & 0x8000;
        x = x << 1;
        if(truncate != 0) x |= 1;
        x | 0x00007777;
        
    }
    return x;
}

int main(void)
{
    int x, n, z;
    x = 0xfa27; /* 任意16位数 */
    n = 4;
    z = rotate_l(x, n);
    printf("%4x (base 16) rotated left by %d bits becomes %4x (base 16)\n", x, n, z);
    return 0;
}
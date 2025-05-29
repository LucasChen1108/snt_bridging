#include<stdio.h>

int rotate_l(int x, int n)
{
    const int width = 16;
    n = n % width;
    return ((x << n) | (x >> (width -n))) & 0xffff;
}

int main()
{
    int x, n, z;
    x = 0xfa27; /* 任意16位数 */
    n = 4;
    z = rotate_l(x, n);
    printf("%4x (base 16) rotated left by %d bits becomes %4x (base 16)\n", x, n, z);
    return 0;
}
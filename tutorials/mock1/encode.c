#include <stdio.h>
#include <stdint.h>

uint32_t encode (uint32_t this1)
{
    uint32_t truncate1, truncate2;
    truncate1 = (this1 & 0xf0000000) >> 28;
    truncate2 = (this1 & 0x0f000000) >> 20;
    this1 = (this1 << 8) | (truncate1 | truncate2);
    
    truncate1 = (this1 & 0xf0000000) >> 4;
    truncate2 = (this1 & 0x0f000000) << 4;
    this1 = (this1 & 0x00ffffff) | (truncate1 | truncate2);
    return this1;
}

int main()
{
    uint32_t a = 0x76543210;
    uint32_t b = encode(a);
    printf("After encode, %x become %x", a, b);
    return 0;
}
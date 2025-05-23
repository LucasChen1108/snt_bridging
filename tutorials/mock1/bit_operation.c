#include <stdio.h>
#include <stdint.h>

uint32_t flipBit(uint32_t n, uint32_t k)
{
    n ^= (1 << k);
    return n;
}

uint32_t clearBit(uint32_t n, uint32_t k)
{
    n &= (~ (1 << k));
    return n;
}

uint32_t getBit(uint32_t n, uint32_t k)
{
    return ((n >> k) & 1);
}

void isPowerOf2(uint32_t n)
{
    if (n == 0)
        printf("Isn't the power of 2. \n");
    else if(n & (n-1))
        printf("Isn't the power of 2. \n");
    else    
        printf("Is the power of 2. \n");
}

void swap(uint32_t *a, uint32_t *b)
{
    *b = *a ^ *b; // a ^ b 是为了表明位数不同之处，再将不同之处反转即可得对方
    *a ^= *b;
    *b ^= *a;
}

uint32_t reverseBits(uint32_t n)
{
    uint32_t result = 0;
    for(int i = 0; i < 32; i++)
    {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }
    return result;
}

uint32_t rotateLeft(uint32_t n, uint32_t k)
{
    for (int i = 0; i < k; i++)
    {
        n = (n << 1) | (n >> 31);
    }
    return n;
}

//分治法！！！！！！！！！！！！！ （类似于merge sort）
uint32_t reverseBits2(uint32_t n) {
    n = (n >> 1)  & 0x55555555 | (n & 0x55555555) << 1;
    n = (n >> 2)  & 0x33333333 | (n & 0x33333333) << 2;
    n = (n >> 4)  & 0x0F0F0F0F | (n & 0x0F0F0F0F) << 4;
    n = (n >> 8)  & 0x00FF00FF | (n & 0x00FF00FF) << 8;
    n = (n >> 16) & 0x0000FFFF | (n & 0x0000FFFF) << 16;
    return n;
}

/*生成位掩码 问题：编写函数generateMask，生成低n位为1的掩码。*/

uint32_t generateMask(uint32_t n) //good method
{
    uint32_t result = 0;
    if (n >= 32) {return 0xffffffff;}
    else if(n == 0) {return 0;}
    else    
        return ((1 << n) - 1);
}

//接受两个无符号整数，返回二进制中不同位的个数。
uint32_t hammingDistance(uint32_t a, uint32_t b)
{
    a = a ^ b; //the different digits will become 1
    uint32_t n = 0;
    while (a != 0)
    {
        a = a & (a -1);
        n ++;
    }
    return n;
}

uint32_t assembleBits(uint8_t a, uint8_t b, uint8_t c) //a has four bits, b has three bits, c has five bits
{
    uint32_t result = 0;
    result = (a << 3) | b;
    result = (result << 5) | c;
    return result;
}

uint32_t add(uint32_t a, uint32_t b)
{
    if ((a & b) == 0)
        return a|b;
    else 
        return add((a & b) << 1, (a ^ b));
}

uint32_t add2(uint32_t a, uint32_t b) //相较于递归，此方法使用迭代更佳
{
    while (b != 0) {
        uint32_t carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}


uint64_t times(uint32_t a, uint32_t b)
{
    uint32_t cnt = 0;
    uint64_t result = 0;
    while (b != 0)
    {
        if (b & 1)
        {
            result += (a<<cnt);
        }
        cnt ++;
        b >>= 1;
    }
    return result;
}


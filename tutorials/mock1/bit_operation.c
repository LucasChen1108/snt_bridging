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

uint32_t isPowerOf2(uint32_t n)
{
    if(n & (n-1))
    {
        printf("Isn't the power of 2. \n");
    }
    else    
        printf("Is the power of 2. \n");
}

uint32_t swap(uint32_t a, uint32_t b)
{
    b = a ^ b; // a ^ b 是为了表明位数不同之处，再将不同之处反转即可得对方
    a ^= b;
    b ^= a;
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
uint32_t reverseBits(uint32_t n) {
    n = (n >> 1)  & 0x55555555 | (n & 0x55555555) << 1;
    n = (n >> 2)  & 0x33333333 | (n & 0x33333333) << 2;
    n = (n >> 4)  & 0x0F0F0F0F | (n & 0x0F0F0F0F) << 4;
    n = (n >> 8)  & 0x00FF00FF | (n & 0x00FF00FF) << 8;
    n = (n >> 16) & 0x0000FFFF | (n & 0x0000FFFF) << 16;
    return n;
}

/*
高级题目

位域打包日期
问题：定义结构体，使用位域存储日期（日5位、月4位、年7位），编写函数打包和解包。

生成位掩码
问题：编写函数generateMask，生成低n位为1的掩码。

计算汉明距离
问题：编写函数hammingDistance，接受两个无符号整数，返回二进制中不同位的个数。

位组装
问题：编写函数assembleBits，将3个小位段（4位、3位、5位）组装成一个整数。

位操作加法
问题：编写函数add，仅用位操作实现两个整数加法，不用+。

*/
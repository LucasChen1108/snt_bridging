// This method is using bit operation
#include <stdio.h> 
#include <math.h>
#include <stdint.h> //！！！better deal with different length
/*
| 格式符  | 类型                  | 意义                         |
| ------ | -------------------- | ---------------------------- |
| `%d`   | `int`                | 有符号十进制整数                |
| `%u`   | `unsigned int`       | 无符号十进制整数                |
| `%hd`  | `short`              | 有符号短整型（一般为 16 位）     |
| `%hu`  | `unsigned short`     | 无符号短整型                   |
| `%ld`  | `long`               | 有符号长整型（通常 32 或 64 位） |
| `%lu`  | `unsigned long`      | 无符号长整型                   |
| `%lld` | `long long`          | 有符号 64 位整型               |
| `%llu` | `unsigned long long` | 无符号 64 位整型               |
*/

void bi_convert(uint64_t n)
{
    for (int i = 31; i >= 0; i--)
        printf("%d", (int)((n >> i) & 1));
    printf("\n");
}

uint32_t interleave(uint16_t x, uint16_t y) 
{
    uint32_t result = 0;
    for (int i = 0; i < 32; i += 2) {
        result |= ((x >> (i / 2)) & 1) << i;
        result |= ((y >> (i / 2)) & 1) << (i + 1);
    }
    return result;
    /* alternative
    for(int i = 0; i < 32; i = i+2)
        {
            inter += ((x >> cntx) & 1) * pow(2, i);
            cntx++;
            inter += ((y >> cnty) & 1) * pow(2, (i + 1));
            cnty++;
        }
    */
}

int main()
{
    uint16_t x, y;
    char quit;
    do
    {
        do
        {
            printf("Enter x: ");
            scanf("%hd", &x);
        }while(x < 0 || x > 65535);
        printf("\n");
        do
        {
            printf("Enter y: ");
            scanf("%hd", &y);
        }while(y < 0 || y > 65535);
        printf("\n");

        uint32_t inter = interleave(x, y);
    
        printf("x = %5u  ", x);
        bi_convert(x);
        printf("y = %5u  ", y);
        bi_convert(y);
        printf("interleaved = %u  ", inter);
        bi_convert(inter);

        printf("\nContinue (y/n): ");
        scanf("%*c%c", &quit);
    }while (quit == 'y');
    return 0;
}
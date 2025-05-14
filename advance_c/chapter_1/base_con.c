#include<stdio.h>
#include<stdlib.h>
#define MAX_DIGITS 32

int main(int argc, char *argv[])
{
    int num, rm, base, cnt = 0;
    char answer[MAX_DIGITS];
    if(argc != 3)
    {
        printf("Wrong Format!\n");
        printf("The format should be: ./base_con (num to convert) base\n");
        exit(1);
    }
    base = atoi(argv[2]);
    if (base > 8 || base < 2)
    {
        printf("base should larger than 1 and smaller than 9\n");
        exit(1);
    }

    num = atoi(argv[1]);
    if (num < 0)
    {
        putchar('-');
        num = -num;
    }

    while(num != 0)
    {
        if (cnt >= MAX_DIGITS - 1) {  // 防止越界
            fprintf(stderr, "Result too large for buffer\n");
            exit(1);
        }
        rm = num % base;
        answer[cnt] = rm + '0';
        cnt++;
        num = num / base;
    }

    while(cnt != 0)
    {
        cnt--;
        putchar(answer[cnt]);
    }
    putchar('\n');
    return 0;
}
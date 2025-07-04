#include <stdio.h>

int isHammingNumber(int num)
{
    while(num%2 == 0) num /= 2;
    while(num%5 == 0) num /= 5;
    while(num%3 == 0) num /= 3;
    if(num == 1) return 1;
    return 0;
}

int main()
{
    int num;
    printf("A number: ");
    scanf("%d", &num);
    if(isHammingNumber(num))
        printf("Yes.\n");
    else
        printf("No. \n");
    return 0;
}
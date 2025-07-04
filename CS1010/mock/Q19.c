#include<stdio.h>

void rdup(int n, int d)
{
    if(n == 0) return;
    else if(n % 10 == d) rdup(n / 10, d);
    else{
        int digit = n % 10;
        printf("%d", digit);
        rdup(n / 10, d);
        printf("%d", digit);
    }
}

int main()
{
    printf("The number: ");
    int n, d;
    scanf("%d", &n);
    printf("d:");
    scanf("%d", &d);
    rdup(n, d);
    printf("\n");
    return 0;
}
// This method is not using bit operation
#include <stdio.h> 
#include <math.h>

void binary_convert(int x, int *p);
void print_binary(int *p);
long long merge(int *bx, int *by, int *bi);

int main()
{
    int x, y, interleaved;
    char quit;
    int bi_x[32] = {0}, bi_y[32] = {0}, bi_i[32] = {0};
    long long answer;
    do
    {
        do
        {
            printf("Enter x: ");
            scanf("%d", &x);
        }while(x < 0 || x > 65535);
        do
        {
            printf("Enter y: ");
            scanf("%d", &y);
        }while(y < 0 || y > 65535);
    
        binary_convert (x, bi_x);
        binary_convert (y, bi_y);
        printf("\nx = %5d  ", x);
        print_binary(bi_x);
        printf("y = %5d  ", y);
        print_binary(bi_y);

        answer = merge(bi_x, bi_y, bi_i);
        printf("interleaved = %lld  ", answer);
        print_binary(bi_i);

        printf("\nContinue (y/n): ");
        scanf("%*c%c", &quit);
    }while (quit == 'y');
    return 0;
}

void binary_convert(int x, int *p)
{
    int cnt = 31;
    while(x != 0)
    {
        p[cnt--] = x % 2;
        x /= 2;
    }
}

void print_binary(int *p)
{
    for(int i = 0; i < 32; i++)
        printf("%d", p[i]);
    printf("\n"); 
}

long long merge(int *bx, int *by, int *bi)
{
    long long answer = 0;
    int cntx = 16, cnty = 16;
    for (int i = 0; i < 32; i++)
    {
        if(i % 2 == 0)
        {
            bi[i] = by[cnty];
            answer += pow(2, 31-i) * by[cnty];
            cnty++;
        }
        else
        {
            bi[i] = bx[cntx];
            answer += pow(2, 31-i) * bx[cntx];
            cntx++;
        }
    }
    return answer;
}
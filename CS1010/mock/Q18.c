#include<stdio.h>

void reorgnized(int num[], int size)
{
    int cnt = 0, temp;
    for (int i = 0; i < size; i++)
    {
        if (num[i] % 2 == 1)
        {
            temp = num[i];
            for (int j = i - 1; j >= cnt; j--)
                num[j + 1] = num[j]; 
            num[cnt] = temp;
            cnt++;
        }
    }
}

int main()
{
    int num[] = {19, 33, 24, 15, 22, 17};
    int size = 6;
    reorgnized(num, size);
    for(int i = 0; i < size; i++) printf("%d ", num[i]);
    printf("\n");
    return 0;
}
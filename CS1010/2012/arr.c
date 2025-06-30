#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define SIZE 100
#define MIN 2
#define MAX 10

int main()
{
    int arr[SIZE], check[MAX-MIN+1][2];

    for(int i=MIN; i <= MAX; i++)
    {
        check[i-MIN][0] = i;
        check[i-MIN][1] = 0;
    }

    srand(time(NULL));
    for(int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % (MAX-MIN+1) + MIN;
        check[arr[i]][1]++;
    }

    int max = 0;
    int index = 0;
    for(int i = MIN; i <= MAX; i++)
    {
        if(check[i][1] > max)
        {
            index = i;
            max = check[i][1];
        }
    }
    printf("Most appeared number: %d         Time of appearing: %d\n", index, max);
    return 0;
}

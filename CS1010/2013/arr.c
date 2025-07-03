#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define SIZE 100
#define MAX 100000
int minDiff(int arr[]);


int main()
{
    int visited[MAX/3] = {0};
    int arr[100], temp;
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++)
    {
        do{
            temp = rand()%(MAX/3);
        }while(visited[temp] == 1);
        visited[temp] = 1;
        arr[i] = temp * 3;
    }

    printf("The smallest difference is: %d\n", minDiff(arr));
}

int minDiff(int arr[])
{
    int store[10][SIZE], digit, cnt;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < SIZE; j++)
            store[i][j] = -1;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            cnt = 0;
            digit = (arr[j]/(int)pow(10, i)) % 10;
            while(store[digit][cnt] != -1)
                cnt++;
            store[digit][cnt] = arr[j];
        }
        int idx = 0;
        for(int k = 0; k < 10; k++)
        {
            int r = 0;
            while(store[k][r] != -1)
                arr[idx++] = store[k][r++];
        }

        for(int x = 0; x < 10; x++)
            for(int y = 0; y < SIZE; y++)
                store[x][y] = -1;
    }
//find difference
    int min = 100000;
    for(int i = 0; i < SIZE-1; i++)
    {
        if(abs(arr[i]-arr[i+1]) < min)
            min = abs(arr[i]-arr[i+1]);
    }
    return min;
}

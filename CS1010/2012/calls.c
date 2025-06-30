#include<stdio.h>
#include<stdlib.h>
#define MAX_ROUTE 100

void readFile(int route[][2], int *size, int *route_cnt)
{
    FILE *indata = fopen("calls.in", "r");
    fscanf(indata, "%d %d", size, route_cnt);
    for(int i = 0; i < *route_cnt; i++)
    {
        fscanf(indata, "%d %d", &route[i][0], &route[i][1]);
    }
    fclose(indata);
}

int countRecursive(int route[][2], int size, int route_cnt)
{
    int cnt = 0, occu[size];
    for (int i = 0; i < size; i++)
        occu[i] = 0;  
    for(int i = 0; i < route_cnt; i++)
    {
        if(route[i][0] == route[i][1])
        {
            if(occu[route[i][0]] == 0)
            {
                occu[route[i][0]] = 1;
                cnt++;
            }
        }
    }
    return cnt;
}

int countDiretCalls(int route[][2], int size, int route_cnt, int f)
{
    int cnt = 0, occu[size];
    for (int i = 0; i < size; i++)
        occu[i] = 0;  
    for(int i = 0; i < route_cnt; i++)
    {
        if(route[i][0] == f)
        {
            if(occu[route[i][1]] == 0)
            {
                occu[route[i][1]] = 1;
                cnt++;
            }
        }
    }
    return cnt;
}

int canReach(int route[][2], int size, int route_cnt, int f, int g)
{
    if(f == g) return 1;
    int visited[size];
    for (int i = 0; i < size; i++)
        visited[i] = 0;  
    visited[f] = 1;

    for(int i = 0; i < route_cnt; i++)
    {
        if(route[i][0] == f)
        {
            int next = route[i][1];
            if(next == g)
                return 1;
            if(visited[next] == 0 && canReach(route, size, route_cnt, next, g))
                return 1;
        }

    }
    return 0;
}

int main()
{
    int route[MAX_ROUTE][2], size = 0, route_cnt = 0, f, g;
    readFile(route, &size, &route_cnt);
    printf("(b) Number of recursive functions = %d\n", countRecursive(route, size, route_cnt));
    printf("(c) Enter function number (0 - %d): ", size-1);
    scanf("%d", &f);
    printf("Function %d calls %d function(s) directly. \n", f, countDiretCalls(route,size,route_cnt,f));
    printf("Enter 'source' and 'destination' functions: ");
    scanf("%d%d", &f, &g);
    if(canReach(route, size, route_cnt, f, g))
        printf("Function %d calls function %d, directly or inderectly.\n", f, g);
    else
        printf("function %d does not call function %d, directly or inderectly\n", f, g);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_PARKING_UNIT 9000 
#define LENGTH_OF_CAR 8 
#define MAX_NUM_ROUND 10000
int parkingUnits[MAX_PARKING_UNIT] = {0};

int parkingCar(int x)
{
    for(int i = x; i < x+LENGTH_OF_CAR; i++)
    {
        if (parkingUnits[i] == 1)
            return 0;
    }
    for(int i = x; i < x+LENGTH_OF_CAR; i++)
    {
        parkingUnits[i] = 1;
    }
    return 1;
}

int main()
{
    int occupied = 0;
    srand(time(NULL));
    int x;
    for(int i = 0; i < MAX_NUM_ROUND; i++)
    {
        x = rand() % MAX_PARKING_UNIT;
        if(parkingCar(x))
            occupied += LENGTH_OF_CAR;
    }
    float utilizationRate = (float)occupied / MAX_PARKING_UNIT * 100; 
    printf("Utilization rate of the roadside: %.2f%%\n", utilizationRate);
    return 0;
}
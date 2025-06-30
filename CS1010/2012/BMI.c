#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float height;
    float mass;
    float bmi;
    int riskType;
} record;

int main()
{
    record *storage = (record *)malloc(sizeof(record));
    if (storage == NULL)
    {
        printf("Memory allocation failed.\n\n");
        exit(1);
    }
    printf("Height(in meter): ");
    scanf("%f", &storage->height);
    printf("Mass(in kilograms): ");
    scanf("%f", &storage->mass);
    storage->bmi = (float)((int)((storage->mass / (storage->height * storage->height)) * 10 + 0.5)) / 10;
    if(storage->bmi >= 27.5)
        storage->riskType = 2;
    else if(storage->bmi >= 23.0)
        storage->riskType = 1;
    else if(storage->bmi >= 18.5)
        storage->riskType = 0;
    else
        storage->riskType = -1;
    
    printf("%d\n", storage->riskType);
    free(storage);
    return 0;
}
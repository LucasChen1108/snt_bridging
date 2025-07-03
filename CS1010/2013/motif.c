#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct{
    int rows, cols;
}dim_t;

typedef struct{
    dim_t dim;
    int grid[MAX][MAX];
}grid_t;

void readFile(grid_t *plot, grid_t *motif)
{
    FILE *indata = fopen("motif.in", "r");
    if(indata == NULL)
    {
        printf("Fail to read the file.\n\n");
        exit(1);
    }

    fscanf(indata, "%d %d", &plot->dim.rows, &plot->dim.cols);
    fscanf(indata, "%d %d", &motif->dim.rows, &motif->dim.cols);
    for(int i = 0; i < motif->dim.rows; i++)
    {
        for(int j = 0;  j < motif->dim.cols; j++)
            fscanf(indata, "%d", &motif->grid[i][j]);
    }
    fclose(indata);
}

void fillPlot(grid_t *plot, grid_t *motif)
{
    int i, j;
    int rows_size = motif->dim.rows;
    int cols_size = motif->dim.cols;

    for (i = 0; i < plot->dim.rows; i++) {
        for (j = 0; j < plot->dim.cols; j++) {
            plot->grid[i][j] = motif->grid[i % rows_size][j % cols_size];
        }
    }
}

void printGrid(grid_t *plot)
{
    for(int i = 0; i < plot->dim.rows; i++)
    {
        for(int j = 0; j < plot->dim.cols; j++)
            printf("%d ", plot->grid[i][j]);
        printf("\n");
    }
}

int main()
{
    grid_t plot, motif;
    readFile(&plot, &motif);
    fillPlot(&plot, &motif);
    printGrid(&plot);
    return 0;
}

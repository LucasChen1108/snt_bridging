#include<stdio.h>
#include<stdlib.h>
#define N 50

typedef struct{
    int x;
    int y;
}coord_t;
void readMap(int map[][N], int *m, int *n);
void prtMap(int map[][N], int m, int n);
void read2Corners(coord_t *c1, coord_t *c2);
void findCorners(coord_t c1, coord_t c2, coord_t corners[4]);
void fillSpace(int map[][N], coord_t top_left, coord_t bottom_right);
void drawBorders(int map[][N], int rows, int cols);
void touch(int map[][N], int rows, int cols);

int main()
{
    int opt, quit = 1, m = 0, n = 0;
    int map[N][N] = {{0,0}};
    coord_t c1, c2, corners[4];
    readMap(map, &m, &n);
    prtMap(map, m, n);
    do
    {
        printf("Enter opetion number [0 to 4]; other integer to get out : ");
        scanf("%d", &opt);
        switch (opt)
        {
            case 0:
                printf("Print the current map.\n");
                prtMap(map, m, n);
                printf("++++++++++++++++++++++\n");
                break;
            case 1:
                printf("Find Corners.\n");
                printf("+++++++++++++\n");
                read2Corners(&c1, &c2);
                findCorners(c1, c2, corners);
                break;
            case 2:
                printf("Map Filling Operation.\n");
                printf("++++++++++++++++++++++\n");
                read2Corners(&c1, &c2);
                findCorners(c1, c2, corners);
                fillSpace(map, corners[0], corners[3]);
                break;
            case 3:
                printf("Display Map Borders.\n");
                printf("++++++++++++++++++++++\n");
                drawBorders(map, m, n);
                break;
            case 4:
                printf("Map Touching Operation.\n");
                printf("++++++++++++++++++++++\n");
                touch(map, m, n);
                break;
            default:
                quit = 0;
                printf("The End.\n");
                break;
        }
    }while(quit);
}

void readMap(int map[][N], int *m, int *n)
{
    int num;
    printf("Read in number of rows: ");
    scanf("%d", m);
    printf("Read in number of columns: ");
    scanf("%d", n);
    printf("Read in the map of %dX%d\n", *m, *n);
    for(int i = 0; i < *m; i++)
    {
        for(int j = 0; j < *n; j++)
            scanf("%d", &map[i][j]);
    }
    //Illegal Input
}

void prtMap(int map[][N], int m, int n)
{
    printf("   ");
    int j = 0;
    while(j < n)
        printf("%3d", j++);
    printf("*\n");

    printf("--+");
    for(int k = 0; k < n; k++)
        printf("---");
    printf("*\n");

    for(int i = 0; i < m; i++)
    {
        printf("%2d|",i);
        for(int j = 0; j < n; j++)
            printf("%3d", map[i][j]);
        printf("*\n");
    }
}

void read2Corners(coord_t *c1, coord_t *c2)
{
    printf("Please enter the first corner: ");
    scanf("%d", &(c1->x));
    scanf("%d", &(c1->y));
    printf("Please enter the corresponding diagonal corner: ");
    scanf("%d", &(c2->x));
    scanf("%d", &(c2->y));
}

void findCorners(coord_t c1, coord_t c2, coord_t corners[4])
{
    int minX = c1.x < c2.x ? c1.x : c2.x;
    int maxX = c1.x > c2.x ? c1.x : c2.x;
    int minY = c1.y < c2.y ? c1.y : c2.y;
    int maxY = c1.y > c2.y ? c1.y : c2.y;

    // Top-left
    corners[0].x = minX;
    corners[0].y = minY;

    // Top-right
    corners[1].x = minX;
    corners[1].y = maxY;

    // Bottom-left
    corners[2].x = maxX;
    corners[2].y = minY;

    // Bottom-right
    corners[3].x = maxX;
    corners[3].y = maxY;

    printf("Top-left Corner: %d, %d\n", corners[0].x, corners[0].y);
    printf("Top-right Corner: %d, %d\n", corners[1].x, corners[1].y);
    printf("Bottom-left Corner: %d, %d\n", corners[2].x, corners[2].y);
    printf("Bottom-right Corner: %d, %d\n", corners[3].x, corners[3].y);
}

void fillSpace(int map[][N], coord_t top_left, coord_t bottom_right)
{
    int num;
    printf("Enter number to be filled in: ");
    scanf("%d", &num);
    for(int i = top_left.x; i <= bottom_right.x; i++)
    {
        for (int j = top_left.y; j <= bottom_right.y; j++)
            map[i][j] = num;
    }
}

void drawBorders(int map[][N], int rows, int cols)
{
    int key;
    printf("Read in a number: ");
    scanf("%d", &key);
    char new_map[2*rows+1][3*cols + 2];
    for (int i = 0; i < 2 * rows + 1; i++) 
    {
        for (int j = 0; j < 3 * cols + 1; j++) 
            new_map[i][j] = ' ';
        new_map[i][3*cols +1] = '*';
    }//初始化

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            new_map[1+2*i][2+3*j] = map[i][j] + '0';
            if(map[i][j] == key)
            {
                int r = 1 + 2 * i;
                int c = 3 * j + 2;

                // 上方不是 key，画上边
                if (i == 0 || map[i - 1][j] != key) 
                {
                    new_map[r-1][c]     = '-';
                    new_map[r-1][c -1] = '-';
                }

                // 下方不是 key，画下边
                if (i == rows - 1 || map[i + 1][j] != key) 
                {
                    new_map[r + 1][c]     = '-';
                    new_map[r + 1][c - 1] = '-';
                }

                // 左边不是 key，画左边
                if (j == 0 || map[i][j - 1] != key) 
                {
                    new_map[r][c-2] = '|';
                }

                // 右边不是 key，画右边
                if (j == cols - 1 || map[i][j + 1] != key) 
                {
                    new_map[r][c+1] = '|';
                }
            }
        }
    }

    //print out the new matirix
    for(int i = 0; i < 2*rows+1; i++)
    {
        for(int j = 0; j < 3*cols+2; j++)
            printf("%c", new_map[i][j]);
        printf("\n");
    }
}

void touch(int map[][N], int rows, int cols)
{
    coord_t c1, c2, corners[4], touch;
    int virus, key, ref[rows][cols];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
                ref[i][j] = 0;//初始化
    read2Corners(&c1, &c2);
    findCorners(c1, c2, corners);
    printf("Enter the coordinate of a location to touch: ");
    scanf("%d%d", &touch.x, &touch.y);
    printf("Choose a number to spread: ");
    scanf("%d", &virus);
    key = map[touch.x][touch.y];
    map[touch.x][touch.y] = virus;

    //在该限定函数内无法进行递归操作:(, 只能每次都遍历map，并记录是否成功拓展，若有拓展则需继续进行
    int change;
    ref[touch.x][touch.y] = 1;
    do
    {
        change = 0;
        for(int i = corners[0].x; i <= corners[3].x; i++)
        {
            for(int j = corners[0].y; j <= corners[3].y; j++)
            {
                if(ref[i][j])
                {
                    //上方
                    if (i-1 >= corners[0].x && map[i - 1][j] == key && ref[i-1][j] != 1) 
                    {
                        ref[i-1][j] = 1;
                        map[i-1][j] = virus;
                        change = 1;
                    }

                    // 下方
                    if (i+1 <= corners[3].x && map[i + 1][j] == key && ref[i+1][j] != 1) 
                    {
                        ref[i+1][j] = 1;
                        map[i+1][j] = virus;
                        change = 1;
                    }

                    // 左边
                    if (j-1 >= corners[0].y && map[i][j-1] == key && ref[i][j-1] != 1) 
                    {
                        ref[i][j-1] = 1;
                        map[i][j-1] = virus;
                        change = 1;
                    }

                    // 右边
                    if (j+1 <= corners[3].y && map[i][j+1] == key && ref[i][j+1] != 1) 
                    {
                        ref[i][j+1] = 1;
                        map[i][j+1] = virus;
                        change = 1;
                    }
                }
            }
        }
        
    } while(change);
}
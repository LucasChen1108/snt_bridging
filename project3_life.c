#include <stdio.h>
#define MAXSIZE 48
void read_soc(int soc[][MAXSIZE], int size);
void print_soc(int soc[][MAXSIZE], int size);
int population(int soc[][MAXSIZE], int size);
void evolve_soc(int soc[][MAXSIZE], int size);
int destiny(int soc[][MAXSIZE], int row, int col, int size); 
void generate(int soc[][MAXSIZE], int size, int gen) ;
void census(int soc[][MAXSIZE], int size, int pop[]);
void migrate(int soc[][MAXSIZE], int size, int pop[]);
int main()
{
    int size,gen,pop[MAXSIZE];
    printf("Read the boundary size: ");
    scanf("%d", &size);
    printf("Build the society. \n");
    int soc[size][MAXSIZE];
    read_soc(soc, size);
    printf("New Life: \n");
    print_soc(soc, size);
    printf("\n\n");
    evolve_soc(soc, size);
    printf("After one evolution: \n");
    printf("++++++++++++++++++++++++++++++\n");
    print_soc(soc, size);
    printf("\n\n");
    scanf("%d", &gen);
    printf("Evolution begins \n");
    printf("++++++++++++++++++++++++++++++\n");
    generate(soc, size, gen);
    printf("\n\n");
    census(soc, size, pop);
    printf("\n\n");
    migrate(soc, size, pop);
    return 0;
}

void read_soc(int soc[][MAXSIZE], int size)
{
    char temp;
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            scanf(" %c", &temp);
            if (temp == '*')
                soc[i][j] = 1;
            else 
                soc[i][j] = 0;
        }
    }
}

void print_soc(int soc[][MAXSIZE], int size)
{
    int i, j;
    printf("/");
    for(i = 0; i < size; i++)
        printf("oo");
    printf("o");
    printf("\\\n");
    for (i = 0; i < size; i++)
    {
        printf("| ");
        for (j = 0; j < size; j++)
        {
            if(soc[i][j] == 1)
                printf("* ");
            else
                printf("- ");
        }
        printf("|\n");
    }
    printf("\\");
    for(i = 0; i < size; i++)
        printf("oo");
    printf("o");
    printf("/\n");
    printf("The number of inhabitants is: %d\n", population(soc, size));
}

int population(int soc[][MAXSIZE], int size)
{
    int i, j, pop = 0;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (soc[i][j] == 1)
                pop++;
        }
    }
    return pop;
}

void evolve_soc(int soc[][MAXSIZE], int size)
{
    int temp[MAXSIZE][MAXSIZE]; 
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            temp[i][j] = destiny(soc, i, j, size);
        }
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            soc[i][j] = temp[i][j];
        }
    }
}

int destiny(int soc[][MAXSIZE], int row, int col, int size)
{
    int i, j, count = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
                continue; 

            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size)
            {
                if (soc[newRow][newCol] == 1)
                    count++;
            }
        }
    }
    if (soc[row][col] == 1)
    {
        if (count == 2 || count == 3)
            return 1;
        else
            return 0;
    }
    else
    {
        if (count == 3)
            return 1;
        else
            return 0;
    }
}

void generate(int soc[][MAXSIZE], int size, int gen) 
{
    int i, j, r;
    int is_same;
    int prev[MAXSIZE][MAXSIZE]; 

    for (i = 0; i < gen; i++)
    {
        // Save the current state to prev
        for (j = 0; j < size; j++)
        {
            for (r = 0; r < size; r++)
            {
                prev[j][r] = soc[j][r];
            }
        }
        evolve_soc(soc, size);
        // Check if the society has died
        if (population(soc, size) == 0)
        {
            printf("The society has died after %d generations.\n", i + 1);
            print_soc(soc, size); // Print the final state
            return;
        }
        // Check if the society has stabilized
        is_same = 1; // Reset is_same for each generation
        for (j = 0; j < size; j++)
        {
            for (r = 0; r < size; r++)
            {
                if (prev[j][r] != soc[j][r])
                {
                    is_same = 0; // States are different
                    break;
                }
            }
            if (!is_same)
                break;
        }
        if (is_same)
        {
            print_soc(soc, size);
            printf("The society stablelizes at evolution %d.\n", i);
            return;
        }
    }
    // If the loop completes, the society is still evolving
    print_soc(soc, size);
    printf("Evolution continues after %d evolutions.\n", gen);
    
}

void census(int soc[][MAXSIZE], int size, int pop[])
{
    int i,j;
    printf("Census Result: \n");
    printf("++++++++++++++++++++++++++++++\n");
    printf("[");
    for(i = 0; i < size; i++)
    {
        pop[i] = 0;
        for(j = 0; j < size; j++)
        {
            if(soc[i][j] == 1)
                pop[i]++;
        }
        printf("%2d", pop[i]);
    }
    printf(" ]\n");
}

void migrate(int soc[][MAXSIZE], int size, int pop[])
{
    int census_data[MAXSIZE][2]; // Array to store population and row indices
    int temp[MAXSIZE][MAXSIZE];  
    int i, j;

    for (i = 0; i < size; i++)
    {
        census_data[i][0] = pop[i]; // Population count
        census_data[i][1] = i;      // Row index
    }

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (census_data[j][0] < census_data[j + 1][0])
            {
                int temp_pop = census_data[j][0];
                census_data[j][0] = census_data[j + 1][0];
                census_data[j + 1][0] = temp_pop;

                int temp_index = census_data[j][1];
                census_data[j][1] = census_data[j + 1][1];
                census_data[j + 1][1] = temp_index;
            }
        }
    }
    // Rebuild the society based on the sorted row indices
    for (i = 0; i < size; i++)
    {
        int row_index = census_data[i][1]; // Get the original row index
        for (j = 0; j < size; j++)
        {
            temp[i][j] = soc[row_index][j]; // Copy the row to the new position
        }
    }
    printf("After Migration:\n");
    printf("++++++++++++++++++++++++++++++\n");
    print_soc(temp, size);
}
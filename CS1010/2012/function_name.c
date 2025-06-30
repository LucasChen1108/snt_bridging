#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 20
#define NUM_FUNCTIONS 5

void convert(char fname[]);
int search(char functions[][MAX_LENGTH+1], int size, char fname[]);

int main(void) {
    char functions[NUM_FUNCTIONS][MAX_LENGTH+1] = { "main", "abc", "d_e_f", "pqr__st","kkkkkmmmmmrrrrrsssss"};
    char fname[MAX_LENGTH+1];

    printf("Enter function name: ");
    fgets(fname, MAX_LENGTH+1, stdin);
    convert(fname);

    printf("fname found at position %d\n", search(functions, NUM_FUNCTIONS, fname));
    return 0;
}

void convert(char fname[])
{
    for(int i = 0; i < MAX_LENGTH && fname[i] != '\0'; i++)
        if(fname[i] == ' ')
            fname[i] = '_';
        else if(fname[i] == '\n')
            fname[i] = '\0';
}

int search(char functions[][MAX_LENGTH+1], int size, char fname[])
{
    for(int i = 0; i < size; i++)
    {
        if(strcmp(functions[i], fname) == 0)
            return i;
    }
    return -1;
}
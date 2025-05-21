#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Error! There is no text input\n");
        exit(1);
    }
    int j = 0;
    for (int i = 1; i < argc; i++)
    {
        j = 0;
        while(argv[i][j] != '\0')
        {
            if (isalpha(argv[i][j]))
            {
                printf("%c", toupper(argv[i][j]));
            }
            else
                printf("%c", argv[i][j]);
            j++;
        }
        printf("\n");
    }
    return 0;
}
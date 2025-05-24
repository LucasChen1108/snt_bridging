#include <stdio.h>
#include <stdlib.h>

typedef struct tray{
    int value;
    struct tray *below;
} tray;

tray *top = NULL;
int currsize = 0;

void push(int n);
int pop(void);
void free_all(void);

int main()
{
    int temp = 0, devider, this1;
    char a, trash;
    FILE *indata = fopen("postfix.inf", "r");
    if (indata == NULL)
    {
        printf("Fail to open the file.");
        exit(1);
    }
    while (fscanf(indata, "%c", &a) == 1)
    {
        if (a == 'X') break;
        printf("%c", a);
        switch(a)
        {
            case '-':
                temp = pop();          
                temp = pop() - temp;   
                push(temp);
                break;
            case '+':
                temp = pop();
                temp += pop();
                push(temp);
                break;
            case '/':
                devider = pop();
                if (devider == 0) 
                {
                    printf("Error: Division by zero\n");
                    free_all();
                    fclose(indata);
                    exit(1);
                }
                temp = pop() / devider;
                push(temp);
                break;
            case '*':
                temp = pop();
                temp *= pop();
                push(temp);
                break;
            case ' ':
                break;
            case '=':
                if (currsize < 1) {
                    printf("\nError: Stack empty at =\n");
                    continue;
                }
                printf("%d\n", top->value);
                fscanf(indata, "%c", &trash); // Consume newline
                break;
            case '\n':
                break;
            default:
               if (a >= '0' && a <= '9') 
                    push(a - '0');
                else 
                {
                    printf("\nError: Invalid character '%c'\n", a);
                    // Skip to newline to handle invalid line
                    while (fscanf(indata, "%c", &trash) == 1 && trash != '\n');
                }
        }
    }
    free_all();
    fclose(indata);
    return 0;
}

void push(int n)
{
    tray *this;
    this = (tray *)malloc(sizeof(tray));
    if (this == NULL)
    {
        printf("Memory allocation failed. \n");
        free_all();
        exit(1);
    } 
    this->value = n;
    this->below = top;
    top = this;
    currsize++;
}

int pop(void)
{
    if (currsize < 1) 
        return 0;   
    tray *ptr = top;
    int value = ptr->value; // Save the value
    top = top->below;       // Update top
    free(ptr);              // Free the node
    currsize--;             // Update size
    return value;           // Return the value
}

void free_all(void)
{
    tray *ptr;
    while (top != NULL)
    {
        ptr = top;
        top = top->below;
        free(ptr);
    }
}
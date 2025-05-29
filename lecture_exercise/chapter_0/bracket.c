#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    char bracket;
    struct stack *below;
}stack;

stack *top = NULL;
void free_all(void)
{
    stack *temp;
    while (top != NULL)
    {
        temp = top;
        free(temp);
        top = top->below;
    }
}

void push(char c)
{
    stack *this1 = (stack *)malloc(sizeof(stack));
    if (this1 == NULL)
    {
        printf("Allocation fail \n");
        free_all();
        exit(1);
    }
    this1->bracket = c;
    this1->below = top;
    top = this1;
}

char pop(void)
{   
    if (top == NULL)
    {
        printf("EMPTY STACK.\n");
        return 0;
    }
    char c = top->bracket;
    stack *temp = top;
    top = top->below;
    free(temp);
    return c;
}

int is_match(char open, char close)
{
    return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}

int main()
{
    char sign;
    printf("Enter a sentence to check if the brackets are correctly paired: ");
    while(scanf("%c", &sign) == 1  && sign != '\n') //scanf 会读改行的换行符并且只要没有遇到EOF就不会停止，所以需要单独处理换行符
    {
        if (sign == '(' || sign == '{' || sign == '[')
        {
            push(sign);
        }
        if (sign == ')' || sign == '}' || sign == ']')
        {
            char last = pop();
            if(!is_match(last, sign))
            {
                printf("do not match! \n");
                free_all();
                return 0;
            }
        }
    }
    if (top == NULL)
        printf("Match !\n");
    else
    {
        printf("Brackets do not match! (unmatched left brackets)\n");
        free_all();
        return 1;
    }

    free_all();
    return 0;
}
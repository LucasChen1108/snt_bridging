#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct tray{
    char color[10];
    int id;
    struct tray *below;
}node;
node *top = NULL;
int cnt = 0;
void get_data(node *ptr);
void put_data(const node *ptr);
node *pop(void), *push(node this1);

int main()
{
    node this1, *ptr;
    int opt, quit;
    do
    {
        do
        {
            printf("\nEnter 1 to push, 2 to pop: ");
            scanf("%d", &opt);
            printf("\n");
            switch(opt)
            {
                case 1: 
                    get_data(&this1);
                    if(push(this1) == NULL)
                        printf("STACK FULL\n");
                    break;
                case 2:
                    if((ptr=pop()) != NULL)
                        put_data(ptr);
                    else
                        printf("STACK EMPTY\n");
                    break;
                default:
                    printf("ILLEGAL RESPONSE\n");
                break;
            }
        } while (opt != 1 && opt != 2);
        printf("\n1 to continue, 0 to quit: ");
        scanf("%d", &quit);
    }while(quit);
    return 0;
}

void get_data(node *ptr)
{
    printf("Enter the tray's color: ");
    scanf("%s", ptr->color);
    printf("Enter the tray's id: ");
    scanf("%d", &(ptr->id));
}

void put_data(const node *ptr)
{
    printf("Tray's color: %s\n", ptr->color);
    printf("Tray's id: %d\n", ptr->id);
    printf("cnt=%d\n", cnt);
}

node *push(node this1)
{
    node *ptr;
    if (cnt >= SIZE)
        return NULL;
    ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
        printf("NO MORE MEMORY TO ALLOCATE");
    *ptr = this1;
    cnt++;
    ptr->below = top;
    top = ptr;
    printf("cnt=%d\n", cnt);
    return ptr;
}

node *pop(void)
{
    static node popped_one;
    node *ptr;
    if (cnt < 1)
        return NULL;
    popped_one = *top;
    ptr = top;
    top = top->below;
    free(ptr);
    --cnt;
    return (&popped_one);
}
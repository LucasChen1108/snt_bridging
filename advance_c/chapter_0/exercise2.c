//exercise: Ask users for random integers and store them into a linked-list in the order of increase value.
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num;
    struct node *next;
}node;
void insert(node **first, int num);
void show_list(const node *head);
void free_list(node *head);

int main()
{
    int quit, num;
    node *head = NULL;
    do
    {
        printf("Enter a number between 1 to 30 that u want to insert: ");
        scanf("%d", &num);
        if (num < 1 || num >30)
        {
            printf("Not in the required range !\n\n");
            quit = 1;
        }
        else
        {
            insert (&head, num);
            printf("Enter 1 to continue, 0 to quit and see the list: ");
            scanf ("%d", &quit);
            print("\n");
        }
    }while (quit);
    show_list(head);
    free_list(head);
    return 0;
}

void insert(node **first, int a)
{
    node *this1, *back;
    this1 = (node *)malloc(sizeof(node));
    if (this1 == NULL)
    {
        printf("Memory allocation failed.\n\n");
        exit (1);
    }
    this1->num = a;
    this1->next = NULL;
    if (*first == NULL || (*first)->num >= a)
    {
        this1->next = *first;
        *first = this1;
        return;
    }
    node *current = *first;
    while (current->next != NULL && current->next->num < a)
    {
        current = current->next;
    }
    this1->next = current->next;
    current->next = this1;
}

void show_list(const node *head)
{
    const node *ptr = head;
    while (ptr != NULL)
    {
        printf("%3d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void free_list(node *head)
{
    node *current;
    while(head != NULL)
    {
       current = head;
       head = head->next;
       free(current);
    }
}


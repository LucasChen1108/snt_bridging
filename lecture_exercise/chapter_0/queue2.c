#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct node{
    char lname[25];
    char fname[15];
    int account_num;
    int balance;
    struct node* next;
}node;
node *front, *rear;
int count = 0;
node *insert(node this1);
node *delete(void);
void get_data(node *ptr);
void print_data(node *ptr);

int main()
{
    node this1, *ptr;
    int answer, quit;
    do
    {
        do
        {
            printf("\nEnter 1 to insert, 2 to remove: ");
            scanf("%d", &answer);
            printf("\n");
            switch(answer)
            {
                case 1: 
                    get_data(&this1);
                    if(insert(this1) == NULL)
                        printf("\nQUEUE FULL\n");
                    break;
                case 2:
                    if((ptr = delete()) != NULL)
                        print_data(ptr);
                    break;
                default:
                    printf("Illegal Response");
                    break;
            }
        }while(answer != 1 && answer != 2);
        printf("\n1 to continue, 0 to quit: ");
        scanf("%d", &quit);
    }while(quit);
    return 0;
}

void get_data(node *ptr)
{
    printf("Enter last name: ");
    scanf("%24s", ptr->lname);
    printf("Enter first name: ");
    scanf("%14s", ptr->fname);
    printf("Enter account number: ");
    scanf("%d", &ptr->account_num);
    printf("Enter balance: ");
    scanf("%d", &ptr->balance);
}

void print_data(node *ptr)
{
    printf("Deleted record:\n");
    printf("Customer's name: %s, %s\n", ptr->lname, ptr->fname);
    printf("Account number: %d\n", ptr->account_num);
    printf("Balance: %d\n", ptr->balance);
}

node *insert(node this1)
{
    node *ptr;
    if (count >= SIZE) return NULL;
    ptr = (node *)malloc(sizeof(node));
    *ptr = this1;
    if(count == 0)
        front = ptr;
    else
        rear->next = ptr;
    rear = ptr;
    rear->next = NULL;
    count++;
    return ptr;
}

node *delete(void)
{
    static node this1;
    node *next;
    if (count == 0)
        return NULL;
    this1 = *front;
    next = front;
    free(next);
    front = front->next;
    count--;
    return &this1;
}


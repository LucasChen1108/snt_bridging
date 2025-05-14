#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char name[10];
    struct node *next;
} node;
void print_nodes(const node *head);
node *get_note(void);
void free_list(node *head);
double get_average(node *head);

int main() 
{
    node *head;
    head = get_note();
    print_nodes(head);
    free_list(head);
    return 0;
}
void print_nodes(const node *ptr )
{
    int count = 1;
    printf( "\n" );
    while ( ptr != NULL )
    {
        printf( "\nAnimal number %d is %s.", count++, ptr-> name );
        ptr = ptr -> next;
    } 
    printf( "\n" );
}

node *get_note(void) 
{
    int response;
    node *current, *first;
    /* allocate first node */
    current = first = (node *)malloc(sizeof(node));
    if (first == NULL) {
        printf("Memory allocation failed for first node.\n");
        exit(1);
    }
    /* store name of first node */
    printf("\n\tEnter name of first node:\t");
    scanf("%9s", current->name);

    /* prompt user about another node */
    printf("Add another? <1 == yes, 0 == no>\t");
    scanf("%d", &response);

    /* Add nodes to list until user signals halt. */
    while (response){
        current->next = (node *)malloc(sizeof(node));
        if (current->next == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        current = current->next;
        /* store name of next node */  
        printf("\n\tName:\t");
        scanf("%9s", current->name);
        /* prompt user about another node */    
        printf("Add another? <1 == yes, 0 == no>\t");
        scanf("%d", &response);
    }
    current->next = NULL;
    return first;
}

void free_list(node *head) 
{
    node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

double get_average(node *head) 
{
    int count = 0;
    double sum = 0.0;
    node *current = head;

    while (current != NULL) {
        sum += strlen(current->name);
        count++;
        current = current->next;
    }
    return (count == 0) ? 0 : sum / count;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct product{
    int product_id;
    char name[30];
    double price;
} product;

product* create_arr(int size)
{
    product *ptr;
    ptr = (product *) malloc(size * sizeof(product));
    if(ptr == NULL)
    {
        printf("Memory allocation failed!");
        return NULL;
    }
    return ptr;
}

void initial_product(product *arr, int size)
{
    for (int i = 0; i < size ; i++)
    {
        arr[i].product_id = i+1 ;
        arr[i].name[0] = '\0';
        arr[i].price = 0.0;
    }
}


int main()
{
    int size;
    printf("Size: ");
    scanf("%d", &size);
    product *arr_product = create_arr(size);
    initial_product(arr_product, size);
    product *curr = arr_product;
    for (int i = 0;i < size; i++)
    {
        printf("ID: %d, Name: %s, Price: %.1lf\n", curr->product_id, curr->name, curr->price);
        curr++;
    }
    free(arr_product);
    return 0;
}
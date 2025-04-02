#include<stdio.h>
void scan_set(int set[], int size);
void prt_set(int set[], int size);
int is_member(int item, int set[], int size);
int intersect(int setA[], int sizeA, int setB[], int sizeB, int setC[]);
int top_k_sum(int k, int set[], int size);
int main()
{
    int set[50], setA[50], setB[50], setC[50], n, a, k, choice, sizeA, sizeB, result;
    printf("Enter 1 (membership checking), 2 (intersection), or 3 (top-k sum): ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        scanf("%d", &n);
        scan_set(set, n);
        prt_set(set, n);
        scanf("%d", &a);
        if (is_member(a, set, n) == 1)
            printf("Item %d is a member of the set.\n", a);
        else
            printf("Item %d is NOT a member of the set.\n", a);
        break;
    case 2:
        scanf("%d", &sizeA);
        scan_set(setA, sizeA);
        prt_set(setA, sizeA);
        scanf("%d", &sizeB);
        scan_set(setB, sizeB);
        prt_set(setB, sizeB);
        printf("%d\n", intersect(setA, sizeA, setB, sizeB, setC));
        prt_set(setC, intersect(setA, sizeA, setB, sizeB, setC));
        break;
    case 3:
        scanf("%d", &n);
        scan_set(set, n);
        prt_set(set, n);
        scanf("%d", &k);
        result = top_k_sum(k, set, n);
        if (k > n)
            printf("The set is too small.\n");
        else
            printf("%d\n", result);
        break;
    }
    return 0;
}

void scan_set(int set[], int size)
{
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &set[i]);
    }
}
void prt_set(int set[], int size)
{
    printf("{ ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", set[i]);
    }
    printf("}.\n");
}

int is_member(int item, int set[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if(set[i] == item)
        {
            return 1;
        }
    }
    return 0;
}

int intersect(int setA[], int sizeA, int setB[], int sizeB, int setC[])
{
    int i,j=0;
    for (i=0;i<sizeA;i++)
    {
        if(is_member(setA[i], setB, sizeB)==1)
        {
            setC[j] = setA[i];
            j++;
        }
    }
    return j;
}

int top_k_sum(int k, int set[], int size)
{
    int sum=0,i,j,temp;
    if (k > size)
        return 0;
    else
    {
        for(i=0;i<size;i++)
        {
            for(j=0;j<size-i;j++)
            {
                if(set[j]<set[j+1])
                {
                    int temp = set[j];
                    set[j] = set[j+1];
                    set[j+1] = temp;
                }
            }
        }
        for(i=0;i<k;i++)
            sum+=set[i];
    }
    return sum;
}
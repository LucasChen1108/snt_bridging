# include <stdio.h> 
# include <stdlib.h> 
int main(void) 
{ 
 
    typedef struct employee 
    { 
        char name [14]; 
        int emp_no; 
        char gender; 
        float rate, hr; 
        struct employee *next; 
    }   node; 
    float pay, total=0; 
    FILE *indata; 
 
    node this1; 
    node *temp, *first=NULL; 
    indata = fopen ("wage.inf","r"); 
    if (indata==NULL) 
    { 
        printf ("\n wage.inf cannot be found."); 
        exit (1);
    } 
    printf ("\n Employee No. Hours Worked Hourly Rate Wage"); 
    printf ("\n (hr) ($/hr) ($)"); 
    printf ("\n ================================================="); 
    char line[100];
    while (fgets(line, sizeof(line), indata) != NULL) 
    {
        // 使用 sscanf 解析整行，%13[^\n] 读取最多13个字符（包括空格），直到换行
        if (sscanf(line, "%13[^\n] %d %c %f %f", this1.name, &this1.emp_no, &this1.gender, &this1.rate, &this1.hr) == 5) 
        {
            printf("Read: %s %d %c %.2f %.2f\n", this1.name, this1.emp_no, this1.gender, this1.rate, this1.hr);

            if (this1.hr < 0 || this1.rate < 0) 
            {
                printf("Invalid data for employee %d\n", this1.emp_no);
                continue;
            }
        }



        node *prev = first;
        temp = first;
        node *new_node = (node *)malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Allocation fail. \n\n");
            exit(1);
        }
        *new_node = this1;
        new_node -> next = NULL;

        if (first == NULL || new_node->emp_no <= first->emp_no)
        {
            new_node->next = first;
            first = new_node;
        }
        else
        {
            while( (temp != NULL) && (temp->emp_no < new_node->emp_no))
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = new_node;
            new_node->next = temp;
        }
    } 
 

    
    temp = first; 
    while (temp!=NULL) 
    { 
        printf ("\n %4d %6.2f %6.2f ", 
        temp->emp_no, temp->hr, temp->rate ); 
        if (temp->hr <= 40) 
            pay = temp->hr * temp->rate; 
        else 
            pay = temp->rate *40 + temp->rate*(temp->hr-40)*1.5; 
        printf (" %6.2f ", pay); 
        total +=pay; 
        temp = temp->next; 
    } 

    temp = first;
    while (temp != NULL)
    {
        node *next = temp->next;
        free(temp);
        temp = next;
    }
    printf ("\n\n Total wages = $%-8.2f\n", total); 
    fclose (indata); 
    return 0; 
}
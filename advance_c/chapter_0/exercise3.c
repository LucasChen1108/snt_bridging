// Hash Table Exercise （alpha_hash）
// A system to store students grades. Containing function include: add, get, remove, list, exit.
/* Example run:
Enter command (add/get/remove/list/exit): add
Name: Alice
Grade: 85
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

typedef struct Student{
    int grade;
    char *name;
    struct Student *next;
} Student;

Student* table[ALPHABET_SIZE];
int hash(char *name);
void add_student(char *name, int grade);
void find_student(char *name);
void remove_student(char *name);
void list_students(void);
void free_all(void);

int main()
{
    char command[10];
    char name[100];
    int grade;

    while (1) {
        printf("\nEnter command (add/find/remove/list/exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Name: ");
            scanf(" %[^\n]", name); //使其读到换行符才会停止
            printf("Grade: ");
            scanf("%d", &grade);
            add_student(name, grade);
        } else if (strcmp(command, "find") == 0) {
            printf("Name to search: ");
            scanf(" %[^\n]", name);
            find_student(name);
        } else if (strcmp(command, "remove") == 0) {
            printf("Name to remove: ");
            scanf(" %[^\n]", name);
            remove_student(name);
        } else if (strcmp(command, "list") == 0) {
            list_students();
        } else if (strcmp(command, "exit") == 0) {
            free_all();
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}

int hash(char *name)
{
    if (!isalpha(name[0]))
        return -1;
    return toupper(name[0]) - 'A';
}

void add_student(char *name, int grade)
{
    int index = hash(name);
    if (index < 0 || index > ALPHABET_SIZE)
    {
        printf("Invalid name format. \n");
        return;
    }

    Student *cur = table[index];
    while (cur != NULL)
    {
        if (strcmp(cur->name, name) == 0)
        {
            printf("This student already exists. \n");
            return;
        }
        cur = cur->next;
    }

    Student *new_stu = (Student *)malloc(sizeof(Student));
    new_stu->name = strdup(name); //调用malloc自动分配内存来存储字符串
    new_stu->grade = grade;
    new_stu->next = table[index];
    table[index] = new_stu;
    printf("Added student: %s (grade %d)\n", name, grade);
}

void find_student(char *name)
{
    int key = hash(name);
    if (key < 0)
    {
        printf("Invalid name. \n");
        return;
    }

    Student *cur = table[key];
    while (cur != NULL)
    {
        if(strcmp(cur->name, name) == 0)
        {
            printf("Found: %s - Grade: %d\n", cur->name, cur->grade);
            return;
        }
        cur = cur->next;
    }
    printf("Student not found. \n");
}

void remove_student(char *name)
{
    int key = hash(name);
    if (key < 0)
    {
        printf("Invalid name. \n");
        return;
    }
    Student *cur = table[key], *prev = NULL;
    while (cur != NULL)
    {
        if (strcmp(cur->name, name) == 0)
        {
            if (prev != NULL)
                prev->next = cur->next;
            else table[key] = cur->next;

            free(cur->name) ;// because we used strdup() before
            free(cur);
            printf("Student removed.\n");
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    printf("Students not found.\n");
}

void list_students(void)
{
    int found = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        Student *cur = table[i];
        while (cur != NULL)
        {
            printf("Name: %s | Grade: %d\n", cur->name, cur->grade);
            cur = cur-> next;
            found = 1;
        }
    }
    if (!found) 
            printf("No students in the list.\n");
}

void free_all(void)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        Student *cur = table[i];
        while (cur != NULL)
        {
            Student *tmp = cur;
            cur = cur->next;
            free(tmp->name); // must remember !
            free(tmp);
        }
        table[i] = NULL;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct BookRecord{
    int id;
    char book_name[100];
    char author_name[50];
    double price;
} BookRecord;

int create_book_list(const char* filename, int num_books);
BookRecord** load_books(const char* filename, int* num_books);
void free_loaded_books(BookRecord** book_ptrs, int count);

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Wrong input format. <./exe filename>\n");
        return 1;
    }
    char *filename = argv[1];
    int num_books;
    printf("How many books do u want to create in file <%s>: ", filename);
    scanf("%d", &num_books);
    if(create_book_list(filename, num_books) == -1)
    {
        printf("Ohno, sth went wrong ! \n\n");
        return -1;
    }

    num_books = 0;
    BookRecord **book_list_ptr = load_books(filename, &num_books);
    if (book_list_ptr == NULL)
    {
        printf("Ohno, sth went wrong. \n\n");
        free_loaded_books(book_list_ptr, num_books);
        return -2;
    }
    
    for(int i = 0; i < num_books; i++)
    {
        printf("%3d  %-15s %-15s %.2lf \n", book_list_ptr[i]->id, book_list_ptr[i]->book_name, book_list_ptr[i]->author_name, book_list_ptr[i]->price);
    }

    free_loaded_books(book_list_ptr, num_books);
    return 0;
}

int create_book_list(const char* filename, int num_books)
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        printf("Fail to create a file\n\n");
        return -1;
    }

    srand(time(NULL));
    for (int i = 0; i < num_books; i++)
    {
        BookRecord book;
        int random_num = rand()%26;
        book.id = i+1;
        snprintf(book.book_name, sizeof(book.book_name), "Book title %c", random_num + 'A');
        snprintf(book.author_name, sizeof(book.author_name), "Author %c", random_num + 'A');
        book.price = (float)(rand() % 9101 + 1000) / 100.00;

        if(fwrite(&book, sizeof(BookRecord), 1, fp) != 1)
        {
            printf("Fail to write in record\n\n");
            fclose(fp);
            return -1;
        }
    }
    fclose(fp);
    return 0;
}

BookRecord** load_books(const char* filename, int* num_books)
{
    FILE *indata = fopen(filename, "rb");
    if (indata == NULL)
    {
        printf("Fail to open the file\n\n");
        return NULL;
    }

    int capacity = 10;

    BookRecord **book_list = (BookRecord **)malloc(sizeof(BookRecord*) * capacity);
    if (book_list == NULL)
    {printf("Error in creating the list");exit(1);}

    *num_books = 0;
    while (1) 
    {
        if(*num_books == capacity) //动态分配内存
        {
            capacity *= 2;
            BookRecord **temp_list = (BookRecord **)realloc(book_list, sizeof(BookRecord)*capacity);
            if (temp_list == NULL)
            {
                for(int i = 0; i < *num_books; i++)
                    free(book_list[i]);
                free(book_list);
                printf("Memory reallocation failed for pointer array.\n");
                return NULL;
            }
            book_list = temp_list;
        }

        BookRecord *temp = malloc(sizeof(BookRecord));
        if (temp == NULL) 
        {
            printf("Memory allocation failed.\n\n");
            for (int i = 0; i < *num_books; i++) 
                free(book_list[i]);
            return NULL;
        }

        if (fread(temp, sizeof(BookRecord), 1, indata) != 1) {
            free(temp);  // fread失败，释放这次没用到的内存
            break;
        }

        book_list[*num_books] = temp;
        (*num_books)++;
    }

    fclose(indata);
    return book_list;
}

void free_loaded_books(BookRecord** book_ptrs, int count)
{
    if (book_ptrs == NULL)
    {
        printf("Already NULL, nothing changed. \n");
        return;
    }
    for(int i = 0; i < count; i++)
        free(book_ptrs[i]);
    free(book_ptrs);
    printf("All loaded book data and pointer array memory freed. \n");
}
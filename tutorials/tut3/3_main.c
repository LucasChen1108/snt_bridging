#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tool
{
	int rec_Num;
	char name[16];
	int quantity;
	float cost;
}tool;

int main()
{
    FILE *outdata = fopen("hardware.dat", "rb+");
    if (outdata == NULL){
        printf("Fail to open the file.\n");
        exit(1);
    }
    tool item;
    int delete, quit, option;
    char temp_name[30];
    tool blank = {0, "", 0, 0.0};
    size_t len;

    do{
        quit = 1;
        delete = 0;
        printf("\n1. Input a new record\n");
        printf("2. Update a record\n");
        printf("3. List all records\n");
        printf("4. Delete a record\n");
        printf("5. Quit\n");
        printf("Your option-> ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Enter the record #> ");
                scanf("%d", &item.rec_Num);
                printf("Tool name > ");
                while (getchar() != '\n'); // 清空输入缓冲区里的残留换行符
                fgets(temp_name, sizeof(temp_name), stdin);
                // 去除末尾换行符
                len = strlen(temp_name);
                if (len > 0 && temp_name[len-1] == '\n') {
                    temp_name[len-1] = '\0';
                }
                // 复制前16个字符（包括结束符）
                strncpy(item.name, temp_name, sizeof(item.name)-1);
                item.name[sizeof(item.name)-1] = '\0';  // 确保结束符
                printf("Enter the Quantity and Cost for \'%s\' \n", item.name);
                scanf("%d %f", &item.quantity, &item.cost);
                fseek(outdata, (item.rec_Num-1) * sizeof(tool), SEEK_SET);
                fwrite(&item, sizeof(tool), 1, outdata);
                rewind(outdata);
                break;
            case 2:
                printf("Enter the record #> ");
                scanf("%d", &item.rec_Num);
                printf("Tool name > ");
                while (getchar() != '\n'); // 清空输入缓冲区里的残留换行符
                fgets(temp_name, sizeof(temp_name), stdin);
                // 去除末尾换行符
                len = strlen(temp_name);
                if (len > 0 && temp_name[len-1] == '\n') {
                    temp_name[len-1] = '\0';
                }
                // 复制前16个字符（包括结束符）
                strncpy(item.name, temp_name, sizeof(item.name)-1);
                item.name[sizeof(item.name)-1] = '\0';  // 确保结束符
                printf("Enter the Quantity and Cost for \'%s\' \n", item.name);
                scanf("%d %f", &item.quantity, &item.cost);
                fseek(outdata, (item.rec_Num-1) * sizeof(tool), SEEK_SET);
                fwrite(&item, sizeof(tool), 1, outdata);
                rewind(outdata);
                break;

            case 3:
                printf("Record #  Tool Name         Quantity     Cost\n");
                while (fread(&item, sizeof(struct tool), 1, outdata) == 1) 
                {
                    if (item.rec_Num != 0) 
                    {  // 忽略空记录（初始化时是0）
                        printf("%-9d %-17s %-12d %.2f\n",
                        item.rec_Num, item.name, item.quantity, item.cost);
                    }   
                }
                rewind(outdata);
                break;
            case 4:
                printf("Enter  the record #> ");
                scanf("%d", &delete);
                fseek(outdata, (delete-1) * sizeof(tool), SEEK_SET);
                fwrite(&blank, sizeof(tool), 1, outdata);
                rewind(outdata);
                break;
            case 5:
                quit = 0;
                break;
            default:
                quit = 0;
                break;
        }

    }while(quit);
    fclose(outdata);
    return 0;
}
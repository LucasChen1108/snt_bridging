#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tool
{
	int rec_Num;
	char name[16];
	int quantity;
	float cost;
}tool;

int main()
{
    char line[100];
    char longname[30];
	tool item;
	FILE *indata, *outdata;
	indata = fopen("hardware.inf", "r");
	if (indata == NULL)
	{
		printf("Fail to open the file\n");
		exit(1);
	}

	outdata = fopen("hardware.dat", "rb+");
	if (outdata == NULL)
	{
		printf("Fail to open the binary file.\n");
		exit(1);
	}
	
    while (fgets(line, sizeof(line), indata))
	{
	    // 读取格式：数字 + 带空格名字 + 数字 + 浮点数
	    if (sscanf(line, "%d %29[A-Za-z ] %d %f", &item.rec_Num, longname, &item.quantity, &item.cost) == 4)
	    {
	        strncpy(item.name, longname, sizeof(item.name) - 1);
	        item.name[sizeof(item.name) - 1] = '\0';

	        // 写入二进制文件
	        fseek(outdata, (item.rec_Num - 1) * sizeof(tool), SEEK_SET);
	        fwrite(&item, sizeof(tool), 1, outdata);
	    }
	}
	fclose(indata);
	fclose(outdata);
	return 0;
}
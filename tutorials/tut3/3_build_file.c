#include<stdio.h>
#include<stdlib.h>

typedef struct tool
{
	int rec_Num;
	char name[16];
	int quantity;
	float cost;
}tool;

int main()
{
	FILE *outdata;
	tool empty_tool = {0, "", 0, 0.0};
	outdata = fopen("hardware.dat", "wb");
	if (outdata == NULL)
	{
		printf("Error in open the file to write\n\n");
		exit(1);
	}

	for (int i = 0; i < 100; i++)
	{
		fwrite(&empty_tool, sizeof(tool), 1, outdata);
	}

	fclose(outdata);
	printf("Successfully creat an empty binary file: hardware.dat\n");
	return 0;
}
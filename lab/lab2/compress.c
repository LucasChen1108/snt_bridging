#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXSIZE 50
int main()
{
    FILE *indata, *fp;
    uint32_t pack;
    indata = fopen("digit.inf", "r");
    if (indata == NULL)
    {
        printf("Fail to open the file. \n");
        exit(1);
    }
    int cnt = 0, size = 0;
    char curr;
    unsigned int digit[MAXSIZE][8];
    printf("\n    Original Text: ");
    while(fscanf(indata, "%c", &curr) == 1)
    {
        printf("%c", curr);
        digit[size][cnt] = curr - '0';
        if(cnt == 7)
        {
            size++;
            cnt = 0;
        }
        else
            cnt++;
    }

    fp = fopen("digit.ouf", "wb+");
    //binary operation
    uint32_t mask = 0x0000000f;
    for(int i = 0; i < size; i++)
    {
        pack = 0;
        for(int j = 0; j < 8; j++)
        {
            pack |= (digit[i][j] & mask) << (28-j*4);
        }
        fwrite(&pack, sizeof(uint32_t), 1, fp);
    }
    
    //print out to verify
    rewind(fp);//指针回位
    printf("\nDecompressed Text: ");
    while(fread(&pack, sizeof(uint32_t), 1, fp) == 1)
    {
        for(int i = 0; i < 8; i++)
        {
            printf("%d", (pack >> (28 - i * 4)) & 0xF);
        }
    }
    printf("\n\n");

    fclose(indata);
    fclose(fp);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_WORD_SIZE 20
#define Maxwords 100
#define Maxbi 250

void readWords(char bank[][MAX_WORD_SIZE], int *maxWordSize, int *wordCount);
void print_bank(char bank[][MAX_WORD_SIZE], int maxWordSize, int wordCount);
void findBigrams(char bank[][MAX_WORD_SIZE], int maxWordSize, int wordCount, int bigramTable[26][26]);
void info_bigramTable(int bigramTable[26][26]);
void repeatBigram(char bank[][MAX_WORD_SIZE], int maxWordSize, int wordCount, int bigramTable[26][26]);

int main()
{
    char bank[Maxwords][MAX_WORD_SIZE];
    int bigramTable[26][26] = {0};
    int maxWordSize = 0, wordCount = 0;
    readWords(bank, &maxWordSize, &wordCount);
    print_bank(bank, maxWordSize, wordCount);
    findBigrams(bank, maxWordSize, wordCount, bigramTable);
    info_bigramTable(bigramTable);
    repeatBigram(bank, maxWordSize, wordCount, bigramTable);
    return 0;
}

void readWords(char bank[][MAX_WORD_SIZE], int *maxWordSize, int *wordCount)
{
    char temp;
    int cnt = 0;
    printf("Read in words: \n");
    while (scanf("%c", &temp) == 1 && temp != '.')
    {
        if (isalpha(temp))
        {
            if (cnt < MAX_WORD_SIZE - 1)  // 避免越界
                bank[*wordCount][cnt++] = tolower(temp);
        }
        else if (temp == ' ' && cnt > 0)
        {
            bank[*wordCount][cnt] = '\0';  // 添加终止符
            if (cnt > *maxWordSize)
                *maxWordSize = cnt;

            (*wordCount)++;
            cnt = 0;
        }
    }

    // 处理最后一个单词（如果有）
    if (cnt > 0)
    {
        bank[*wordCount][cnt] = '\0';
        if (cnt > *maxWordSize)
            *maxWordSize = cnt;
        (*wordCount)++;
    }
}

void print_bank(char bank[][MAX_WORD_SIZE], int maxWordSize, int wordCount)
{
    printf("Word Bank: \n");
    printf("++++++++++\n");
    for (int i = 0; i < wordCount; i++)
    {
        for (int j = 0; bank[i][j] != '\0'; j++)
            printf("%c", bank[i][j]);
        printf("\n");
    }
    printf("Number of the words read: %d\n", wordCount);
    printf("The length of the longest word: %d\n", maxWordSize);
}

void findBigrams(char bank[][MAX_WORD_SIZE], int maxWordSize, int wordCount, int bigramTable[26][26])
{
    int curr;
    printf("\n\nBigrams found:\n");
    printf("++++++++++++++\n");
    for (int i = 0; i < wordCount; i++)
    {
        curr = 0;
        printf("%s:", bank[i]);
        while(bank[i][curr + 1] != '\0')
        {
            printf(" %c%c", bank[i][curr], bank[i][curr+1]);
            bigramTable[bank[i][curr] - 'a'][bank[i][curr+1] - 'a']++;
            curr++;
        }
        putchar('\n');
    }
}

void info_bigramTable(int bigramTable[26][26])
{
    int bi_num = 0, bi_occ = 0, print, cnt;
    int activeCols[26] = {0};

    //标记所有出现了的列
    for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                if (bigramTable[i][j] != 0)
                    activeCols[j] = 1;

    printf("\n\nBigram Frequency Table:\n");
    printf("+++++++++++++++++++++++\n");
    //打表头
    printf("  |");
    for (int j = 0; j < 26; j++)
        if (activeCols[j])
            printf("%3c", 'a' + j);
    putchar('\n');
    //分隔符
    printf("--+");
    for (int j = 0; j < 26; j++)
        if (activeCols[j])
            printf("---");
    putchar('\n');
    for (int i = 0; i < 26; i++)
    {
        int hasData = 0;
        for (int j = 0; j < 26; j++) {
            if (bigramTable[i][j] != 0) {
                hasData = 1;
                break;
            }
        }
        if(hasData)
        {
            printf(" %c|", 'a'+i);
            for(int j = 0; j < 26; j++)
            {
                if (activeCols[j])
                {
                     printf("%3d", bigramTable[i][j]);
                    if (bigramTable[i][j] != 0)
                    {
                        bi_num++;
                        bi_occ += bigramTable[i][j];
                    }
                }
            }
            putchar('\n');
        }
    }

    printf("\n\nBigram statistics: \n");
    printf("++++++++++++++++++\n");
    printf("Total number of bigrams: %d\n", bi_num);
    printf("Total count of bigram occurrences: %d\n", bi_occ);
}

void repeatBigram(char bank[][MAX_WORD_SIZE], int maxWordSize, int wordCount, int bigramTable[26][26])
{
    typedef struct location{
        int x;
        int y;
        int times;
    }loc;
    loc array[Maxbi] = {{0,0,0}};
    int binum = 0;
    //遍历所有出现过的bigram并找出其中出现过不止一次的，即同词多现的备选项
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if(bigramTable[i][j] > 1)
            {
                array[binum].x = i;
                array[binum].y = j;
                array[binum].times = 0;
                binum++;
            }
        }
    }
    //遍历bank，逐个确认该bigram是否出现了同词多现的现象
    for(int i = 0; i < wordCount; i++)
    {
        for (int j = 0; j < binum; j++) //对于该单词，从第一个可能的bigram开始
        {
            int occ = 0;
            for(int curr = 0; bank[i][curr+1] != '\0'; curr++)
            {
                if(bank[i][curr] == 'a'+array[j].x && bank[i][curr+1] == 'a'+array[j].y)
                {
                    occ++;
                }
            }
            if(occ > 1)
                array[j].times++;
        }
    }

    //已经获得了所有重复出现的bigram和他们的出现次数了，以递减顺序排列（now using bubble sort)
    loc temp;
    for(int i = 0; i < binum-1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < binum-1-i; j++)
        {
            if(array[j].times < array[j+1].times)
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }

    for(int i = 0; i < binum; i++)
    {
        printf("%c%c: %d", 'a'+array[i].x, 'a'+array[i].y, array[i].times);
    }

    //print data
    printf("\n\nRepeated Bigrams Statistics: \n");
    printf("++++++++++++++++++++++++++++\n");
    int cnt = 0;
    while(array[cnt].times != 0)
    {
        printf("Number of words for which \"%c%c\" is found repeated: %d \n", 'a'+array[cnt].x, 'a'+array[cnt].y, array[cnt].times);
        cnt++;
    }
    if (array[0].times == 0)
        printf("No bigram is found repeated in any word.\n");
}
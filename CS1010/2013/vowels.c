#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 80
void convert(char *);
int main(void) {
	char line[MAXLEN+1];
	int len;
	printf("Enter text: ");
	fgets(line, MAXLEN+1, stdin);
	len = strlen(line);
	if (line[len-1] == '\n')
	line[len-1] = '\0';
	convert(line);
	printf("Converted : %s\n", line);
	return 0;
}

void convert(char *str)
{
	int len = strlen(str);
	for(int i = 0; i < len; i++)
		str[i] = toupper(str[i]);
	for(int i = 0; i < len; i++)
	{
		if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' )
		{
			for(int j = i; j < len-1; j++)
				str[j] = str[j+1];
            str[len-1] = '\0';
			len--;
			i--;
		}
	}
}
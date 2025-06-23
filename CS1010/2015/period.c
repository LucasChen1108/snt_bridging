#include <stdio.h>
#include <string.h>

// 你写的 period 函数声明（假设你在别处实现了这个函数）
int period(char str[]);

int main(void) {
    // 测试样例
    char *test_cases[] = {
        "abcabcabcabc",  // 期望输出: 3
        "abcabc",        // 期望输出: 3
        "ababab",        // 期望输出: 2
        "aaaa",          // 期望输出: 1
        "abcab",         // 期望输出: 5
        "abcdabcdabce",  // 期望输出: 12
        "xyz",           // 期望输出: 3
    };

    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_cases; i++) {
        printf("String: \"%s\", Period: %d\n", test_cases[i], period(test_cases[i]));
    }

    return 0;
}

int period(char str[])
{
	int j, size = strlen(str);
	for(int len = 1; len <= size; len++)
	{
        if (size % len != 0)  // 如果不能整除，一定不能由它重复组成
            continue;
        int ite = 1;
		for(int i=0; i < len; i++)
		{
			char key = str[i];
			for(j = 0; i + len*j < size; j++)
			{
				if(key != str[i + len*j])
					ite = 0;
			}
		}
		if(ite == 1)
		{
			return len;
		}
	}
    return size;
}
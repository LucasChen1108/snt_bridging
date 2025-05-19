#include <stdio.h>
#include <stdlib.h>
//int string_to_int(char *str); 但是此处直接使用atoi函数
int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Error !! No Data. \n");
        exit(1);
    }
    int sum, max, min, temp;
    float mean;
    sum = max = min = atoi(argv[1]);
    if (argc > 2)
    {
        for(int i = 2; i < argc; i++)
        {
            temp = atoi(argv[i]);
            sum += temp;
            max = temp > max? temp : max; 
            min = temp < min? temp : min;
        }
    }
    mean = (float)sum / (argc-1);
    printf("Sum = %d\n", sum);
    printf("Mean = %.2f\n", mean);
    printf("Maximum = %d\n", max);
    printf("Minumun = %d\n", min);
    return 0;
}

/*
int string_to_int(char *str) {
    int result = 0;      // 存储转换结果
    int sign = 1;        // 符号：1 表示正，-1 表示负
    int i = 0;           // 字符串索引

    // 检查空字符串
    if (str[0] == '\0') {
        return 0; // 或根据需求处理错误
    }

    // 处理符号
    if (str[0] == '-') {
        sign = -1;
        i = 1; 
    } else if (str[0] == '+') {
        i = 1; 
    }

    // 检查是否只有符号
    if (str[i] == '\0') {
        return 0; // 或根据需求处理错误
    }

    // 逐字符处理数字
    while (str[i] != '\0') {
        // 验证字符是否为数字
        if (str[i] < '0' || str[i] > '9') {
            return 0; // 非数字字符，返回 0 或其他错误处理
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return sign * result;
}
*/
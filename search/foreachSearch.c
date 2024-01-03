#include<stdio.h>
#include<time.h>
#include<stdlib.h>

/* 宏定义在预处理阶段 被替换 */
#define BUFFER_SIZE 10
/* 宏函数 无法调试 */

int printArray(int *array, int arraySize)
{
    int ret = 0;
    if (array == NULL)
    {
        return ret;
    }
    for (int idx = 0; idx < arraySize; idx++)
    {
        printf("%d\t", array[idx]);
    }
    return ret;
}

int findAppointValPos(int *array, int length, int val)
{
    int ret = 0;
    int count = 0;
    if (array == NULL)
    {
        return ret;
    }
    for (int idx = 0; idx < length; idx++)
    {
        if (array[idx] == val)
        {
            count++;
            printf("找到该位置为:%d\n", idx);
        }
    }
    if (count == 0)
    {
        printf("没找到\n");
    }
    
    return ret;
}



int main()
{
    /* 随机数种子 */
    srand(time(NULL));

    int buffer[BUFFER_SIZE] = { 0 };
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        buffer[idx] = rand() % 10 + 1; 
    }
    int length = sizeof(buffer) /sizeof(buffer[0]);
    printArray(buffer, length);
    printf("\n");
    int pos = 0;
    findAppointValPos(buffer, length, 1);
    return 0;

}
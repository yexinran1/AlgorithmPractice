#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>

#define ARRAY_SIZE 8
#define RANGE_NUM 11

void printArray(int *array, int len)
{
    for(int idx = 0; idx < len; idx++)
    {
        printf("%d ", array[idx]);
    }
    printf("\n");
}

int main()
{
    int array[ARRAY_SIZE];
    memset(array, 0, sizeof(array));
    srand(time(NULL));
    for(int idx = 0; idx < ARRAY_SIZE; idx++)
    {
        array[idx] = rand() % RANGE_NUM;
    }
    printf("原数组:\n");
    printArray(array,ARRAY_SIZE);

    int pos = 0;

    int target;
    printf("请输入目标值:");
    scanf("%d", &target);

    for(int idx = 0; idx < ARRAY_SIZE; idx++ )
    {
        if( array[idx] != target)
        {
            /* 原地空间复杂度o(1)*/
            array[pos++] = array[idx];
            /*
            array[pos] = array[idx];
            pos++;
            */
        }
    }

    if(pos == ARRAY_SIZE)
    {
        printf("没找到目标值\n");
    }
    else
    {
        printf("删除目标值后数组:\n");
        printArray(array, pos);
    }
    return 0;
}
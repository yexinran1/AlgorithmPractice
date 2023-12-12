#include<stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define ARRAY_SIZE 5
#define RANGE_NUM 99

void BubbleSort(char *array , int len )
{
    for(int idx = 0; idx < len - 1; idx++)
    {
    int flag = 0;
       for(int idx2 = 0; idx2 < len - 1 - idx; idx2++)
       {
            if(array[idx2] > array[idx2 + 1])
            {
            flag = 1;
            int temp = array[idx2];
            array[idx2] = array[idx2 + 1];
            array[idx2 + 1] = temp;
            }
        }
       //数列已经有序
       if (flag == 0)
       {
            break;
       }      
   }
}

void printArray(char *array, int len)
{
    for(int idx = 0; idx < ARRAY_SIZE; idx++)
    {
        printf("%d ", array[idx]);
    }
    printf("\n");
}

int main()
{
    int len = ARRAY_SIZE;
    char array[ARRAY_SIZE];
    memset(array, 0, sizeof(array));
    for(int idx = 0; idx < ARRAY_SIZE; idx++)
    {
        array[idx] = rand() % RANGE_NUM;
    }
    printf("排序前随机数组:\n");
    printArray(array, len);

    BubbleSort(array, ARRAY_SIZE);
    printf("排序后随机数组:\n");
    printArray(array, ARRAY_SIZE);

    return 0;
}
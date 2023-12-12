#include<stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define ARRAY_SIZE 5
#define RANGE_NUM 99

void fastSort(int *array, int start, int end)
{
    if(start >= end)
    {
        return;
    }
    int temp = array[start];
    int left = start;
    int right = end;
    while(left < right)
    {
        while(left < right && array[right] > temp)
        {
            right--;
        }
        if(left < right)
        {
            array[left] = array[right];
            left++;
        }
        while(left < right && array[left] < temp)
        {
            left++;
        }
        if(left < right)
        {
            array[right] = array[left];
            right--;
        }
    }
    array[left] = temp;
    fastSort(array, start, left - 1);
    fastSort(array, right + 1, end);
}

void printArray(int *array)
{
    for(int idx = 0; idx < ARRAY_SIZE; idx++)
    {
        printf("%d ", array[idx]);
    }
    printf("\n");
}

int main ()
{
    int array[ARRAY_SIZE];
    memset(array, 0, sizeof(array));
    for(int idx = 0; idx < ARRAY_SIZE; idx++)
    {
        array[idx] = rand() % RANGE_NUM;
    }
    printf("排序前随机数组:\n");
    printArray(array);

    fastSort(array, 0, ARRAY_SIZE);
    printf("排序后随机数组:\n");
    printArray(array);

    return 0;
}
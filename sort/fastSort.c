/* 时间复杂度o(NlogN) */
#include<stdio.h>

int printArray(int *array, int arraySize)
{
    int ret = 0;
    for (int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d]:%d\n", idx, array[idx]);
    }
    return 0;
}

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

int main()
{
    int array[] = {11, 36, 24, 107, 23, 65, 1};
    int len = sizeof(array) / sizeof(array[0]);
    fastSort(array, 0, len - 1);
    printArray(array, len);
    return 0;
}
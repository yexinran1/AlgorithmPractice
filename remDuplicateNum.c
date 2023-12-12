#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define ARRAY_SIZE 11
#define RANGE_NUM 10

/* 快速排序 */
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

/* 打印数组 */
void printArray(int *array, int len)
{
    for(int idx = 0; idx < len; idx++)
    {
        printf("%d ", array[idx]);
    }
    printf("\n");
}

/* 去重 (双指针) */
#if 1
int remDuplicateNum(int *nums, int numsSize)
{
    int num=0;
    if (numsSize == 0) 
    {
        return 0;
    }
    int fast = 1, slow = 1;
    while (fast < numsSize) 
    {
        if (nums[fast] != nums[fast - 1]) 
        {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }
    return slow;
}
#endif


int main()
{
    /* 初始化 */
    int array[ARRAY_SIZE];
    memset(array, 0, sizeof(array));
    srand(time(NULL));
    for(int idx = 0; idx < ARRAY_SIZE; idx++)
    {
        array[idx] = rand() % RANGE_NUM;
    }

    printf("排序前数组:\n");
    printArray(array, ARRAY_SIZE);

    fastSort(array, 0, ARRAY_SIZE-1);
    printf("排序后数组:\n");
    printArray(array, ARRAY_SIZE);

    int len = remDuplicateNum(array, ARRAY_SIZE);
    printf("去重后的数组\n");
    //printf("数组长度:%d\n", len);
    printArray(array, len);

    return 0;
}
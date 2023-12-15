/* 合并字符串 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define BUFFER_SIZE 100

void printArray(int *array, int len)
{
    for(int idx = 0; idx < len; idx++)
    {
        printf("%d ", array[idx]);
    }
    printf("\n");
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

int *mergeOrderNum(int *nums1, int numsSize1,int *nums2, int numsSize2, int newNumSize)
{
#if 0
    int *array = (int *)malloc(sizeof(int) * (newNumSize));
    int idx;
    for(idx = 0; idx < numsSize1; idx++)
    {
        array[idx] = nums1[idx];
    }
    for(int idx2 = 0; idx2 < numsSize2; idx2++)
    {
        array[idx++] = nums2[idx2];
    }
    return array;
#else
    int *array = (int *)malloc(sizeof(int) * (newNumSize));
    if(array ==  NULL)
    {
        return NULL;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
    }
    int count = 0; 
    int ptr1 = 0;
    int ptr2 = 0;
    while(ptr1 < numsSize1 && ptr2 < numsSize2)
    {
        if(nums1[ptr1] < nums2[ptr2])
        {
            array[count++] = nums1[ptr1++];
        }
        else
        {
            array[count++] = nums2[ptr2++];
        }
    }
    while(ptr1 < numsSize1)
    {
        array[count++] = nums1[ptr1++];
    }
    while(ptr2 < numsSize2)
    {
        array[count++] = nums2[ptr2++];
    }
    return array;

    if(array != NULL)
    {
        free(array);
        return NULL;
    }
}
#endif

int main()
{
    int nums1[] = {1, 1, 2, 4, 6, 11};
    int nums2[] = {2, 4, 6, 7, 7, 20, 31};
    int numsSize1 = sizeof(nums1) / 4;
    int numsSize2 = sizeof(nums2) / 4;
    int newNumSize = numsSize1 + numsSize2;
    int  *array = mergeOrderNum(nums1, numsSize1, nums2, numsSize2, newNumSize);
    printf("合并后数组:\n");
    printArray(array, newNumSize);

    // fastSort(array, 0, newNumSize - 1);
    // printf("排序后数组\n");
    // printArray(array, newNumSize);
    free(array);
    return 0;
}
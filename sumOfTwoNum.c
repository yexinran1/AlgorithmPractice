#include<stdio.h>
#include<stdlib.h>
//给定一个整数数组nums和一个整数目标值target
//在该数组中找出和为目标值target的两整数，并返回它们的数组下标。
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    for (int idx1 = 0; idx1 < numsSize - 1; idx1++) 
    {
        for (int idx2 = idx1 + 1; idx2 < numsSize; idx2++) 
        {
            if (nums[idx1] + nums[idx2] == target) 
            {
                int* ret = malloc(sizeof(int) * 2);
                ret[0] = idx1, ret[1] = idx2;
                *returnSize = 2;
                return ret;
                
            }    
        }
    }
    *returnSize = 0;
    return NULL;
}
int main ()
{
    int nums[] = { 1 , 3 , 4 , 5 };
    int target = 9;
    int len = 4;
    int returnSize;
    
    int* array = malloc(sizeof(int) * 2);
    array = twoSum(nums, len, target, &returnSize);
    for(int idx = 0; idx < returnSize; idx++)
    {
        printf("%d ", array[idx]);
        printf("\n");
    }
    if(returnSize == 0)
    {
        printf("没找到\n");
    }
    free(array);
    return 0;
}
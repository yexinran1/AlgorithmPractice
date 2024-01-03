#include<stdio.h>

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

int binarySearchIsExist(int *array, int length, int val)
{
    if (array == NULL)
    {
        return 0;
    }
    int left = 0;
    int right = length - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (val < array[mid])
        {
            right = mid - 1;
        }
        else if (array[mid] == val)
        {
            return 1;
        }
        else if (val > array[mid])
        {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int array[] = {11, 16, 24, 27, 29, 65};
    int len = sizeof(array) / sizeof(array[0]);
    int result = binarySearchIsExist(array, len, 65);
    printf("%d\n", result);
    return 0;
}
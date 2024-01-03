#include <stdio.h>

#define BUFFER_SIZE 6

/* 交换两个整数 */
int swap(int *val1, int *val2)
{
    int ret = 0;
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
    return ret;
}

/* 数组作函数参数会自动弱化成指针 */
int printArray(int *array, int arraySize)
{
    int ret = 0;
    if (array == NULL)
    {
        return ret;
    }
    for (int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d]:%d\n", idx, array[idx]);
    }
    return ret; 
}

/* 时间复杂度 o(n)^2 */
void bubbleSort01(int *array, int len)
{
    for (int end = len; end > 0; end--)
    {
        /* 已经排好序的标志 */
        for (int begin = 1; begin < end; begin++)
        {
            /* 后面的数字比前面的数字小就交换 */
            if (array[begin - 1] > array[begin])
            {
                swap(&array[begin], &array[begin - 1]);
            }
        }
    }
}

/* 优化1 */
void bubbleSort02(int *array, int len)
{
    for (int end = len; end > 0; end--)
    {
        /* 已经排好序的标志 */
        int sorted = 1;
        for (int begin = 1; begin < end; begin++)
        {
            /* 后面的数字比前面的数字小就交换 */
            if (array[begin - 1] > array[begin])
            {
                swap(&array[begin], &array[begin - 1]);
                /* 没有排好序 */
                sorted = 0;
            }
        }
        if (sorted == 1)
        {
            break;
        }
    }
}

/* 优化2 */
void bubbleSort03(int *array, int len)
{
    if (array == NULL)
    {
        return;
    }
    int sortedIndex = 0;
    for (int end = len; end > 0; end--)
    {
        /* 已经排好的索引 */
        sortedIndex = 1;
        for (int begin = 1; begin < end; begin++)
        {
            /* 后面的数字比前面的数字小就交换 */
            if (array[begin - 1] > array[begin])
            {
                swap(&array[begin], &array[begin - 1]);
                /* 更新排好序的索引 */
                sortedIndex = begin;
            }
        }
        /* 更新 */
        end = sortedIndex;
    }
}

int main()
{
    int array[] = {11, 36, 24, 107, 23, 65};
    int len = sizeof(array) / sizeof(array[0]);

    bubbleSort02(array, len);
    printArray(array, len);
    return 0;
}
#include <stdio.h>

/* 选择排序相较于冒泡排序，减少了交换的次数 */

#define BUFFER_SIZE 7

/* 数组作函数参数会自动弱化成指针 */
int printArray(int *array, int arraySize)
{
    for (int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d]:%d\n", idx, array[idx]);
    }
}

int selectSort01(int *array, int len)
{
    int ret = 0;
    int minValue = 0;
    int minIndex = 0;
    for (int pos = 0; pos < len; pos++)
    {
        minValue = array[pos];
        for (int begin = pos + 1; begin < len; begin++)
        {
            /* 遍历到的元素比最小值小 更新元素 */
            if (minValue > array[begin])
            {
                minValue = array[begin];
                minIndex = begin;
            }
        } 
        if (array[pos] > minValue)
        {
            int temp = array[pos];
            array[pos] = minValue;
            array[minIndex] = temp;
        }      
    }
    return ret;
}

int main()
{
    int array[] = {11, 36, 24, 107, 23, 65};
    int len = sizeof(array) / sizeof(array[0]);
#if 0
    int min = 0;
    int minIndex = 0;
    for (int pos = 0; pos < len; pos++)
    {
        min = array[pos];
        for (int begin = pos + 1; begin < len; begin++)
        {
            /* 遍历到的元素比最小值小 更新元素 */
            if (min > array[begin])
            {
                min = array[begin];
                minIndex = begin;
            }
        } 
        if (array[pos] > min)
        {
            int temp = array[pos];
            array[pos] = min;
            array[minIndex] = temp;
        }      
    }
#endif
    selectSort01(array, len);
    printArray(array, len);
    return 0;
}



#if 0
int main()
{
    
    int minPos = 0;
    int arr[BUFFER_SIZE] = {1, 30, 24, 5, 58, 12, 39};
    int minNum = 0;
    for(int begin = 0; begin < BUFFER_SIZE; begin++)
    {
        minNum = arr[begin + 1];
        for(int jdx = begin + 1; jdx < BUFFER_SIZE; jdx++)
        {            
            if (arr[jdx] < minNum)
            {
                minNum = arr[jdx];
                minPos = jdx;
            }
        }
        if (arr[begin] > minNum)
        {
            int temp = arr[begin];
            arr[begin] = arr[minPos];
            arr[minPos] = temp;
        }        
    }
    for(int begin = 0; begin < BUFFER_SIZE; begin++)
    {
        printf("arr[%d]:%d\t", begin, arr[begin]);
    }
    printf("\n");   
    return 0;
}
#endif
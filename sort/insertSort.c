#include <stdio.h>



int insertSort(int *array, int len)
{
    int ret = 0;
    int temp = 0;
    for (int pos = 1; pos < len; pos++)
    {
        temp =array[pos];
        int begin = 0;
        for (begin = pos; begin > 0; begin--)
        {
            if (array[begin - 1] > temp)
            {
                array[begin] = array[begin - 1];
            }
            else
            {
               break;
            }
        }
        array[begin] = temp;
    }
    return ret;
}

int printArray(int *array, int arraySize)
{
    int ret = 0;
    for (int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d]:%d\n", idx, array[idx]);
    }
    return 0;
}



int insertSort01(int *array, int length)
{
    int ret = 0;
    int num = 0;
    for (int pos = 1; pos < length; pos++)
    {
        num = array[pos];
        for (int idx = pos; idx >= 0; idx--)
        {
            if (array[idx - 1] > num)
            {
                array[idx] = array[idx - 1];
            }
            else
            {
                array[idx] = num;   //错误  idx = 0的情况无法赋值
                break;
            }
        }
    }
    return ret;
}

int main()
{
    int array[] = {167, 36, 24, 107, 23, 65, 1, 4};
    int len = sizeof(array) / sizeof(array[0]);
    //insertSort01(array, len);
    insertSort(array, len);
    printArray(array, len);
    return 0;
}
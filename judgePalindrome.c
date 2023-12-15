#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define BUFFER_SIZE 10

enum STATUS_CODE
{
    FALSE,
    TRUE
};


int judgePalindrome(char *array, int len)
{
    int ptr1 = 0;
    int ptr2 = 0;
    for(int ptr1 = 0; ptr1 < len ; ptr1++)
    {
        if(array[ptr1] <= 'z' && array [ptr1] >= 'a')
        {
            array[ptr2++] = array[ptr1];
        }
        else if(array[ptr1] <= 'Z' && array [ptr1] >= 'A')
        {
            array[ptr2++] = array[ptr1] + 32;
        }
        else
        {
            array[ptr2++] = ' ';
        }
    }
    array[ptr2++] = '\0';
    for(int idx = 0; idx < ptr2 / 2; idx++)
    {
        if(array[idx] != array[ptr2 - idx - 1])
        {
            return FALSE;
        }
    }
    return TRUE;
}

int main()
{
    char array[BUFFER_SIZE] = "Aolba i kj";
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        printf("array[%d] = %c\n", idx, array[idx]);
    }
    printf("array[1]:%c\n", array[1]);
    printf("\n");
    int result = judgePalindrome(array,sizeof(array));
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        printf("array[%d] = %c\n", idx, array[idx]);
    }
    printf("array[2]:%c\n", array[2]);
    if(result == 1)
    {
        printf("该字符串是回文串\n");
    }
    else
    {
        printf("该字符串不是回文串\n");
    }
    return 0;
}
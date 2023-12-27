
#if 0

本章节重点说明：
1、数组作为函数形参的写法
2、函数返回数组的限制

【数组作为函数形参的写法】
一维数组，int arr[5];
    fun(int *p)  // fun(arr);
    fun(int p[]) // fun(arr);
    fun(int p[5]) // fun(arr);  如果知道数组大小的写法，一般是以上面两种写法
    重要的转换公式： *p = *(p + 空) = p[]

二维数组，int arr[2][3];
    fun(int (*p)[3])  // fun(arr);
    fun(int p[][3]) // fun(arr);
    fun(int p[2][3]) // fun(arr);  如果知道数组大小的写法，一般是以上面两种写法

特别：函数并不检查数组的边界，所以函数形参需要将大小，作为另一参数传入

【函数返回数组的限制】：
1、不允许把整个数组作为返回值，但可以返回数组的指针；

#endif

#include <stdio.h>

int arr[3] = {1, 2, 3};

int arr_2[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};

int sum_arr(int *p, int size)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        count += p[i];
    }
    
    return count;
}

int sum_arr2(int (*p)[3], int size)
{
    int count = 0;

    printf("size:%d\n", size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            count += p[i][j];
        }
    }
    
    return count;
}

int* getStaticFunArray(void)
{
    static int s_arr[5] = {1, 2, 3, 4, 5};

    return s_arr;
}

int main(int argc, char const *argv[])
{
    // 函数传递数组
    printf("arr sum:%d\n", sum_arr(arr, sizeof(arr)/sizeof(int)));
    printf("arr sum:%d\n", sum_arr2(arr_2, sizeof(arr_2)/sizeof(int[3])));

    int *p = NULL;
    p = getStaticFunArray();
    for (int i = 0; i < 5; i++)
    {
        printf("s_arr[%d] = %d\n", i, p[i]);
    }
    

    return 0;
}
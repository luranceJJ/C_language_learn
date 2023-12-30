

#if 0

【指针支持的运算方式】：
1、++、--、+、-
    int a[5];
    int *p = a;
++  p++ 指针向前偏移一个地址；（地址大小就是指针指向的数据类型大小，这里p就是一个int大小
--  p-- 指针向后偏移一个地址；（地址大小就是指针指向的数据类型大小，这里p就是一个int大小
+   p+n 指针向前偏移n个地址
-   p-n 指针向前偏移n个地址

【指针比较】
1、指针相加/相减

指针相加，没啥特别含义，单纯的数据加运算
指针相减，一般用于计算字符串长度、数组长度或指针间的数据index偏差

#endif

#include <stdio.h>

#define ARR_MAX (5)

int main(int argc, char const *argv[])
{
    int arr[ARR_MAX] = {2, 4, 6, 8, 10};
    int *p = arr;
    int *q = &arr[ARR_MAX-1];

    //通过指针++，+ 遍历数组
    // for (int i = 0; i < ARR_MAX; i++)
    // {
    //     // printf("arr[%d] = %d\n", i, *(p+i));
    //     // printf("arr[%d] = %d\n", i, p[i]);
    //     printf("arr[%d] = %d\n", i, *(p++));  //这3种写法作用相同
    // }

    //通过指针--，- 遍历数组
    // for (int i = ARR_MAX-1, j = 0; i >= 0; i--, j--)
    // {
    //     printf("arr[%d] = %d, j:%d\n", i, *(q+j), j);  // 这种特别注意，因为j是负数了，如果是q-j就变成了q+j，不符合我们预期
    //     // printf("arr[%d] = %d, j:%d\n", i, q[j], j);
    //     // printf("arr[%d] = %d\n", i, *(q--));  //上面这3种写法作用相同
    // }
    

    //指针相加
    printf("*p + *q = %d\n", *p + *q);

    //指针相减
    printf("*q - *p = %d\n", *q - *p);

    for (int i = 0; i < ARR_MAX; i++)
    {
        printf("arr[%d] addr = %p\n", i, &arr[i]);
    }
    printf("q addr:%p, p addr:%p\n", q, p);
    printf("q - p index = %ld\n", (q - p)); // 这个有问题，难道不能通过数组指针相减

    char str[] = "hello world";
    char *s_head = str;
    char *s_tail;

    for (int i = 0; str[i] != '\0'; i++)
    {
        s_tail = &str[i];
    }
    printf("s_tail - s_head = %ld\n", s_tail - s_head + 1);//字符串长度统计

    return 0;
}
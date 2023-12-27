
#if 0

【静态数组】：
1、定义时，需指定好大小，编译时就分配好空间；
    int arr[5];

【动态数组】：
1、定义时，不需要指定大小，运行时再申请内存；
2、动态数组是在运行时通过动态内存分配函数（如 malloc 和 calloc）手动分配内存的数组；
3、声明周期由程序控制，申请内存后，可释放, 若忘记释放，则会导致内存泄漏；

#endif

#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE (5)

int main(int argc, char const *argv[])
{
    // 动态申请内存，因为可能会申请失败，所以申请内存必须要判空
    int *p = (int*)malloc(sizeof(int) * ARR_SIZE);
    if (NULL == p)\
    {
        printf("malloc error.\n");
    }

    for (int i = 0; i < ARR_SIZE; i++)
    {
        p[i] = i;
        printf("p[%d] = %d\n", i, p[i]);
    }
    
    // 动态内存使用完成，必须free及时释放，避免发生内存泄漏
    free(p);

    return 0;
}

#if 0

【二级指针】
1、指向指针的指针，通常也叫二级指针；
2、二级指针存放的，是一级指针的地址；

【二级指针的常用场合】
1、传递给函数，更换指针的指向（比如，申请内存后，返回内存地址；链表修改指针指向等等）

【扩展：N级指针】
int a = 5;
int *p = &a;  //一级指针
int **q = &p; //二级指针
int **z = &q; //三级指针 （依次类推到N级指针）

#endif

#include <stdio.h>
#include <stdlib.h>


int* get_intarray_memory(int **p)
{
    int *arr = (int*)malloc(30*sizeof(int));
    if ( NULL == arr )
    {
        printf("apply int memory error.\n");
    }
    else
    {
        *p = arr;
        printf("apply memory succeed, addr:%p\n", arr);
    }

    return arr;
}

int main(int argc, char const *argv[])
{
    int a = 5;
    int *p = &a;  //一级指针
    int **q = &p; //二级指针
    int ***z = &q; //三级指针 （依次类推到N级指针）

    printf( "a = %d, a addr:%p\n", a, &a );
    printf( "*p = %d, p = %p, &p addr:%p\n", *p, p, &p);
    printf( "**q = %d, q = %p, *q add:%p\n", **q, q, *q);
    printf( "***z = %d, z = %p, *z add:%p\n", ***z, z, *z);


    // 通过函数返回指针，或者二级指针返回
    int *gp;
    gp = get_intarray_memory(q);
    printf( "p = %p\n", p);
    printf( "*q add:%p\n", *q);
    printf( "gp addr:%p\n", gp );

    return 0;
}


#if 0

【枚举的定义】：
1、枚举是 C 语言中的一种基本数据类型，用于定义一组具有离散值的常量，它可以让数据更简洁，更易读。
2、枚举类型通常用于为程序中的一组相关的常量取名字，以便于程序的可读性和维护性。
3、定义一个枚举类型，需要使用 enum 关键字，后面跟着枚举类型的名称，
以及用大括号 {} 括起来的一组枚举常量。每个枚举常量可以用一个标识符来表示，
也可以为它们指定一个整数值，如果没有指定，那么默认从 0 开始递增。


【枚举的语法】：
enum　枚举名　{枚举元素1,枚举元素2,……,枚举元素n};


【枚举的自动赋值】：
enum E_NUM
{
    NUM0,    // 为0， 不赋初值的话，第一个枚举值默认为0
    NUM1,   //为1,默认是以上一个枚举值+1
    NUM2,   //为2,默认是以上一个枚举值+1
    NUM3 = 5,  //为5，以赋值的为准
    NUM4   //为6,默认是以上一个枚举值+1
};


【枚举的定义】：
enum E_NUM
{
    NUM0,   
    NUM1
}number;   //方法一：声明的时候定义

enum E_NUM number; //方法二、先有枚举再定义；

enum
{
    NUM0,   
    NUM1
}number;   //方法三：省略枚举名，直接定义


【特殊说明】：
1、因为枚举支持自定义赋值，如果不是连续情况，是没办法遍历的；

#endif


#include <stdio.h>

enum WEEK
{
    MON=1, 
    TUE, 
    WED, 
    THU, 
    FRI, 
    SAT, 
    SUN,
    MAX
};

int main(int argc, char const *argv[])
{
    enum WEEK weeken;
    int a = 5;

    // 枚举是连续的，可以通过循环遍历
    for (weeken = MON; weeken < MAX; weeken++)
    {
        printf("loop WEED %d\n", weeken);
    }
    
    weeken = (enum WEEK)a;  //强制类型转换为枚举值
    printf("==>weeken %d\n", weeken);

    return 0;
}


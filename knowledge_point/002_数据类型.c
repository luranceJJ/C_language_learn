#include <stdio.h>

//【1】数据类型的定义
// 在 C 语言中，数据类型指的是用于声明不同类型的变量或函数的一个广泛的系统。
// 变量的类型决定了变量存储占用的空间，以及如何解释存储的位模式

//【2】数据类型的种类
// C 中的类型可分为以下几种
// 序号	类型与描述
// 1	基本数据类型
// 说  明	字符型	短整型	整型	长整型	单精度浮点型	双精度浮点型	无类型
// 数据类型	char	short	int	   long	  float	          double	    void

// 2	枚举类型：
// 它们也是算术类型，被用来定义在程序中只能赋予其一定的离散整数值的变量。

// 3	void 类型：
// 类型说明符 void 表示没有值的数据类型，通常用于函数返回值。

// 4	派生类型：
// ：包括数组类型、指针类型和结构体类型。

//【3】数据类型的大小
// 说  明	字符型	短整型	整型	长整型	单精度浮点型	双精度浮点型
// 数据类型	char	short	int	long	float	double
// 长  度	  1	    2	    4	4	    4	    8
// 注意：数据大小跟系统位数有关，可以使用sizeof函数确认

#if 1
void main(void)
{
    char c1 = 5;
    char c2 = 'C';
    char c3 = 0xff;  // 0x7f=127, 0x80=-128, 0xff=-1
    unsigned c4 = 0xff;

    short s1 = 0xffff;
    unsigned short s2 = 0xffff;
    
    printf("c1:%d, c2:%d, c3:%d, c4:%d, s1:%d, s2:%d\n", c1, c2, c3, c4, s1, s2);
}
#endif
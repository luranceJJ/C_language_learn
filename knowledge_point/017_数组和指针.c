

#if 0

1、系统变量类型数组；
2、字符串数组；（元素都是指针，指针类型是char型）
3、指针数组；（数组元素都是指针，比如指向字符串、函数、数组、结构体数组等等）
4、结构体数组；

这些不同类型的数组，和指针的结合，通常使用方法；

#endif

#include <stdio.h>

#define CLASS_STUDENT_NUMBER_MAX (3)

struct student_msg
{
    int id;
    char name[32];
};


int main(int argc, char const *argv[])
{
    // 定义指针数组 & 遍历
    char *class_student_name[CLASS_STUDENT_NUMBER_MAX] = { 
        "xiaoming", "xiaohong", "xiaoqiang" };
    for (int i = 0; i < CLASS_STUDENT_NUMBER_MAX; i++)
    {
        printf("student [%d] name is %s\n", i, class_student_name[i]);
    }
    
    // 定义整形数组和整形数组指针
    int arr[3] = {1, 2, 3};
    int *ip[3];
    for (int i = 0; i < 3; i++)
    {
        ip[i] = &arr[i]; //将数组指针指向arr数组的每一个元素
    }

    for (int i = 0; i < 3; i++)
    {
        printf("ip[%d] = %d\n", i, *(ip[i])); // 打印数组元素的值
    }
    
    // 定义一个结构体数组
    struct student_msg class_one[3] = {
        {.id = 1, .name = "xiaoming"},
        {.id = 2, .name = "xiaohong"},
        {.id = 3, .name = "xiaoqiang"}
    };
    // 定义一个结构体指针，并遍历数组元素值
    struct student_msg *p_stu = class_one;
    for (int i = 0; i < 3; i++)
    {
        printf("class student id[%d], name:%s\n", p_stu->id, p_stu->name);
        p_stu++;
    }
    

    return 0;
}



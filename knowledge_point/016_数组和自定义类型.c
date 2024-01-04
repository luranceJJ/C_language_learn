
#if 0

本章节重点说明数组和自定义类型的组合

【数组和结构体】

【数组和枚举】

#endif

#include <stdio.h>

struct student_msg
{
    int id;
    char name[32];
};

enum class_level
{
    CLASS_LEVEL_ONE,
    CLASS_LEVEL_TWO,
    CLASS_LEVEL_THREE
};

int main(int argc, char const *argv[])
{
    // 定义一个结构体数组
    struct student_msg class_one[3] = {
        {.id = 1, .name = "xiaoming"},
        {.id = 2, .name = "xiaohong"},
        {.id = 3, .name = "xiaoqiang"}
    };
    for (int i = 0; i < 3; i++)
    {
        printf("class student id[%d], name:%s\n", class_one[i].id, class_one[i].name);
    }
    
    enum class_level qinghua_school[3] = {CLASS_LEVEL_ONE, CLASS_LEVEL_ONE, CLASS_LEVEL_TWO};
    for (int i = 0; i < 3; i++)
    {
        printf("qinghua_school [%d] level is %d\n", i, qinghua_school[i]);
    }
    

    return 0;
}
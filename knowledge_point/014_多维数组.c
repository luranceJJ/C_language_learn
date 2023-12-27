
#if 0

【定义】：
1、C语言支持多维数组，一般形式：
    type name[size1][size2]...[sizeN];



【常见的数组定义】：
    int arr[3] = {1, 2, 3}; //一维数组
    int arr[2][3] = { {1, 2, 3}, {4, 5, 6} }; //二维数组，即N个一维数组的集合
    int arr[2][2][3] = {{ {1, 2, 3}, {4, 5, 6} }
                        , { {7, 8, 9}, {10, 11, 12} }}; //三维数组，即N个二维数组的集合

对于二维数组来说，两个数组代表：[行数][列数]
对于三维数组来说，三个数组代表：[面数][行数][列数]


【数组访问的等效写法，关键】：
一维数组：
    int a[5];
    int *p = a; // 或int *p = &a[0];
    那么 p==a,衍生出：p[i] == a[i]
    指针偏移：p[i] == *(p+i) // 指针访问[]内容，都是要解引用

二维数组：
    int a[2][3];
    int (*p)[3] = a; //或int (*p)[3] = &a[0][0]; //这里要注意，定义二维数组指针，必须制定列数
    那么 p == a，衍生出： p[i][j] == a[i][j]
    指针偏移：p[i][j] == *(&p[i][j]) == *(p[i]+j) == *(*(p+i)+j) // 指针访问[]内容，都是要解引用，这里二维两个[]需要两个*解引用

三维数组：
    int a[2][2][3];
    int (*p)[2][3] = a; //或int (*p)[2][3] = &a[0][0][0]; //这里要注意，定义三维数组指针，必须制定行、列数
    那么 p == a, 衍生出：p[i][j][k] == a[i][j][k]
    指针偏移：p[i][j][k] = (*(&p[i][j]))[k] = (*(p[i]+j))[k] //遵守从左往右拆解即可

#endif

#include <stdio.h>


// 定义一个全局的二维数组
int arr_2[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};

// 定义一个全局的三维数组
int arr_3[2][2][3] = {
    {{1, 2, 3}, {4, 5, 6}},
    {{7, 8, 9}, {10, 11, 12}}
};

int main(int argc, char const *argv[])
{
    // 参考网址：https://blog.csdn.net/TianYanRen111/article/details/118940004

    int (*p2)[3] = NULL;  //定义一个指针，类型为列数为3的整形二维数组
    int (*p3)[2][3] = NULL;//定义一个指针，类型为行数为2，列数为3的整形三维数组

    p2 = arr_2;
    // p2 = &arr_2[0][0]; //作用同上
    // p3 = arr_3;
    p3 = &arr_3[0][0][0];//作用同上

    //二维数组的访问
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //几种写法，作用是等效的
            // printf("arr_2[%d][%d] = %d\n", i, j, arr_2[i][j]); 
            // printf("arr_2[%d][%d] = %d\n", i, j, p2[i][j]);
            // printf("arr_2[%d][%d] = %d\n", i, j, *(&p2[i][j]));
            // printf("arr_2[%d][%d] = %d\n", i, j, *(p2[i]+j));
            // printf("arr_2[%d][%d] = %d\n", i, j, *(*(p2+i)+j));
            // printf("arr_2[%d][%d] = %d\n", i, j, (*(p2+i))[j]);
            // printf("arr_2[%d][%d] = %d\n", i, j, *(*(p2+i)+j));
        }
    }
    
    //三维数组的访问
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                //几种写法，作用是等效的
                // printf("arr_3[%d][%d][%d] = %d\n", i, j, k, arr_3[i][j][k]);
                // printf("arr_3[%d][%d][%d] = %d\n", i, j, k, p3[i][j][k]); 
                // printf("arr_3[%d][%d][%d] = %d\n", i, j, k, *(&p3[i][j][k])); 
                // printf("arr_3[%d][%d][%d] = %d\n", i, j, k, (*(&p3[i][j]))[k]); 
                // printf("arr_3[%d][%d][%d] = %d\n", i, j, k, (*(p3[i]+j))[k]); 
                // printf("arr_3[%d][%d][%d] = %d\n", i, j, k, (*(*(p3+i)+j))[k]); 
                // printf("arr_3[%d][%d][%d] = %d\n", i, j, k, *(*(*(p3+i)+j)+k));

                // printf("arr_3[%d][%d][%d] = %d\n", i, j, k, (*(p3+i))[j][k]);  
            }
        }
    }

    // 等效地址
    // printf("arr_3 addr = %p\n", arr_3);
    // printf("arr_3[0][0][0] addr = %p\n", &arr_3[0][0][0]);
    // printf("p3 addr = %p\n", p3);

    return 0;
}
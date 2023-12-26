
#if 0

【数组的定义】：
1、存储一个或多个系统或自定义类型的元素集合;
2、它可以存储一个固定大小的相同类型元素的顺序集合；
3、可通过下标访问，注意的是，下标是从0开始计数的；


【数组的声明】：
1、 C 中要声明一个数组，需要指定元素的类型和元素的数量
    type arrayName [ arraySize ];  //一维数组
    arraySize 必须是一个大于零的整数常量
    type 可以是任意有效的 C 数据类型

特别注意：arraySize 必须是编译前就知道的大小，不允许是运行时再动态调整。
    int a = 5;
    int arr_num[a];  // 这样是不允许的


【数组的初始化】：
1、可以逐个初始化，也可以一起；
例子：int arr_num[5] = {1, 2, 3, 4, 5};  //注意，这样写要确保{}数据不要超过数组大小

2、一般如果直接初始化，可以不写入大小，程序会自动算
例子：int arr_num[] = {1, 2, 3, 4, 5};  // 程序会自动推算出大小，sizeof(arr_num)/sizeof(int) == 5

3、给数组每个元素都初始化，比如置为0
例子：int arr_num[5] = {0};
      int arr_num[5];  //局部数组，如果没有初始化，那么数字内部原始数据是脏数据，和函数内局部变量一致


【数组大小测量】：
1、sizeof(array_name);  //测量数字大写
2、sizeof(array_name)/sizeof(array type)  //测量数组长度
3、sizeof(array_name)/sizeof(array_name[0])  //测量数组长度,作用同上，两种写法


【数组的访问】：
1、通过下标访问
    array_name[index];


【数组名】：
1、数组名表示数组的地址，即数组首元素的地址；
2、数组名本身是一个常量指针，意味着它的值是不能被改变的，一旦确定，就不能再指向其他地方；
3、可以使用&运算符来获取数组的地址
    int array_num[5] = {0};
    int *ptr = &array_num[5]; //定义一个整数指针ptr指向数组array_num
    int *ptr = array_num;  //作用同上，只是写法不同而已
特别注意：传递数组到函数，必须传递数组size，因为函数只能定义数组指针接收数组，这一点尤为注意


#endif

#include <stdio.h>

int g_arr_num[5];  // 全局变量，数组元素默认会被初始化为0

// 函数数组形参写法1
void printArray(int arr[], int arr_len)
{
    int arr_size;
    arr_size = sizeof(arr)/sizeof(int);
    printf("int %d\n", sizeof(int));
    printf("arr_len:%d, arr_size:%d\n", arr_len, arr_size);  // arr_len==5, arr_size==2 

    for (int i = 0; i < arr_len; i++)
    {
        printf( "arr[%d] = %d\n", i, arr[i] );
    }
}

// 函数数组形参写法2
void printArray1(int *arr, int arr_len)
{
    int arr_size;
    arr_size = sizeof(arr)/sizeof(int);
    printf("int %d\n", sizeof(int));
    printf("arr_len:%d, arr_size:%d\n", arr_len, arr_size);  // arr_len==5, arr_size==2 

    for (int i = 0; i < arr_len; i++)
    {
        printf( "arr[%d] = %d\n", i, arr[i] );
    }
}

int main(int argc, char const *argv[])
{
    // int arr_num[5];// 局部变量，数组元素为脏数据
    int arr_num[5] = {0};// 局部变量，数组元素初始化为0
    int arr_size;
    
    // arr_size = sizeof(arr_num)/sizeof(int);
    arr_size = sizeof(arr_num)/sizeof(arr_num[0]); //作用同上
    for (int i = 0; i < arr_size; i++)
    {
        printf( "arr_num[%d] = %d\n", i, arr_num[i] );
        printf( "g_arr_num[%d] = %d\n", i, g_arr_num[i] );
    }

    printf("----------------------\n");
    printArray(arr_num, arr_size);  // 函数内无法计算数组大小，所以传递数组到函数，必须传递数组大小

    printf("----------------------\n");
    printArray1(arr_num, arr_size);
    

    return 0;
}


#if 0

【常量的定义】：
常量是固定值，在程序执行期间不会改变。
常量可以是任何的基本数据类型，比如整数常量、浮点常量、字符常量，或字符串字面值，也有枚举常量。
常量就像是常规的变量，只不过常量的值在定义后不能进行修改。
常量可以直接在代码中使用，也可以通过定义常量来使用。


【整数常量】：
    0b1101     /* 二进制，0b开头，b不区分大小写*/
    85         /* 十进制 */
    0213       /* 八进制，0开头 */
    0x4b       /* 十六进制，0x开头，X不区分大小写 */
    30         /* 整数 */
    30u        /* 无符号整数 ，后缀U代表无符号整数，u不区分大小写*/
    30l        /* 长整数 ，后缀l代表long型，l不区分大小写*/
    30ul       /* 无符号长整数 , ul可以结合，也可以写成lu，不区分顺序*/


【浮点数常量】：
浮点常量由整数部分、小数点、小数部分和指数部分组成。可以使用小数形式或者指数形式来表示浮点常量。
当使用小数形式表示时，必须包含整数部分、小数部分，或同时包含两者。当使用指数形式表示时， 
必须包含小数点、指数，或同时包含两者。带符号的指数是用 e 或 E 引入的。
    3.14159       /* 合法的 */
    314159E-5L    /* 合法的 */
    510E          /* 非法的：不完整的指数 */
    210f          /* 非法的：没有小数或指数 */
    .e55          /* 非法的：缺少整数或分数 */
    
float myFloat = 3.14f; //浮点数常量可以带有一个后缀表示数据类型
double myDouble = 3.14159;


【字符常量】：
字符常量是括在单引号中，例如，'x' 可以存储在 char 类型的简单变量中。
字符常量可以是一个普通的字符（例如 'x'）、一个转义序列（例如 '\t'），或一个通用的字符（例如 '\u02C0'）。
在 C 中，有一些特定的字符，当它们前面有反斜杠时，它们就具有特殊的含义，被用来表示如换行符（\n）或制表符（\t）等
    转义序列	含义
    \\	\ 字符
    \'	' 字符
    \"	" 字符
    \?	? 字符
    \a	警报铃声
    \b	退格键
    \f	换页符
    \n	换行符
    \r	回车
    \t	水平制表符
    \v	垂直制表符
    \ooo	一到三位的八进制数
    \xhh . . .	一个或多个数字的十六进制数


【字符串常量】:
字符串字面值或常量是括在双引号 " " 中的。一个字符串包含类似于字符常量的字符：普通的字符、转义序列和通用的字符。
可以使用反斜杠做分隔符，把一个很长的字符串常量进行分行。
    下面这三种形式所显示的字符串是相同的
    *"hello, dear"
    *"hello, \
    dear"
    *"hello, " "d" "ear"
字符串常量在内存中以 null 终止符 \0 结尾
char myString[] = "Hello, world!"; //系统对字符串常量自动加一个 '\0'


【定义常量】：
使用 #define 预处理器： #define 可以在程序中定义一个常量，它在编译时会被替换为其对应的值。
使用 const 关键字：const 关键字用于声明一个只读变量，即该变量的值不能在程序运行时修改。
    #define 常量名 常量值
    #define PI 3.14159

    const 数据类型 常量名 = 常量值;  // 注意：const 声明常量要在一个语句内完成
    const int MAX_VALUE = 100;  （√）
    const int var;
    var = 5;   (×)

编程好习惯：把常量定义为大写字母形式，是一个很好的编程习惯


【#define 与 const 区别】：
#define 与 const 这两种方式都可以用来定义常量，选择哪种方式取决于具体的需求和编程习惯。
通常情况下，建议使用 const 关键字来定义常量，因为它具有类型检查和作用域的优势，
而 #define 仅进行简单的文本替换，可能会导致一些意外的问题。
    #define 预处理指令和 const 关键字在定义常量时有一些区别：
    替换机制：#define 是进行简单的文本替换，而 const 是声明一个具有类型的常量。#define 定义的常量在编译时会被直接替换为其对应的值，而 const 定义的常量在程序运行时会分配内存，并且具有类型信息。
    类型检查：#define 不进行类型检查，因为它只是进行简单的文本替换。而 const 定义的常量具有类型信息，编译器可以对其进行类型检查。这可以帮助捕获一些潜在的类型错误。
    作用域：#define 定义的常量没有作用域限制，它在定义之后的整个代码中都有效。而 const 定义的常量具有块级作用域，只在其定义所在的作用域内有效。
    调试和符号表：使用 #define 定义的常量在符号表中不会有相应的条目，因为它只是进行文本替换。而使用 const 定义的常量会在符号表中有相应的条目，有助于调试和可读性。

#endif

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 整形常量
    unsigned int bin_num = 0b1101;
    unsigned int decimalism_num = 100;
    unsigned int octonary_num = 020;
    unsigned int hexadecimal_num = 0xff;
    unsigned int us_num = 65536u;
    unsigned long ul_num = 123456789ul;

    printf( "bin_num:%d, decimalism_num:%d, octonary_num:%d, hexadecimal_num:%d, us_num:%d, ul_num:%ld.\n", bin_num, decimalism_num, octonary_num, hexadecimal_num, us_num, ul_num);
    //字符串可以通过"\"来换行
    printf( "bin_num:%d, decimalism_num:%d, octonary_num:%d, hexadecimal_num:%d \
    , us_num:%d, ul_num:%ld.\n", bin_num, decimalism_num, octonary_num, hexadecimal_num, us_num, ul_num);
    
    float myFloat = 3.14f; //浮点数常量可以带有一个后缀表示数据类型
    double myDouble = 3.14159;
    printf( "myFloat:%f, myDouble:%f\n", myFloat, myDouble );

    char myString[] = "123456789"; //因为默认字符串后缀有'\0'，所以该字符串长度为10
    printf( "myString:%s, sizeof(myString):%ld\n", myString, sizeof(myString) );

    return 0;
}
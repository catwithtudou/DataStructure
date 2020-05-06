#ifndef STATUSLIB_H_INCLUDED
#define STATUSLIB_H_INCLUDED

/**
*       第五章串示例
*       课程相关状态码及宏函数的定义
*/

#include <stdio.h>
#include <stdlib.h>

/** 状态码 */
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define EQ 0   //=
#define GT 1   //>
#define LT -1  //<
#ifndef STATUS_H_  //若系统中已经有以下状态码的定义,就不再重复定义
#define OVERFLOW  -2  //堆栈上溢 超过所能表示的最大正数
#define UNDERFLOW -3  //堆栈下溢 超过所能表示的最小负数
#endif // STATUS_H_

typedef int Status; //自定义一个状态码识别类型




#endif // STATUSLIB_H_INCLUDED

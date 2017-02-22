//
//  SeqList.h
//  C语言算法
//
//  Created by pengkai on 2017/2/21.
//  Copyright © 2017年 changpengkai. All rights reserved.
//

#ifndef SeqList_h
#define SeqList_h

#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE   100
typedef int  ElementType;

// 声明一个线性列表
typedef struct SeqList {
    ElementType element[MAXSIZE];   // 存放数据域的连续数组
    int length;                     // 线性表的真实长度
}SeqList;

// 初始化线性表
bool initLinelist(SeqList * SeqList);

// 动态分配内存
void initLineListWithMalloc(SeqList ** SeqList);
// 释放内存
void deallocLinelist(SeqList ** SeqList);

// 查询操作
ElementType getElement(SeqList SeqList, int index);
// 插入操作 （index >= 1）
bool insertElement(SeqList *SeqList, int index, ElementType element);
// 删除操作
bool deleteElement(SeqList *SeqList, int index);
// 更新操作
bool updateElement(SeqList *SeqList, int index, ElementType element);
// 打印所有元素
void listAllElement(SeqList SeqList);
#endif /* SeqList_h */

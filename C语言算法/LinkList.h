//
//  LinkList.h
//  C语言算法
//
//  Created by pengkai on 2017/2/22.
//  Copyright © 2017年 changpengkai. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

/*单向链表*/
#include <stdio.h>
#include <stdbool.h>

typedef int ElementType;

typedef struct Node {
    ElementType data;   // 数据域
    int lenght;         // 链表长度
    
    struct Node *next;  // 指针域，指向下一个节点
    
}*LinkList,Node;

// 初始化链表(实质是返回链表头结点的指针)
LinkList initLinkList();

// 赋值操作(尾插法,新增元素总是在尾部)
bool tailAssignLinkList(LinkList list,ElementType value);

// 链表所有元素
void listLinkList(LinkList list);
#endif /* LinkList_h */

//
//  LinkList.h
//  C语言算法
//
//  Created by pengkai on 2017/2/22.
//  Copyright © 2017年 changpengkai. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

/*单向链表，头结点，头指针，尾指针*/
#include <stdio.h>
#include <stdbool.h>

typedef int ElementType;

typedef struct node {
    
    ElementType  data;      // 数据域
    struct node  *next;     // 指针域
}LinkList,Node;

// 初始化链表，返回头结点 （头结点指向首元元素，首元元素索引默认从1开始）
LinkList * initLinkList();

// 遍历listHead指向链表的所有元素
void displayLinkList(LinkList *listHead);

// listHead指向链表的index位置，向前插入value
void insertLinkList(LinkList *listHead,int index,ElementType value);

// listHead指向链表的index位置，删除该元素
void deleteIndexInLinkList(LinkList *listHead,int index);

// listHead指向的链表，返回index所在的节点
Node * locationInLinkList(LinkList *listHead,int index);

// listHead指向的链表，返回value在链表中的索引
int indexInLinkList(LinkList *listHead,ElementType value);

// listHead指向的，返回链表的长度
int lengthOfLinklist(LinkList * listHead);

// 清空链表
void emptyLinkList(LinkList ** listHead);

// 反转链表
void reverseLinkList(LinkList * listHead);


#endif /* LinkList_h */

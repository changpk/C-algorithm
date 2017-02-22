//
//  LinkList.c
//  C语言算法
//
//  Created by pengkai on 2017/2/22.
//  Copyright © 2017年 changpengkai. All rights reserved.
//

#include "LinkList.h"
#include <stdlib.h>

LinkList initLinkList() {
   
    LinkList pHead = (LinkList)malloc(sizeof(Node));
    if (NULL == pHead) {
        printf("初始化链表失败");
        return NULL;
    }else{
        pHead->lenght = 0;
        pHead->data = -1; // 表明是头节点
        printf("初始化链表成功，链表长度是%d\n",pHead->lenght);
        return pHead;
    }
}

bool tailAssignLinkList(LinkList list,ElementType value) {
    
    LinkList pTail = (LinkList)malloc(sizeof(Node));
    
    // 找到最后的节点
    while (list->next != NULL) {
        list = list->next;
    }
    
    if (NULL == pTail) {
        printf("插入操作,初始化新节点失败\n");
        return false;
    }
    
    pTail->data = value;
    pTail->next = NULL;
    
    list->next = pTail;
    list->lenght ++ ;
  
    return true;
}

void listLinkList(LinkList list) {
    
    LinkList pHead = list;
    
    printf("链表的所有元素是：");
    int i = 0;
    while (pHead->next != NULL) {
        printf("[%d]=%d ",i,pHead->data);
        i ++ ;
        pHead = pHead->next;
    }
    printf("\n");
}

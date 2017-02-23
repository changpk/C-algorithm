//
//  LinkList.c
//  C语言算法
//
//  Created by pengkai on 2017/2/22.
//  Copyright © 2017年 changpengkai. All rights reserved.
//

#include "LinkList.h"
#include <stdlib.h>

LinkList * initLinkList() {
    
    LinkList *pHead,*pNewNode, *pTail;
    pHead = (LinkList *)malloc(sizeof(LinkList));
    if (NULL == pHead) {
        printf("初始化链表失败\n");
        return NULL;
    }
    pHead->next = NULL;
    
    // 尾指针初始化指向头结点
    pTail = pHead;
    
    printf("请输入链表元素（整数），空格分开,并以回车结尾\n");
    ElementType val;
    
    // 尾插法插入元素
    while (scanf("%d",&val) != EOF ) {
        // 新节点分配内存
        pNewNode = (LinkList *)malloc(sizeof(LinkList));
        // 新节点赋值
        pNewNode->data = val;
        if (NULL == pNewNode) {
            printf("生成节点内存分配失败\n");
            return pHead;
        }
        // 尾指针指向最新生成的节点
        pTail->next = pNewNode;
        // 尾指针移动到最新的节点，准备指向下一个新的节点
        pTail = pNewNode;
        
        if (getchar() == '\n') {
            // 赋值结束
            break;
        }
    }
    // 尾指针的Next指向为NULL
    pTail->next = NULL;
    if (NULL != pHead) {
        displayLinkList(pHead);
    }
    return pHead;
}

void displayLinkList(LinkList *  listHead) {
    
    if (listHead == NULL) {
        printf("链表不存在\n");
        return;
    }
    printf("链表所有的元素是:");

    if (NULL == listHead->next) {
        printf("空链表\n");
        return;
    }
    // 指向第一个节点
    LinkList *curNode = listHead->next;
    int index = 1 ;
    // 遍历到最后一个节点
    while (NULL != curNode->next) {
        printf("[%d]=%d ",index,curNode->data);
        curNode = curNode->next;
        index ++;
    }
    // 最后一个结点
    printf("[%d]=%d\n",index,curNode->data);

}

void insertLinkList(LinkList *listHead,int index,ElementType value) {
    
    /*
     1.找到[index-1]的Node
     2.NewNode的next指向[index]的Node
     3.[index-1]的Node的next指向NewNode
     */

    if (index < 1) {
        printf("无效的插入位置\n");
    }
    
    printf("在链表%d的位置插入%d\n",index,value);
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (NULL == newNode) {
        printf("生成节点内存分配失败\n");
        return;
    }
    newNode->data = value;
    
    // 1.找到[index-1]的Node
    Node *insertLastNode = locationInLinkList(listHead, index - 1);
    
    // 2.NewNode的next指向[index]的Node
    newNode->next = insertLastNode->next;
    
    // 3.[index-1]的Node的next指向NewNode
    insertLastNode->next = newNode;
    
    displayLinkList(listHead);
    
}

void deleteIndexInLinkList(LinkList *listHead,int index) {
    
    
    int length = lengthOfLinklist(listHead);
    
    if (index < 1 || index > length) {
        printf("删除索引无效\n");
        return;
    }
    
    /*
     1.找到[index-1]的Node
     2.记录[index]的Node，[index-1]的Node指向[index]的next
     3.释放[index]的Node的内存
     */
    
    printf("删除%d所在索引的元素",index);
    // 1.找到[index-1]的Node
    Node *deleteLastNode = locationInLinkList(listHead, index - 1);
    
    // 2.记录[index]的Node，[index-1]的Node指向[index]的next
    Node *deletedNode = deleteLastNode->next;
    deleteLastNode->next = deletedNode->next;
    
    // 3.释放[index]的Node的内存
    free(deletedNode);
    
    displayLinkList(listHead);
}


Node * locationInLinkList(LinkList *listHead,int index) {
    
    int currentIndex = 0;
    
    Node *currentNode = listHead;
    
    while (NULL != currentNode->next ) {
        
        if (currentIndex == index) {
            break;
        }
        
        currentNode = currentNode->next;
        currentIndex ++ ;
    }
    return currentNode;
}

int indexInLinkList(LinkList *listHead,ElementType value) {
    
    LinkList *currNode = listHead->next;
    
    int count = 0;
    
    while (NULL != currNode) {
        
        count ++;
        if (currNode->data == value) {
            break;
        }
        currNode = currNode->next;
    }
    
    if (0 == count) {
        printf("没有找到\n");
    }else{
        printf("元素%d在链表中的位置是%d\n",value,count);
    }
    return count;
}


int lengthOfLinklist(LinkList * listHead) {
    
    int count = 0;
    LinkList *currNode = listHead;
    while (NULL != currNode->next) {
        count ++;
        currNode = currNode->next;
    }
    return count;
}

void emptyLinkList(LinkList ** listHead) {
    
    // 这种写法，不能清空链表头，赋值过程就是copy过程
//    LinkList *curr = *listHead;
    while (NULL != (* listHead)->next) {
        LinkList *lastNode = (* listHead);
        (* listHead) = (* listHead)->next;
        free(lastNode);
    }
    
    if (NULL == (* listHead)->next && NULL != (* listHead)) {
        free(* listHead);
        (* listHead) = NULL;
    }
   
    printf("清空链表\n");
}

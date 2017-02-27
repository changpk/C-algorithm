//
//  SeqList.c
//  C语言算法
//
//  Created by pengkai on 2017/2/21.
//  Copyright © 2017年 changpengkai. All rights reserved.
//

#include "SeqList.h"
#include <stdlib.h>
#include <stdio.h>

bool initLinelist(SeqList * seqList) {
    
    seqList = (SeqList *)malloc(sizeof(SeqList));
    seqList->length = 0;
    printf("初始化线性表成功\n");
    return true;
}

void initLineListWithMalloc(SeqList ** seqList) {
    
    *seqList = (SeqList *)malloc(sizeof(SeqList));
    (*seqList)->length = 0;
}

void deallocLinelist(SeqList ** seqList) {
    free(*seqList);
    *seqList = NULL;
}

ElementType getElement(SeqList seqList, int index) {
    
    if (index < 0 || index > seqList.length) {
        return 0;
    }else{
        return seqList.element[index];
    }
}

bool insertElement(SeqList *seqList, int index, ElementType element) {
    
    int actualIndex = index - 1;
    if (actualIndex < 0 || actualIndex > seqList->length) {
        printf("插入位置不合法\n");
        return false;
    }else if (actualIndex > MAXSIZE + 1) {
        printf("线性表数据已满\n");
        return false;
    }else{
      
        // 空线性表
        if (seqList->length == 0) {
            seqList->element[0] = element;
        }else {
            // 把index - 1之后的元素右移
            for (int j = seqList->length - 1; j >= actualIndex; j --) {
                seqList->element[j+1] = seqList->element[j];
            }
            // 把空出的index - 1的元素赋值
            seqList->element[actualIndex] = element;
        }
        
        seqList->length ++;
        
        listAllElement(*seqList);
        return true;
    }
}

bool deleteElement(SeqList *seqList, int index) {
    
    int actualIndex = index - 1;

    if (actualIndex < 0 || actualIndex > seqList->length - 1) {
        return false;
    }else {
        for (int j = actualIndex; j <= seqList->length-2; j ++) {
            seqList->element[j] = seqList->element[j+1];
        }
        seqList->length --;
        printf("删除后的结果是:");
        listAllElement(*seqList);
        return true;
    
    }
}

bool updateElement(SeqList *seqList, int index, ElementType element) {
    int actualIndex = index - 1;
    if (actualIndex < 0 || actualIndex > seqList->length - 1) {
        return false;
    }else{
        seqList->element[actualIndex] = element;
        listAllElement(*seqList);
        return true;
    }
}

void listAllElement(SeqList seqList) {
    
    for (int i = 0; i <= seqList.length - 1; i ++) {
        printf("[%d]=%d ",i,seqList.element[i]);
    }
    printf("线性表长度是%d\n",seqList.length);
}

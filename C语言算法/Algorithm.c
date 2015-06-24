//
//  Algorithm.c
//  C语言算法
//
//  Created by changpengkai on 15/6/24.
//  Copyright (c) 2015年 changpengkai. All rights reserved.
//

#include "Algorithm.h"

// 交换排序，保证*a1<*a2
void swap (int *a1, int *a2) {
    
    int temp = *a1;
    if (*a1 > * a2) {
        *a1 = *a2;
        *a2 = temp;
    }
}

// 遍历每个数组的元素
void showArryElement (int arr[],int length) {
    
    for ( int i = 0; i < length; i ++) {
        printf(" 第 %d 的元素是 %d\n",i ,arr[i]);
    }
}

// 二分法 场景：数组，有序
int binarySearch (int arr[],int keyNum,int low,int high) {
    
    int mid = (low + high) * 0.5;
    
    if (low > high) {
        printf("数组中不存在寻找的数字: %d ",keyNum);
        return -1;
    }
    
    // 直接找到
    if (keyNum == arr[mid]) {
        printf("寻找数字：%d 在数组中的位置是 %d",keyNum,mid);
        return mid;
    }else if (keyNum > arr[mid]) {
        
        // keyNum较大落在后半区间
        return binarySearch(arr, keyNum, mid + 1, high);
        
    }else if (keyNum < arr[mid]) {
        
        // keyNum较小落在前半区间
        return binarySearch(arr, keyNum, low, mid - 1);
        
    }
    
    return -1;
}

// 冒泡排序：两两比较，每次把最大的放到最下面

void bubblingSort (int arr[],int length) {
    
    printf(" 冒泡排序开始\n");
    for (int i = 0; i < length; i ++) {
        
        for (int j = i; j < length; j ++) {
            
            swap(&arr[j], &arr[j + 1]);
        }
    }
    
    showArryElement(arr, length);
}

// 选择排序：第一个元素和其它所有元素比较，保持第一个元素为最小的；依次进行，左边始终是最小的元素

void chooseSort (int arr[], int length) {
    
    printf(" 选择排序开始\n");
    
    for (int i = 0; i < length; i ++) {
        
        for (int j = i + 1; j < length; j ++) {
            
            swap(&arr[i], &arr[j]);
        }
        
    }
    
    showArryElement(arr, length);
}

// 插入排序：第一个元素为一个有序数列

void insertSort (int arr[], int length) {
    
    
}

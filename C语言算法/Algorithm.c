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

// 插入排序：第一个元素为一个有序数列（1.a0为一个有序序列，a[1,...n-1]为无序序列；2.把第i个元素插入a[0,1,...i -1],的到有序序列a[0,1,......i];3.进行循环，直到i = n-1 为止）

void insertSort (int arr[], int length) {
    
    printf(" 插入排序开始\n");
    for (int i = 0; i < length; i ++) {
        
        // 第二个循环元素的索引和第一个的关系（这个可类似于一个冒泡排序，交换相邻元素。难点是找索引的关系）
        for (int j = i - 1; j >= 0; j --) {
            
            // 相邻排序的元素
            swap(&arr[j], &arr[j+1]);
            /*
             int temp = arr[j+1];
             arr[j+1] = arr[j];
             arr[j] = temp;
             */
        }
    }
    
      showArryElement(arr, length);
}

// 快速排序采用的是分治的思想，找到一个基准（pivot），保证左边序列的数字必须小于等于pivot，右边序列的数字必须大于pivot。对左右两边的数列进行递归操作

void quickSort (int a[], int left, int right) {
    
    printf("快速排序开始\n");
    
    // 结束的标志
    if (left >= right) return;
    
    // i 从左边扫描，j从右边扫描
    int i , j,baseNum;
    
    baseNum = a[left];
    i = left;
    j = right;
    
    
    // {100,2,49,34,8,65,9,19,76,34}
    // i 和 j相等的时候，则找到了pivot
    while (i != j) {
        
        // 如果右边的元素大于基数，继续向左扫描
        while (a[j] >= baseNum && i < j) {
            printf("1**\n");
            j --;
        }
        
        // 如果左边的元素小于基数，继续向右扫描
        while (a[i] <= baseNum && i < j) {
            printf("2**\n");

            i ++;
        }
        
        int temp;
        // 需要交换a[i]和a[j]
        if (i < j) {
            
            printf("3??\n");

            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    
    // 把基数放到合适的位置
    a[left] = a[i];
    a[i] = baseNum;
    
    // 递归处理右边序列
    quickSort(a, i + 1, right);
    
    // 递归处理左边序列
    quickSort(a, left, i - 1);
    
    showArryElement(a, right + 1);
    
}



//
//  Algorithm.c
//  C语言算法
//
//  Created by changpengkai on 15/6/24.
//  Copyright (c) 2015年 changpengkai. All rights reserved.
//

#include "Algorithm.h"

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
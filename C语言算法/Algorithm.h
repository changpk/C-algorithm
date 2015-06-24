//
//  Algorithm.h
//  C语言算法
//
//  Created by changpengkai on 15/6/24.
//  Copyright (c) 2015年 changpengkai. All rights reserved.
//

#ifndef __C______Algorithm__
#define __C______Algorithm__

#include <stdio.h>

// 二分法 场景：数组，有序
int binarySearch (int arr[],int keyNum,int low,int high);

// 冒泡排序：两两比较，每次把最大的放到最下面
void bubblingSort (int arr[],int length);

// 选择排序：第一个元素和其它所有元素比较，保持第一个元素为最小的；依次进行，左边始终是最小的元素
void chooseSort (int arr[], int length);
#endif /* defined(__C______Algorithm__) */

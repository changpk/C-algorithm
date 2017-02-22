//
//  main.c
//  C语言算法
//
//  Created by changpengkai on 15/6/24.
//  Copyright (c) 2015年 changpengkai. All rights reserved.
//

#include <stdio.h>
#include "Algorithm.h"
#include "LinkList.h"


int main(int argc, const char * argv[]) {

    LinkList l = initLinkList();
    for (int i = 0; i < 4; i ++) {
        tailAssignLinkList(l, i );
    }
    listLinkList(l);
    
    return 0;
}









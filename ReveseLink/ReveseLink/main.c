//
//  main.c
//  ReveseLink
//
//  Created by iOS on 2019/8/14.
//  Copyright © 2019 iOS. All rights reserved.
//

#include <stdio.h>
struct Link * construtLink(int *arr, int size);
struct Link * reverseLink(struct Link *header);
#define stopFlag 100

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {2, 3, 4, 5};
    struct Link *h = construtLink(a, 4);
    struct Link *reverse = reverseLink(h);
    return 0;
}

struct Link {
    struct Link *next;
    int value;
};
struct Link * construtLink(int *arr, int size) {
    struct Link *pre = NULL;
    struct Link *current = NULL;
    for (int i = 0; i < size; i++) {
        current = calloc(1, sizeof(struct Link *));
        current->value = arr[size - i - 1];
        current->next = pre;
        pre = current;
    }
    
    return current;
}

struct Link * reverseLink(struct Link *header) {
    
    struct Link *current = header;
    
    struct Link *next;
    
    struct Link *pre = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    
    
    
    return pre;
    
}



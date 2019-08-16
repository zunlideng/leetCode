//
//  main.c
//  LongestPath
//
//  Created by iOS on 2019/8/15.
//  Copyright © 2019 iOS. All rights reserved.
//

#include <stdio.h>
struct TreeNode {
    struct TreeNode *left;
    struct TreeNode *right;
    int val;
};
int maxOfInt(int a, int b);
int hight(struct TreeNode *root);
void testNode(struct TreeNode *root, int * stop, void **des);


int main(int argc, const char * argv[]) {
    
    struct TreeNode *tree = calloc(1, sizeof(calloc(1, sizeof(struct TreeNode *))));
    tree->val = 2;
    
    struct TreeNode *left = calloc(1, sizeof(calloc(1, sizeof(struct TreeNode *))));
    left->val = 45;
    tree->left = left;
   // 0x000000010051c050
    
    struct TreeNode *left1 = calloc(1, sizeof(calloc(1, sizeof(struct TreeNode *))));
    left1->val = 90;
    left->left = left1;
    
    //栈 0x00007ffeefbff540
    //堆 0x000000010070a250
    struct TreeNode *right = calloc(1, sizeof(calloc(1, sizeof(struct TreeNode *))));
    right->val = 72;
    tree->right = right;
   
 //   &d 0x00007ffeefbff538
    void *d;
    int a = 0;
    testNode(tree, &a, &d);
    
    printf("%p", d);
    return 0;
}

void testNode(struct TreeNode *root, int * stop, void **des) {
    
    if (root == NULL) {
        return;
    }
//    if (*stop == 1) {
//        return;
//    }
    printf("%d\n", root->val);
    if (root->val == 45) {
        *des = root;
        return;
    }
    testNode(root->left, stop, des);
    testNode(root->right,stop, des);
//    if (root->left->val == 45) {
//        *stop = 1;
//        //right write
//        *des = root->left;
//        testNode(root->left, stop, des);
//        //error write
//        //void *d = roo->left; d is at function stack is release when out the function
//        //testNode(root->left, stop, &d);
//    } else {
//        testNode(root->left, stop, des);
//        testNode(root->right,stop, des);
//    }
    
    
   
}

int longestPath(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    int a = maxOfInt(longestPath(root->left), longestPath(root->right));
    
    
    
    return maxOfInt(a, hight(root));
    
    
    
}
//求树的高度
int hight(struct TreeNode *root) {
    
    if (root == NULL) {
        return 0;
    }
    
    return maxOfInt(hight(root->right), hight(root->left)) + 1;
    
}
int maxOfInt(int a, int b) {
    if (a > b) {
        b = a;
    }
    return b;
}

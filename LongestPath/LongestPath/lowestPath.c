//
//  lowestPath.c
//  LongestPath
//
//  Created by iOS on 2019/8/15.
//  Copyright © 2019 iOS. All rights reserved.
//
/*
#include "lowestPath.h"
struct TreeNode {
    struct TreeNode *left;
    struct TreeNode *right;
    int val;
};

struct TreeNode * lowestPath(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) {
    
    
    int a = 0;
    struct TreeNode *des;
    numOfDesNode(root, p, q, &a, &des);

    return des;
}


int numOfDesNode(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q, int *stop, struct TreeNode **des) {
    if (root == NULL) {
        return 0;
    }
    if (*stop == 1) {
        return 0;
    }
    
    int left = numOfDesNode(root->left, p, q, stop, des);
    int right = numOfDesNode(root->right, p, q, stop, des);
    
    if (left + right == 2) {
        printf("node:%d", root->val);
        int a = 1;
        numOfDesNode(root, p, q, &a, &root);
    }
    
    return left + right + (root == p || root == q);
    
    
}
*/

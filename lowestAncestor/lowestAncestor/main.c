//
//  main.c
//  lowestAncestor
//
//  Created by iOS on 2019/8/16.
//  Copyright © 2019 iOS. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    return 0;
}


struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
    struct TreeNode *des;
    numOfDes(root, p, q, &des);
    
    return des;
    
}

int numOfDes(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q, struct TreeNode **des) {
    
    if (root == NULL) {
        return 0;
    }
    if (*des != NULL) {
        return 0;
    }
    int l = numOfDes(root->left, p, q, des);
    int r = numOfDes(root->right, p, q, des);
    int a = 0;
    if (root == q || root == p) {
        a = 1;
    }
    if (l + r + a == 2) {
        if (*des == NULL) {
            *des = root;
        }
    }
    
    return l + r + a;
    
    
    
    
}

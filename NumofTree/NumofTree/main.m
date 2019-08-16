//
//  main.m
//  NumofTree
//
//  Created by iOS on 2019/7/31.
//  Copyright © 2019 iOS. All rights reserved.
//

#import <Foundation/Foundation.h>




int main(int argc, const char * argv[]) {
    
    
    
    
    
    return 0;
}
int countNodes(struct TreeNode *root) {
    
    if (root == NULL) {
        return 0;
    }
    int res = 1;
    struct TreeNode* node = root;
    int heigh = 0;
    
    while (node->right == NULL) {
        node = node->right;
        heigh++;
    }
    
    if (root != NULL) {
        
        
        
        
//        res += numofTree(root->left);
//        res += numofTree(root->right);
    }
    
    return  res;
}

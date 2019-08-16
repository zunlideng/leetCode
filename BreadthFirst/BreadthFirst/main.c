//
//  main.c
//  BreadthFirst
//
//  Created by iOS on 2019/8/13.
//  Copyright © 2019 iOS. All rights reserved.
//

#include <stdio.h>

struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct Stack {
    
};

int main(int argc, const char * argv[]) {
    
    
    return 0;
}
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1 == NULL) {
        return t2;
    }
    if (t2 == NULL) {
        return t1;
    }
    
    struct TreeNode *newT = calloc(1, sizeof(struct TreeNode *));
    newT->value = t1->value + t2->value;
    
    newT->left = mergeTrees(t1->left, t2->left);
    newT->right = mergeTrees(t1->right, t2->right);
    
    
    return newT;
    
}


void iterAction(struct TreeNode *node) {
    struct Stack *s;
    struct TreeNode *currentNode;
    while (currentNode != NULL /*|| 　!(s->isempty())*/) {
        
        while (currentNode != NULL) {
            //s->push(currentNode)
            currentNode = currentNode->left;
        }
       

//        currentNode = s.pop();
        //中序 printf("currentNode %d", currentNode->value);
        currentNode = currentNode->right;
        //后续遍历
    }
}
/* 广度优先
void breadthFirstSearch(Tree root){
    queue<Node *> nodeQueue;  //使用C++的STL标准模板库
    nodeQueue.push(root);
    Node *node;
    while(!nodeQueue.empty()){
        node = nodeQueue.front();
        nodeQueue.pop();
        cout<<node->data;//遍历根结点
        if(node->lchild){
            nodeQueue.push(node->lchild);  //先将左子树入队
        }
        if(node->rchild){
            nodeQueue.push(node->rchild);  //再将右子树入队
        }
    }
}

*/

//
//  Iterative.swift
//  LongestSubString
//
//  Created by iOS on 2019/8/13.
//  Copyright © 2019 iOS. All rights reserved.
//

import Foundation
struct Stack {
    
    
    func push(node: TreeNode)  {
        
    }
    
    
    func pop() -> TreeNode {
        return TreeNode()
    }
    func isEmpty() -> Bool {
        return false
    }
    
}
class TreeNode {
    var value: Int = 0
    var left: TreeNode?
    var right: TreeNode?
    
    
    //迭代法DFS 深度优先后序遍历
    func iterativeSuf(root: TreeNode?) {
        let stack = Stack()
       
        
        stack.push(node: root!)
        while !stack.isEmpty() {
            var currentNode: TreeNode = stack.pop()
            print(currentNode.value)
            if currentNode.right != nil {
                stack.push(node: currentNode.right!)
            }
            
            if currentNode.left != nil {
                stack.push(node: currentNode.left!)
            }
            
        }
        
        
    }
    
    
    //迭代法DFS 深度优先中序遍历
    func iterative(root: TreeNode?) {
        let stack: Stack = Stack()
        
        var curr = root
        while curr != nil || !stack.isEmpty() {
            while curr != nil {
                stack.push(node: curr!)
                curr = curr?.left
            }
            curr = stack.pop()
            print(curr?.value ?? "")
            curr = curr?.right
        }
        
        
    }
    //迭代法DFS 深度优先前序遍历
    func iterativePre(root: TreeNode?) {
        let stack = Stack()
        
        
        stack.push(node: root!)
        while !stack.isEmpty() {
            var currentNode: TreeNode = stack.pop()
            print(currentNode.value)
            if currentNode.right != nil {
                stack.push(node: currentNode.left!)
            }
            
            if currentNode.left != nil {
                stack.push(node: currentNode.right!)
            }
            
        }
        
        
    }
    
    
    
}




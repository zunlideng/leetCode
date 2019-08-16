//
//  ViewController.swift
//  TreeInsert
//
//  Created by iOS on 2019/8/9.
//  Copyright © 2019 iOS. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
    }


}

public class TreeNode {
  public var val: Int
  public var left: TreeNode?
  public var right: TreeNode?
  public init(_ val: Int) {
      self.val = val
      self.left = nil
      self.right = nil
  }
}

class Solution {
    // is error
    func generateTrees(_ n: Int) -> [TreeNode?] {
        
        var treeNode : [TreeNode?] = [];
        let tree = TreeNode(1);
        treeNode.append(tree);
        
        for i in 2...n {
            treeNode = insertN(i, arr: treeNode);
        }
        return treeNode;
    }
    
    func insertN(_ n: Int, arr: [TreeNode?]) -> [TreeNode?] {
        
        var treeNodes : [TreeNode?] = []
       
        
        for t in arr {
            
            let root = deepCopy(originTree: t);
            
            var tmp = root?.right
            if tmp == nil {
                treeNodes.append(root)
            }
                
             while(tmp != nil) {
                tmp = tmp?.right
                if tmp == nil {
                    let new = TreeNode(n)
                    tmp?.right = new
                }
                treeNodes.append(root)
            }
           
           
        }
        
        
        return treeNodes
    }
    
    func deepCopy(originTree: TreeNode?) -> TreeNode? {
        
        if originTree == nil {
            return nil;
        }
        
        let tree = TreeNode(originTree!.val);
        tree.left = deepCopy(originTree: originTree!.left)
        tree.right = deepCopy(originTree: originTree!.right);
        
        return tree;
        
    }
}

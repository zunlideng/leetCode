//
//  File.swift
//  InsertSort
//
//  Created by iOS on 2019/7/10.
//  Copyright © 2019 iOS. All rights reserved.
//

import Foundation

class Queue {
    var s1: Stack!
    var s2: Stack!
    
    func out() -> Any {
        
        if s1.isEmpty() {
            let s = s1
            s1 = s2
            s2 = s
        }
        var lastObj = s1.pop()
        s2.push(lastObj)
        while s1.isEmpty() {
            lastObj = s1.pop()
            s2?.push(lastObj)
        }
        
       return lastObj
        
        
    }
    func insert(_ obj: Any) {
        if s1.isEmpty() {
            let s = s1
            s1 = s2
            s2 = s
        }
        s1.push(obj)
    }
}
class Stack {
    
    func isEmpty() -> Bool {
        return true
    }
    func pop() -> Any  {
        return ""
    }
    func push(_ obj:Any) {
        
    }
}

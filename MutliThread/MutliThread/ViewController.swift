//
//  ViewController.swift
//  MutliThread
//
//  Created by iOS on 2019/7/16.
//  Copyright © 2019 iOS. All rights reserved.
//

import Cocoa
//依赖 单个block优先级 单个kvo键值对观察
class ViewController: NSViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        operationFunc()
        // Do any additional setup after loading the view.
    }

    override var representedObject: Any? {
        didSet {
        // Update the view, if already loaded.
        }
    }
    private func operationFunc() {
        let queue = OperationQueue.init()
        for i in 0...3 {
            let op = BlockOperation.init {
                self.doSomething()
                
            }
            queue.addOperation(op)
        }
        DispatchQueue.main.asyncAfter(deadline: DispatchTime.now() + 3) {
            
            queue.isSuspended = true//无法暂停
            let op = BlockOperation.init {
                self.doSomething()
                
            }
            queue.addOperation(op)
            
            queue.isSuspended = false
            
        }
        
        
    }
    
    
    
    
    
    private func threadFunc() {
        
        let thread = Thread.init(target: self, selector: #selector(doSomething), object: nil)
        
        thread.stackSize = 1024 * 4 * 2
        
        thread.start()
        
        
        DispatchQueue.main.asyncAfter(deadline: DispatchTime.now() + 3) {
            print("cancel thread")
            self.perform(#selector(self.exitThread), on: thread, with: nil, waitUntilDone: false)
            //thread.cancel()//只改变状态 并不能停止当前线程
        }
    }
    @objc private func exitThread() {
        print(Thread.current)
        Thread.exit()
    }
    @objc private func doSomething() {
        
        print("start task")
        sleep(5)
        print("end stask")
//        Thread.sleep(forTimeInterval: 3) //阻塞当前线程
       // Thread.exit()//退出当前线程，自己回收资源，不建议使用
        //
    }
    
    
}


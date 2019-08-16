//
//  main.cpp
//  InsertSort
//
//  Created by iOS on 2019/7/9.
//  Copyright © 2019 iOS. All rights reserved.
//

#include <iostream>

void insertSort(int *arr, int count);
void quickSort(int *arr, int count);
void printArr(int *arr, int count);
void bublySory(int *arr, int count);
void selectArr(int *arr, int count);
void MergeSort(int *sourceArr, int *tempArr, int startIndex, int endIndex);

class Queue {
    
    void in();
    void out();
};
class Stack {
    void pop();
    void push();
};

class Solution {
    public boolean isValidBST(TreeNode root) {
        Stack<TreeNode> stack = new Stack();
        double inorder = - Double.MAX_VALUE;
        
        while (!stack.isEmpty() || root != null) {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }
            root = stack.pop();
            // If next element in inorder traversal
            // is smaller than the previous one
            // that's not BST.
            if (root.val <= inorder) return false;
            inorder = root.val;
            root = root.right;
        }
        return true;
    }
}


int main(int argc, const char * argv[]) {
    
    
    int arr[] = {7, 4, 5, 9, 2, 6};
    
    
    
    //归并
    //堆排序
    //动态规划
    
    int *tempArr = (int *)calloc(6, sizeof(int));
    
    for (int i = 0; i < 6; i++) {
        tempArr[i] = i;
    }
//    MergeSort(arr, tempArr, 0, 5);
    
    //osspin
    /*s
    bool isLock = true
     
     while(isLock) {
     
         lock()
        // crtic section
         unlock()
     
        isLock = false
     }
     
    
     
     IPC inter-process-communication
     
     process 拥有自己的 memoryAddress
     
    */
    
    //P_thread_mute
    //
    printArr(arr, 6);
    return 0;
}
void swap(int *a, int *b) {
    
    int c = *a;
    *a = *b;
    *b = c;
}
void printArr(int *arr, int count) {
    for (int i = 0; i < count; i++) {
        std::cout << arr[i];
    }
    std::cout << "\n";
}
void bublySory(int *arr, int count) {
    for (int i = 0; i < count; i ++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
void selectArr(int *arr, int count) {
    for (int i = 0; i < count; i++) {
        int index = i;
        for (int j = i+1; j < count; j++) {
            if (arr[j] < arr[index]) {
                index = j;
            }
        }
        if (index != i) {
            swap(&arr[index], &arr[i]);
        }
    }
}
void sort(int *arr, int count) {
    
    if (count <= 0) {
        return;
    }
    
    for (int i = 0; i < count; i ++) {
        for (int j = i + 1; j > 0; j--) {
            if (arr[j] < arr[j-1]) {
                swap(&arr[j], &arr[j-1]);
            } else {
                break;
            }
        }
    }
    
    
    
}
//
void insertSort(int *arr, int count) {
    if (count <= 1) {
        return ;
    }
    
    for (int i = 0; i < count; i++) {
        printArr(arr, count);
        int index = i + 1;
        while (index >= 0) {
            if (arr[index] < arr[index - 1]) {
                swap(&arr[index], &arr[index - 1]);
                index--;
            } else {
                break;
            }
        }
        printArr(arr, count);
    }
    
    
    
    
}
void quickCore(int *arr, int start, int end, int count) {
    
    if (start < 0 || start > end || end > count - 1) {
        return ;
    }
    int left = start;
    int right = end;
    int key = arr[left];
    
    while (left < right) {
        
        while (left < right && arr[right] > key) {
            right--;
        }
        arr[left] = arr[right];
        
        while (left < right && arr[left] < key) {
            left++;
        }
        
        arr[right] = arr[left];
        
    }
    arr[left] = key;
    quickCore(arr, start, left - 1, count);
    quickCore(arr, left + 1, end, count);
    
}

void quickSort(int *arr, int count) {
    
    quickCore(arr, 0, count - 1, count);
}

void sortAd(int *arr, int start, int end) {
    if (start >= end) {
        return;
    }
    
    int left = start;
    int right = end;
    int key = arr[start];
    while (left < right) {
        
        while (left < right && key < arr[right]) {
            right--;
        }
        arr[left] = arr[right];
        
        while (left < right && key > arr[left]) {
            left++;
        }
        
        arr[right] = arr[left];
        
    }
    
    arr[left] = key;
    sortAd(arr, start, left - 1);
    sortAd(arr, left + 1, end);
    
    
    
    
}


void Merge(int *sourceArr,int *tempArr, int startIndex, int midIndex, int endIndex)
{
    int i = startIndex, j=midIndex+1, k = startIndex;
    while(i!=midIndex+1 && j!=endIndex+1)
    {
        if(sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    while(i != midIndex+1)
        tempArr[k++] = sourceArr[i++];
    while(j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex; i<=endIndex; i++)
        sourceArr[i] = tempArr[i];
}

//内部使用递归
void MergeSort(int *sourceArr, int *tempArr, int startIndex, int endIndex)
{
    int midIndex;
    //NlgN N N*N
    if(startIndex < endIndex)
    {
        midIndex = startIndex + (endIndex-startIndex) / 2;//避免溢出int
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}



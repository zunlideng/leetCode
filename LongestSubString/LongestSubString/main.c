//
//  main.c
//  LongestSubString
//
//  Created by iOS on 2019/7/15.
//  Copyright © 2019 iOS. All rights reserved.
//

#include <stdio.h>

int longestSubString(char *str, int count);
char* longestCommomSubstring(char *str1, char *str2, int count1, int count2);
struct TreeNode* bstFromPreorder(int* preorder, int preorderSize);
    

int main(int argc, const char * argv[]) {
    
    int a[] = {8,5,1,7,10,12};
    struct TreeNode* tree = bstFromPreorder(a, 6);
    char *s = "desedasav";
    char *t = "vasadesed";
    
    char *s2 = longestCommomSubstring(s, t, 7, 7);
    
    
    return 0;
}
int maxInt(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}
//分而治之
int longestSubString(char *str, int count) {
    //arr[i] 表示的是 以 i为结尾indx的正确字串最长长度
    //故 arr[i] = arr[i] + 2|0 + arr[i-1-a[i-1]-1]
    int *arr = (int *)(calloc(count, sizeof(int)));
    int max = 0;
    arr[0] = 0;
    for (int i = 1; i < count; i++) {
        //can't find the start of invalble subString index
        if (str[i] == ')') {
            if (str[i - 1] == '(') {
               
                arr[i] = (i >= 2 ? arr[i - 2] : 0) + 2;
                
            } else if ((i - arr[i - 1]  > 0) && str[i - arr[i - 1] - 1] == '(') {
                
                
//                arr[i] = arr[i - 1]  + 2;
                arr[i] = arr[i - 1] + ((i - arr[i - 1]) > 0 ? arr[i - arr[i - 1] - 2] : 0) + 2;
                
            }
            
            max = maxInt(max, arr[i]);
        }
        
        printf("%d\n", arr[i]);
        
    }
    
    
    
    return -1;
    
   
    
}

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* coreBstFromPreorder(int* preorder, int preorderSize, int* index, int min, int max) {
    int a = *index;
    if (a >= preorderSize) {
        return NULL;
    }
    
    
    if (min != NULL && min > *(preorder + a)) {
        return NULL;
    }
    if (max != NULL && max < *(preorder + a)) {
        return NULL;
    }
    
    int value = *(preorder + a);
    *index = (++a);
    struct TreeNode *tree = calloc(1, sizeof(struct TreeNode *));
    tree->val = value;
    tree->left = coreBstFromPreorder(preorder, preorderSize, index, min, value);
    tree->right = coreBstFromPreorder(preorder, preorderSize, index, value, max);

    return tree;
    
}


struct TreeNode* bstFromPreorder(int* preorder, int preorderSize) {
    int index = 0;
    return coreBstFromPreorder(preorder, preorderSize, &index, NULL, NULL);
}




//public String longestPalindrome(String s) {
//    if (s == null || s.length() < 1) return "";
//    int start = 0, end = 0;
//    for (int i = 0; i < s.length(); i++) {
//        int len1 = expandAroundCenter(s, i, i);
//        int len2 = expandAroundCenter(s, i, i + 1);
//        int len = Math.max(len1, len2);
//        if (len > end - start) {
//            start = i - (len - 1) / 2;
//            end = i + len / 2;
//        }
//    }
//    return s.substring(start, end + 1);
//}
//
//private int expandAroundCenter(String s, int left, int right) {
//    int L = left, R = right;
//    while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
//        L--;
//        R++;
//    }
//    return R - L - 1;
//}


char* longestRevseString(char *s, int start, int end, int count) {
    int left, right;
    int arr[count];
    for (int i = 0; i < count; i++) {
        
        
    }
    
    
    return "";
}

int longestString(char *s, int count) {
    
    int max = 0;
    int *arr = calloc(count, sizeof(int));
    for (int i = 0; i < count; i++) {
        if (s[i] == ')') {
            if (i - 1 >= 0 && s[i - 1] == '(') {
                arr[i] = (i >= 2) ? arr[i - 2] : 0 + 2;
            } else if (i - arr[i - 1] - 1 >= 0 && s[i - 1 - arr[i - 1]] == '(') {
                arr[i] = arr[i - 1] + ((i - 2 - arr[i - 1] >= 0) ? arr[i - 2 - arr[i - 1]] : 0) + 2;
            }
            if (arr[i] > max) {
                max = arr[i];
            }
        }
    }
    
    
    return max;
}
//动态规划
char* longestCommomSubstring(char *str1, char *str2, int count1, int count2) {
    int vect[count1][count2];
    int longest = 0;
    int end = 0;
    for (int i = 0; i < count1; i++) {
        
        for (int j = 0; j < count2; j++) {
            if (str1[i] == str2[j]) {
                if (i == 0 || j == 0) {
                    vect[i][j] = 0;
                } else {
                    vect[i][j] = vect[i-1][j-1] + 1;
                }
                
                if (vect[i][j] > longest) {
                    longest = vect[i][j];
                    end = i;
                }
            } else {
                vect[i][j] = 0;
            }
            
            
            
            
        }
        
        
        
    }
    
//    int start = 0, end = 0, longest = 0;
//    for (int i = 0; i < count1; i++) {
//
//        for (int j = 0; j < count1; j++) {
//
//            if (str1[i] == str2[j]) {
//
//                int k = i;
//                int n = j;
//                while (str1[++k] == str2[++n]) {
//                }
//                if ((k - i) > longest) {
//                    longest = k - i;
//                    start = i;
//                    end = k;
//                }
//            }
//
//
//        }
//    }
    //2 4 [4-2+1, 4+1)
    
    char res[longest];
    for (int i = 0; i < end; i++) {
        res[i] = str1[end - longest + i + 1];
    }

    return  res;
}

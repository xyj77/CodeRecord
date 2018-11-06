# -*- coding: utf-8 -*-
"""
Created on Sun Sep 09 14:57:16 2018

@author: xyj
"""
'''
对于仅由小写字母组成的字符串A和字符串B，如果存在一个字母映射方式将a-z依次映射为另一个序列
如果存在一个映射将A映射成B，则A和B相似，例如abcc和xyaa对应的映射是：{a->x, b->y, c->a, ...}

现给仅由小写字母组成的字符串S，T
求S中有多少子串和T相似

示例：
input:ababcb
xyx
output:3


思路：KMP算法，但并不是寻找子串，而是寻找相似序列。
'''
import sys
def KMP(S):
    m = len(S)
    N = [0 for i in range(m)]
    for i in range(1,m):
        k = N[i-1]
        while(k>0 and S[i]!=S[k]):
            k = N[k-1]
        if(S[i]==S[k]):
            N[i]=k+1
        else:
            N[i]=0
    return N
    
    
if __name__ == '__main__':
    S = sys.stdin.readline().strip()
    T = sys.stdin.readline().strip()
    len1 = len(S)
    len2 = len(T)
    TN = KMP(T)
    count = 0
    if(len1<len2):
        print(0)
        sys.exit()
    for i in range(len1):
        tmp = S[i:i+len2]
        tmpN = KMP(tmp)
        if(len(tmp)<len2):
            break
        elif(tmpN==TN):
            count+=1
    print(count)
   
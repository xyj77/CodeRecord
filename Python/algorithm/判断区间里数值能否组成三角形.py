# -*- coding: utf-8 -*-
"""
Created on Thu Oct 18 20:25:39 2018
判断数组中任意区间里的数值是否能组成三角形

@author: xyj
"""

def solve(edges):
    if(len(edges) < 3):
        return 0
    edges.sort()
    for i in range(len(edges)-2):
        if(edges[i] > 0 and edges[i] > edges[i+2] - edges[i+1]):
            return 1 
    return 0
    
N = int(raw_input())
edges = [int(x) for x in raw_input().strip().split(' ')]
M = int(raw_input())
res = 0
for i in range(M):
    l, r = [int(x) for x in raw_input().strip().split(' ')]
    if(l>r):
        continue
    res = res + solve(edges[l-1:r])
print(res)

# -*- coding: utf-8 -*-
"""
Created on Mon Sep 10 20:18:22 2018

@author: xyj

爬楼梯：
N阶台阶，每次可以爬1，2，4，8，····级台阶
求有多少种爬台阶方法。

"""

def solve():
    N = int(input())
    dp = [0 for i in range(N + 1)]
    dp[0] = 1
    dp[1] = 1
    for i in range(2, N + 1):
        count = 0
        count_i = 0
        while 2 ** count_i <= i + 1:
            count += dp[i - 2 ** count_i]
            count_i += 1
        dp[i] += count
    print(dp[-1])
    
if __name__ == '__main__':
    M = int(raw_input())
    for _ in range(M):
        solve()
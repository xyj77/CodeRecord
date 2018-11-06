# -*- coding: utf-8 -*-
"""
Created on Mon Sep 10 20:46:50 2018

@author: xyj

小数除法：
a/b
如果结果是整数，则不需要小数点
如果是有限小数则直接输出
如果是无限循环小数则要把循环部分用括号括起来

"""

a, b = list(map(int, raw_input().split(' ')))
Z = a // b
a = a % b
if a == 0:
    print(Z)
    exit()
re = '%d.' % Z
while True:
    old_a = a
    a *= 10
    re += str(a // b)
    a = a % b
    if old_a == a or a == 0:
        if not a == 0:
            re = re[:-1] + '(' + re[-1:]
            re += ')'
        print(re)
        break
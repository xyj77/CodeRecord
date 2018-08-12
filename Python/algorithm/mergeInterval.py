# -*- coding: utf-8 -*-
"""
合并区间问题：
输入：
3
1,10;32,45
78,94;5,16
80,100;200,220;16,32

输出：
1,45;78,100;200,220


Created on Sun Aug 12 09:58:08 2018
"""

from __future__ import absolute_import
from __future__ import print_function

class Part(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end

class Solution(object):
    
    def merge(self, intervals):
        out = []
        for i in sorted(intervals, key=lambda i: i.start):
            if out and i.start <= out[-1].end:
                out[-1].end = max(out[-1].end, i.end)
            else:
                out += i,
        return out
    
    '''
    def merge(self, parts):
        n = len(parts)
        if n <= 1:
            return parts
        result = []
        parts.sort(key=lambda d: d.start)
        left, right = parts[0].start, parts[0].end
        for index in range(1,n): #从第二个区间开始判断
            # 下一个区间的起始位置小于或等于当前的right值，说明可以合并
            if parts[index].start <= right:
                right = max(parts[index].end, right)
            # 下一个区间的起始位置大于当前的right值，说明应该重新生成区间
            else:
                # 实际上是以left, right为初始变量生成一个Part型的对象，并加入结果列表
                result.append(Part(left, right))
                left = parts[index].start
                right = parts[index].end
                
            index += 1

        result.append(Part(left, right))
        return result  
    '''              
        

def main():
    s = []
    n = int(raw_input())
    solver = Solution()
    for i in range(n):
        temp = [x.split(',') for x in list(raw_input().split(';'))]
        
        for pair in temp:
            s.append(Part(int(pair[0]), int(pair[1])))
            
        s = solver.merge(s)
    result = ''
    for x in s:
        result = result + str(x.start) + ',' + str(x.end) + ';'
    
    print(result[:-1])
    

if __name__ == '__main__':
    main()    
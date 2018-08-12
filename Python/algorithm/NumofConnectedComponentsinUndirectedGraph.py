# -*- coding: utf-8 -*-
"""
[LeetCode] Number of Connected Components in an Undirected Graph 无向图中的连通区域的个数

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
write a function to find the number of connected components in an undirected graph.

Example 1:

     0          3

     |          |

     1 --- 2    4

Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.


Example 2:

     0           4

     |           |

     1 --- 2 --- 3

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, 
[0, 1] is the same as [1, 0] and thus will not appear together in edges.

"""

# Method 1
# Definition for a undirected graph node
class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []

class Solution:
    # @param {UndirectedGraphNode[]} nodes a array of undirected graph node
    # @return {int[][]} a connected set of a undirected graph
    def connectedSet(self, nodes):
        # Write your code here
        self.hashMap = {}
        for node in nodes:
            self.hashMap[node.label] = False
            
        res = []
        for node in nodes:
            if not self.hashMap[node.label]:
                temp = []
                self.dfs(node, temp)
                res.append(sorted(temp))
                
        return res
        
    def dfs(self, node, temp):
        self.hashMap[node.label] = True
        temp.append(node.label)
        for neighbor in node.neighbors:
            if not self.hashMap[neighbor.label]:
                self.dfs(neighbor, temp)

if __name__=='__main__':
    nodes = []
    n = int(raw_input())
    while(n > -1): #序号输入-1结束输入
        neighbors = []
        neighbors = [int(x) for x in raw_input().split(',')]
        node = UndirectedGraphNode(n)
        node.neighbors = [UndirectedGraphNode(x) for x in neighbors]
        nodes.append(node)
        n = int(raw_input())
    
#    for i in range(len(nodes)):
#        print nodes[i].label, nodes[i].neighbors
        
    solver = Solution()
    result = solver.connectedSet(nodes)
    print len(result)
    print result
    
'''
Input:
0
1 2
1
0 2
2
1
3
4
4
3
-1

Output:
2
[[0, 1, 2], [3, 4]]
'''    
    
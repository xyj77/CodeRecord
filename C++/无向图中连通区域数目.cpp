/*
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
*/ 
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1001

using namespace std;


/*
解法一： 
这道题让求无向图中连通区域的个数，解法都有类似的特点，都是要先构建邻接链表Adjacency List
这道题的一种解法是利用DFS来做，思路是给每个节点都有个flag标记其是否被访问过，
对于一个未访问过的节点，我们将结果自增1，因为这肯定是一个新的连通区域，然后我们通过邻接链表来遍历与其相邻的节点，
并将他们都标记成已访问过，遍历完所有的连通节点后我们继续寻找下一个未访问过的节点，以此类推直至所有的节点都被访问过了，
那么此时我们也就求出来了连通区域的个数。
*/
/*
void dfs(vector<vector<int> > &g, vector<bool> &v, int i) {
    if (v[i]) return;
    v[i] = true;
    for (int j = 0; j < g[i].size(); ++j) {
        dfs(g, v, g[i][j]);
    }
}
int countComponents(int n, vector<pair<int, int> >& edges) {
    int res = 0;
    vector<vector<int> > g(n);
    vector<bool> v(n, false);
    vector<pair<int, int> >::iterator it;
    for(it = edges.begin(); it != edges.end(); it++){
        g[it->first].push_back(it->second);
        g[it->second].push_back(it->first);
    }
    for (int i = 0; i < n; ++i) {
        if (!v[i]) {
            ++res;
            dfs(g, v, i);
        }
    }
    return res;
}
*/

/*
解法二：
还有一种比较巧妙的方法，不用建立邻接链表，也不用DFS，思路是建立一个root数组，下标和节点值相同，
此时root[i]表示节点i属于group i，我们初始化了n个部分 (res = n)，假设开始的时候每个节点都属于一个单独的区间，
然后我们开始遍历所有的edge，对于一条边的两个点，他们起始时在root中的值不相同，这时候我们我们将结果减1，
表示少了一个区间，然后更新其中一个节点的root值，使两个节点的root值相同，
那么这样我们就能把连通区间的所有节点的root值都标记成相同的值，不同连通区间的root值不相同，
这样也能找出连通区间的个数。
*/ 

int find(vector<int> &root, int i) {
    while (root[i] != i) i = root[i];
    return i;
}
int countComponents(int n, vector<pair<int, int> >& edges) {
    int res = n;
    vector<int> root(n);
    for (int i = 0; i < n; ++i) root[i] = i;
    vector<pair<int, int> >::iterator it;
    for(it = edges.begin(); it != edges.end(); it++){
        int x = find(root, it->first), y = find(root, it->second);
        if (x != y) {
            --res;
            root[y] = x;
        }
    }
    return res;
}


void inputGraph(vector<pair<int, int> >& graph);
int main(){
	int n;
	cin>>n;
	// 图存储 
	vector<pair<int, int> > g;
	inputGraph(g);
	
	//方法一
	int result = countComponents(n, g);
	cout<<result<<endl;
	
	return 0;
}

void inputGraph(vector<pair<int, int> >& g){
	int start, end;
	while(cin>>start>>end){//键盘Ctrl+Z Enter结束输入 
	    pair<int, int> edge(start, end);
	    g.push_back(edge);
	}
}











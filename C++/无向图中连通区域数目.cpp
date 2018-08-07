/*
[LeetCode] Number of Connected Components in an Undirected Graph ����ͼ�е���ͨ����ĸ���

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
�ⷨһ�� 
�������������ͼ����ͨ����ĸ������ⷨ�������Ƶ��ص㣬����Ҫ�ȹ����ڽ�����Adjacency List
������һ�ֽⷨ������DFS������˼·�Ǹ�ÿ���ڵ㶼�и�flag������Ƿ񱻷��ʹ���
����һ��δ���ʹ��Ľڵ㣬���ǽ��������1����Ϊ��϶���һ���µ���ͨ����Ȼ������ͨ���ڽ������������������ڵĽڵ㣬
�������Ƕ���ǳ��ѷ��ʹ������������е���ͨ�ڵ�����Ǽ���Ѱ����һ��δ���ʹ��Ľڵ㣬�Դ�����ֱ�����еĽڵ㶼�����ʹ��ˣ�
��ô��ʱ����Ҳ�����������ͨ����ĸ�����
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
�ⷨ����
����һ�ֱȽ�����ķ��������ý����ڽ�����Ҳ����DFS��˼·�ǽ���һ��root���飬�±�ͽڵ�ֵ��ͬ��
��ʱroot[i]��ʾ�ڵ�i����group i�����ǳ�ʼ����n������ (res = n)�����迪ʼ��ʱ��ÿ���ڵ㶼����һ�����������䣬
Ȼ�����ǿ�ʼ�������е�edge������һ���ߵ������㣬������ʼʱ��root�е�ֵ����ͬ����ʱ���������ǽ������1��
��ʾ����һ�����䣬Ȼ���������һ���ڵ��rootֵ��ʹ�����ڵ��rootֵ��ͬ��
��ô�������Ǿ��ܰ���ͨ��������нڵ��rootֵ����ǳ���ͬ��ֵ����ͬ��ͨ�����rootֵ����ͬ��
����Ҳ���ҳ���ͨ����ĸ�����
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
	// ͼ�洢 
	vector<pair<int, int> > g;
	inputGraph(g);
	
	//����һ
	int result = countComponents(n, g);
	cout<<result<<endl;
	
	return 0;
}

void inputGraph(vector<pair<int, int> >& g){
	int start, end;
	while(cin>>start>>end){//����Ctrl+Z Enter�������� 
	    pair<int, int> edge(start, end);
	    g.push_back(edge);
	}
}











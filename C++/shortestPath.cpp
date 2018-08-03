/**
题目：给定一个n*m的矩阵，矩阵中元素非负，从左上角到右下角找一条路径，使得路径上元素之和最小，
每次只能向右或者向下走一个方格。
例如：
    [10  5  7  4]
	[ 9 11 12  6]
	[ 1  2  4  9]
	[15  1  1  2]
最短路径为：10->9->1->2->1->1->2 

*/
#include <vector> 
#include <iostream> 
#include <iterator> 
using namespace std;
//INT_MAX INT_MIN 是在 limits.h 中定义 
#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)
int N=4,M=4; 
vector<vector<int> > grid(N, vector<int>(M,0));
 
int minPathSum2(vector<vector<int> >& grid);//方法一 
int minPathSum3(vector<vector<int> >& grid);//方法二 
int minPathSum4(vector<vector<int> >& grid);//方法三 
int minPathSum5(vector<vector<int> >& grid);//方法四 

int main(){ 
    /*
    int temp;
	cout << "输入整数，以任意字母结束：" << endl;
    while(cin>>temp){           //如果不确定输入数字个数，可以用这种方式
		grid[0].push_back(temp);  //填充数据
	}
    ostream_iterator<int> os(cout, " "); 
    grid[0][2]=4; 
    //交换矩阵的两行 
    grid[0].swap(grid[1]); 
    for(int i=0;i<grid.size();i++){ 
        copy(grid[i].begin(), grid[i].end(), os); 
        cout<<endl; 
    } 
    */
    int a[][4] = {{10,5,7,4},{9,11,12,6},{1,2,4,9},{15,1,1,2}};
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            grid[i][j] = a[i][j];  
    ostream_iterator<int> os(cout, " ");
    for(int i=0;i<grid.size();i++){
	    copy(grid[i].begin(), grid[i].end(), os);
		cout<<endl; 
    }
    
    int result2 = minPathSum2(grid);
    cout<<result2<<endl;
    
    int result3 = minPathSum3(grid);
    cout<<result3<<endl;
    
    int result4 = minPathSum4(grid);
    cout<<result4<<endl;
    
    //int result5 = minPathSum5(grid);
    //cout<<result5<<endl;
    
    return 0; 
} 

/**
方法一(转换为图中的最短路径)：我们可以把矩阵中的每个方格当做图中的一个顶点，相邻的方格之间有一条边，
每个方格最多有两条出边，(当前方格到右侧方格有一条出边，当前方格到下侧方格有一条出边)。
我们把矩阵中的最短路径转换为图中的最短路径，使用Dijstra算法来做此题，
我们再次使用最简单的Dijstra算法，没有进行优化。图中总共有n*m个点，因为每一次都需要找到一个最小值，
找最小值得代价为o(n*m)，总共需要找o(n*m)个最小值，所以时间复杂度为o(n*n*m*m)。
*/
struct Node  
{  
    int val;  
    int row;  
    int col;  
    Node(){}  
    Node(int v, int r, int c) :val(v), row(r), col(c)  
    {}  
    friend bool operator<(const Node &lhs, const Node &rhs);  
};  
  
bool operator<(const Node &lhs, const Node &rhs)  
{  
    return lhs.val > rhs.val;  
}  
  
struct Vertex  
{  
    int dis;  
    bool visited;  
    Vertex(){}  
    Vertex(int d, bool v) :dis(d), visited(v){}  
};  
  
class Solution {  
public:  
    Node findMinVal(vector<vector<Vertex> > ve)  
    {  
        Node res = Node(INT_MAX, 0, 0);  
        for (int i = 0; i < ve.size(); ++i)  
        {  
            for (int j = 0; j < ve[0].size(); ++j)  
            {  
                if (!ve[i][j].visited && res.val > ve[i][j].dis)  
                {  
                    res.col = j;  
                    res.row = i;  
                    res.val = ve[i][j].dis;  
                }  
            }  
        }  
        return res;  
    }  
      
    int minPathSum(vector<vector<int> >& grid)  
    {  
        int sum = 0;  
        int rows = grid.size();  
        int cols = grid[0].size();  
        vector<vector<Vertex> > ve;  
        ve.resize(rows);  
        for (int i = 0; i < rows; ++i)  
        {  
            ve[i].resize(cols);  
            for (int j = 0; j < cols; ++j)  
            {  
                ve[i][j] = Vertex(INT_MAX, false);  
            }  
        }  
        ve[0][0].dis = grid[0][0];  
        while (true)  
        {  
            Node res = findMinVal(ve);  
            int row = res.row;  
            int col = res.col;  
            sum = res.val;  
            if (row == rows - 1 && col == cols - 1)  
                break;  
            ve[row][col].visited = true;  
            if (row + 1 < rows && sum + grid[row + 1][col] < ve[row + 1][col].dis)  
            {  
                ve[row + 1][col].dis = sum + grid[row + 1][col];  
            }  
            if (col + 1 < cols && sum + grid[row][col + 1] < ve[row][col + 1].dis)  
            {  
                ve[row][col + 1].dis = sum + grid[row][col + 1];  
            }  
        }  
        return sum;  
    }  
};  

/**
 方法二(动态规划)：时间复杂为o(n*m)和空间复杂度为o(n*m)。
 典型的动态规划问题，假设当前已经开始计算s[i][j]，那么s[i][j]只可能从s[i-1][j]+grid[i][j]
 或者s[i][j-1]+grid[i][j]计算得到，也就是s[i][j] = min(s[i-1][j],s[i][j-1])+grid[i][j]。
 我们需要一个o(n*m)额外空间保存已经计算的s[i][j]的值，我们只需要访问一遍数组即可。
 因此时间复杂度为o(n*m)，空间复杂度为o(n*m)。我们需要特殊处理矩阵中第一行和第一列。
 因为第一行没有s[i-1][j]元素，只有s[i][j-1]元素。第一列没有s[i][j-1]元素，只有s[i-1][j]元素。
 代码如下：
*/
int minPathSum2(vector<vector<int> >& grid)  
{  
    //当grid为空时，返回0  
    if (grid.empty())  
        return 0;  
    //获取grid的行数和列数  
    int rows = grid.size();  
    int cols = grid[0].size();  
    //额外数组data,大小和grid一样  
    vector<vector<int> > data(rows,vector<int>(cols,grid[0][0]));  
    //处理data第一列  
    for (int i = 1; i < rows; ++i)  
    {  
        data[i][0] = data[i - 1][0] + grid[i][0];  
    }  
    //处理data第一行  
    for (int i = 1; i < cols; ++i)  
    {  
        data[0][i] = data[0][i - 1] + grid[0][i];  
    }  
    //处理data非第一行和第一列的元素  
    for (int i = 1; i < rows; ++i)  
    {  
        for (int j = 1; j < cols; ++j)  
        {  
            data[i][j] = min(data[i][j - 1], data[i - 1][j]) + grid[i][j];  
        }  
    }  
    //返回最短路径值
	 
    return data[rows - 1][cols - 1];  
}

/**
 方法三(动态规划)：时间复杂度为o(n*m)，空间复杂度为o(m)，此方法需要2*m额外空间。
 当我们求s[i][j]时，s[i-2]行的元素我们就不再需要，我们只需要s[i-1]行中的元素，
 我们把s[i-1]行中的元素保存在pre数组中，数组的大小为m。我们把s[i]保存在cur数组中，
 当s[i]行的元素计算完毕以后，我们交换pre和cur数组。因为需要pre数组和cur数组，
 且数组的大小都为m，所以我们需要2*m大小的额外空间。
 */
int minPathSum3(vector<vector<int> >& grid)  
{  
    //当grid为空时，返回0  
    if (grid.empty())  
        return 0;  
    //获得grid行数和列数  
    int rows = grid.size();  
    int cols = grid[0].size();  
    //保存s[i-1]行中的元素  
    vector<int> pre(cols, grid[0][0]);  
    //保存当前行的元素  
    vector<int> cur(cols);  
    //初始化pre  
    for (int i = 1; i < cols; ++i)  
    {  
        pre[i] = pre[i - 1] + grid[0][i];  
    }  
    //获得s[i][j]  
    for (int i = 1; i < rows; ++i)  
    {  
        cur[0] = grid[i][0] + pre[0];  
        for (int j = 1; j < cols; ++j)  
        {  
            cur[j] = min(cur[j - 1], pre[j]) + grid[i][j];  
        }  
        swap(cur, pre);  
    }  
    return pre[cols - 1];  
}

/**
方法四(动态规划)：时间复杂度为o(n*m)，空间复杂度为o(m)，需要m大小的额外空间，
注意此方法和方法三的区别，方法三需要2*m大小的额外空间，此方法只需要m大小的额外空间，
在方法三中我们保存当前行s[i]中的元素，假设我们当前计算s[i][j]，我们只需要知道s[i][j-1]的值即可，
不需要保存s[i]行中的元素。每次计算s[i][j]时，我们需要更新pre[j]的值。
*/
int minPathSum4(vector<vector<int> >& grid)  
{  
    //当grid为空时，返回0  
    if (grid.empty())  
        return 0;  
    //获得grid行数和列数  
    int rows = grid.size();  
    int cols = grid[0].size();  
    //保存s[i-1]行中的元素  
    vector<int> pre(cols, grid[0][0]);  
    //保存s[i][j-1]中的元素  
    int cur = grid[0][0];  
    //初始化pre  
    for (int i = 1; i < cols; ++i)  
    {  
        pre[i] = pre[i - 1] + grid[0][i];  
    }  
    //获得s[i][j]的最小值  
    for (int i = 1; i < rows; ++i)  
    {  
        cur = grid[i][0] + pre[0];  
        pre[0] = cur;  
        for (int j = 1; j < cols; ++j)  
        {  
            cur = min(cur, pre[j]) + grid[i][j];  
            pre[j] = cur;  
        }  
    }  
    return pre[cols - 1];  
}

/**
方法五：上述四种方法都不要改变原矩阵中元素的值，
当我们面试的时候，可以问一下面试官是否可以改变原矩阵中的元素，如果可以改变原矩阵中的值，
我们可以再次提高一下空间效率，时间复杂度为o(n*m)，空间复杂度为o(1)。每次计算s[i][j]时，
我们把grid[i][j]更新为此值，因为再之后的访问过程中不需要再次访问grid[i][j]。
*/
int minPathSum5(vector<vector<int> >& grid)  
{  
    if (grid.empty())  
        return 0;  
    int rows = grid.size();  
    int cols = grid[0].size();  
    for (int i = 1; i < cols; ++i)  
    {  
        grid[0][i] = grid[0][i - 1] + grid[0][i];  
    }  
    for (int i = 1; i < rows; ++i)  
    {  
        grid[i][0] = grid[i - 1][0] + grid[i][0];  
    }  
    for (int i = 0; i < rows; ++i)  
    {  
        for (int j = 0; j < cols; ++j)  
        {  
            grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];  
        }  
    }  
    return grid[rows - 1][cols - 1];  
}  





/**
��Ŀ������һ��n*m�ľ��󣬾�����Ԫ�طǸ��������Ͻǵ����½���һ��·����ʹ��·����Ԫ��֮����С��
ÿ��ֻ�����һ���������һ������
���磺
    [10  5  7  4]
	[ 9 11 12  6]
	[ 1  2  4  9]
	[15  1  1  2]
���·��Ϊ��10->9->1->2->1->1->2 

*/
#include <vector> 
#include <iostream> 
#include <iterator> 
using namespace std;
//INT_MAX INT_MIN ���� limits.h �ж��� 
#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)
int N=4,M=4; 
vector<vector<int> > grid(N, vector<int>(M,0));
 
int minPathSum2(vector<vector<int> >& grid);//����һ 
int minPathSum3(vector<vector<int> >& grid);//������ 
int minPathSum4(vector<vector<int> >& grid);//������ 
int minPathSum5(vector<vector<int> >& grid);//������ 

int main(){ 
    /*
    int temp;
	cout << "������������������ĸ������" << endl;
    while(cin>>temp){           //�����ȷ���������ָ��������������ַ�ʽ
		grid[0].push_back(temp);  //�������
	}
    ostream_iterator<int> os(cout, " "); 
    grid[0][2]=4; 
    //������������� 
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
����һ(ת��Ϊͼ�е����·��)�����ǿ��԰Ѿ����е�ÿ��������ͼ�е�һ�����㣬���ڵķ���֮����һ���ߣ�
ÿ������������������ߣ�(��ǰ�����Ҳ෽����һ�����ߣ���ǰ�����²෽����һ������)��
���ǰѾ����е����·��ת��Ϊͼ�е����·����ʹ��Dijstra�㷨�������⣬
�����ٴ�ʹ����򵥵�Dijstra�㷨��û�н����Ż���ͼ���ܹ���n*m���㣬��Ϊÿһ�ζ���Ҫ�ҵ�һ����Сֵ��
����Сֵ�ô���Ϊo(n*m)���ܹ���Ҫ��o(n*m)����Сֵ������ʱ�临�Ӷ�Ϊo(n*n*m*m)��
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
 ������(��̬�滮)��ʱ�临��Ϊo(n*m)�Ϳռ临�Ӷ�Ϊo(n*m)��
 ���͵Ķ�̬�滮���⣬���赱ǰ�Ѿ���ʼ����s[i][j]����ôs[i][j]ֻ���ܴ�s[i-1][j]+grid[i][j]
 ����s[i][j-1]+grid[i][j]����õ���Ҳ����s[i][j] = min(s[i-1][j],s[i][j-1])+grid[i][j]��
 ������Ҫһ��o(n*m)����ռ䱣���Ѿ������s[i][j]��ֵ������ֻ��Ҫ����һ�����鼴�ɡ�
 ���ʱ�临�Ӷ�Ϊo(n*m)���ռ临�Ӷ�Ϊo(n*m)��������Ҫ���⴦������е�һ�к͵�һ�С�
 ��Ϊ��һ��û��s[i-1][j]Ԫ�أ�ֻ��s[i][j-1]Ԫ�ء���һ��û��s[i][j-1]Ԫ�أ�ֻ��s[i-1][j]Ԫ�ء�
 �������£�
*/
int minPathSum2(vector<vector<int> >& grid)  
{  
    //��gridΪ��ʱ������0  
    if (grid.empty())  
        return 0;  
    //��ȡgrid������������  
    int rows = grid.size();  
    int cols = grid[0].size();  
    //��������data,��С��gridһ��  
    vector<vector<int> > data(rows,vector<int>(cols,grid[0][0]));  
    //����data��һ��  
    for (int i = 1; i < rows; ++i)  
    {  
        data[i][0] = data[i - 1][0] + grid[i][0];  
    }  
    //����data��һ��  
    for (int i = 1; i < cols; ++i)  
    {  
        data[0][i] = data[0][i - 1] + grid[0][i];  
    }  
    //����data�ǵ�һ�к͵�һ�е�Ԫ��  
    for (int i = 1; i < rows; ++i)  
    {  
        for (int j = 1; j < cols; ++j)  
        {  
            data[i][j] = min(data[i][j - 1], data[i - 1][j]) + grid[i][j];  
        }  
    }  
    //�������·��ֵ
	 
    return data[rows - 1][cols - 1];  
}

/**
 ������(��̬�滮)��ʱ�临�Ӷ�Ϊo(n*m)���ռ临�Ӷ�Ϊo(m)���˷�����Ҫ2*m����ռ䡣
 ��������s[i][j]ʱ��s[i-2]�е�Ԫ�����ǾͲ�����Ҫ������ֻ��Ҫs[i-1]���е�Ԫ�أ�
 ���ǰ�s[i-1]���е�Ԫ�ر�����pre�����У�����Ĵ�СΪm�����ǰ�s[i]������cur�����У�
 ��s[i]�е�Ԫ�ؼ�������Ժ����ǽ���pre��cur���顣��Ϊ��Ҫpre�����cur���飬
 ������Ĵ�С��Ϊm������������Ҫ2*m��С�Ķ���ռ䡣
 */
int minPathSum3(vector<vector<int> >& grid)  
{  
    //��gridΪ��ʱ������0  
    if (grid.empty())  
        return 0;  
    //���grid����������  
    int rows = grid.size();  
    int cols = grid[0].size();  
    //����s[i-1]���е�Ԫ��  
    vector<int> pre(cols, grid[0][0]);  
    //���浱ǰ�е�Ԫ��  
    vector<int> cur(cols);  
    //��ʼ��pre  
    for (int i = 1; i < cols; ++i)  
    {  
        pre[i] = pre[i - 1] + grid[0][i];  
    }  
    //���s[i][j]  
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
������(��̬�滮)��ʱ�临�Ӷ�Ϊo(n*m)���ռ临�Ӷ�Ϊo(m)����Ҫm��С�Ķ���ռ䣬
ע��˷����ͷ����������𣬷�������Ҫ2*m��С�Ķ���ռ䣬�˷���ֻ��Ҫm��С�Ķ���ռ䣬
�ڷ����������Ǳ��浱ǰ��s[i]�е�Ԫ�أ��������ǵ�ǰ����s[i][j]������ֻ��Ҫ֪��s[i][j-1]��ֵ���ɣ�
����Ҫ����s[i]���е�Ԫ�ء�ÿ�μ���s[i][j]ʱ��������Ҫ����pre[j]��ֵ��
*/
int minPathSum4(vector<vector<int> >& grid)  
{  
    //��gridΪ��ʱ������0  
    if (grid.empty())  
        return 0;  
    //���grid����������  
    int rows = grid.size();  
    int cols = grid[0].size();  
    //����s[i-1]���е�Ԫ��  
    vector<int> pre(cols, grid[0][0]);  
    //����s[i][j-1]�е�Ԫ��  
    int cur = grid[0][0];  
    //��ʼ��pre  
    for (int i = 1; i < cols; ++i)  
    {  
        pre[i] = pre[i - 1] + grid[0][i];  
    }  
    //���s[i][j]����Сֵ  
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
�����壺�������ַ�������Ҫ�ı�ԭ������Ԫ�ص�ֵ��
���������Ե�ʱ�򣬿�����һ�����Թ��Ƿ���Ըı�ԭ�����е�Ԫ�أ�������Ըı�ԭ�����е�ֵ��
���ǿ����ٴ����һ�¿ռ�Ч�ʣ�ʱ�临�Ӷ�Ϊo(n*m)���ռ临�Ӷ�Ϊo(1)��ÿ�μ���s[i][j]ʱ��
���ǰ�grid[i][j]����Ϊ��ֵ����Ϊ��֮��ķ��ʹ����в���Ҫ�ٴη���grid[i][j]��
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





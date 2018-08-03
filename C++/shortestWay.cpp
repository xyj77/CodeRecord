/**
题目：给定一个7x5的方格子，求A点(左上)到B点（右下）的最短路径有多少条？用算法实现。
答：从图中可以看出，A点到B点的最短路径为12，即A点横走5小格，纵走7小格才能最快到达B点，这是排列组合的问题，
即从最短路径12中选取5个横走的小格子(或者从最短路径12中选取7个纵走的小格子)。所以从A点到B点的最短路径条数，
直接可以算出来，即为：
          C(12,5) 或者 C(12,7)
		  (12x11x10x9x8)/(5x4x3x2x1)=792 
编程实现：回溯法
*/

#include<iostream>
using namespace std;
 
int g_num = 0;  //统计A点到B点的最短路径条数
int ROW=7, COL=5; //终点位置 

void shortestPathNumber(int row, int col, int &step)
{
    if (row < 0 || row > ROW || col < 0 || col > COL || step > ROW+COL)
    {
        return;
    }
    if (row == ROW && col == COL) 
    {
        if (step == ROW+COL)  //已到达B点，且等于最短路径12，就累加
        {
            g_num++;
        }
    }
    else
    {
        step++;

        shortestPathNumber(row, col + 1, step); //向2个方向走
        shortestPathNumber(row + 1, col, step);

        step--;//回溯
    }
}

int main()
{
	cin>>ROW>>COL;
    int step = 0;
    shortestPathNumber(0, 0, step); //从(0, 0)点开始搜索
    cout<<"A点到B点的最短路径条数为: "<<g_num<<endl;

    return 0;
}


/*
int g_num = 0;  //统计A点到B点的最短路径条数
void shortestPathNumber(char grid[9][9], int row, int col, int &step)
{
    if (row < 0 || row > 8 || col < 0 || col > 8 || grid[row][col] == '*' || step > 16)
    {
        return;
    }
    if (row == 0 && col == 8) 
    {
        if (step == 16)  //已到达B点，且等于最短路径16，就累加
        {
            g_num++;
        }
    }
    else
    {
        grid[row][col] = '*'; //标记该点已访问
        step++;

        shortestPathNumber(grid, row, col + 1, step); //向4个方向走
        shortestPathNumber(grid, row + 1, col, step);
        shortestPathNumber(grid, row, col - 1, step);
        shortestPathNumber(grid, row - 1, col, step);

        grid[row][col] = '.'; //回溯
        step--;
    }
}
int main()
{
    char grid[9][9] = {0};
    int step = 0;
    shortestPathNumber(grid, 8, 0, step); //从A点开始搜索
    cout<<"A点到B点的最短路径条数为: "<<g_num<<endl;

    return 0;
}
*/




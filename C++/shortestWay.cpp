/**
��Ŀ������һ��7x5�ķ����ӣ���A��(����)��B�㣨���£������·���ж����������㷨ʵ�֡�
�𣺴�ͼ�п��Կ�����A�㵽B������·��Ϊ12����A�����5С������7С�������쵽��B�㣬����������ϵ����⣬
�������·��12��ѡȡ5�����ߵ�С����(���ߴ����·��12��ѡȡ7�����ߵ�С����)�����Դ�A�㵽B������·��������
ֱ�ӿ������������Ϊ��
          C(12,5) ���� C(12,7)
		  (12x11x10x9x8)/(5x4x3x2x1)=792 
���ʵ�֣����ݷ�
*/

#include<iostream>
using namespace std;
 
int g_num = 0;  //ͳ��A�㵽B������·������
int ROW=7, COL=5; //�յ�λ�� 

void shortestPathNumber(int row, int col, int &step)
{
    if (row < 0 || row > ROW || col < 0 || col > COL || step > ROW+COL)
    {
        return;
    }
    if (row == ROW && col == COL) 
    {
        if (step == ROW+COL)  //�ѵ���B�㣬�ҵ������·��12�����ۼ�
        {
            g_num++;
        }
    }
    else
    {
        step++;

        shortestPathNumber(row, col + 1, step); //��2��������
        shortestPathNumber(row + 1, col, step);

        step--;//����
    }
}

int main()
{
	cin>>ROW>>COL;
    int step = 0;
    shortestPathNumber(0, 0, step); //��(0, 0)�㿪ʼ����
    cout<<"A�㵽B������·������Ϊ: "<<g_num<<endl;

    return 0;
}


/*
int g_num = 0;  //ͳ��A�㵽B������·������
void shortestPathNumber(char grid[9][9], int row, int col, int &step)
{
    if (row < 0 || row > 8 || col < 0 || col > 8 || grid[row][col] == '*' || step > 16)
    {
        return;
    }
    if (row == 0 && col == 8) 
    {
        if (step == 16)  //�ѵ���B�㣬�ҵ������·��16�����ۼ�
        {
            g_num++;
        }
    }
    else
    {
        grid[row][col] = '*'; //��Ǹõ��ѷ���
        step++;

        shortestPathNumber(grid, row, col + 1, step); //��4��������
        shortestPathNumber(grid, row + 1, col, step);
        shortestPathNumber(grid, row, col - 1, step);
        shortestPathNumber(grid, row - 1, col, step);

        grid[row][col] = '.'; //����
        step--;
    }
}
int main()
{
    char grid[9][9] = {0};
    int step = 0;
    shortestPathNumber(grid, 8, 0, step); //��A�㿪ʼ����
    cout<<"A�㵽B������·������Ϊ: "<<g_num<<endl;

    return 0;
}
*/




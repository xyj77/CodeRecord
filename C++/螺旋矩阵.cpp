#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std; 

//���ܣ���ӡ��������
//����˵����matrix ����������(x��y) ����һ��Ԫ�ص�����
//          start ����һ��Ԫ�ص�ֵ     n ������Ĵ�С
void SetMatrix(int **matrix, int x, int y, int start, int n){ //�ݹ�ʵ�� 
    int i, j;
    if (n <= 0)
        return;
    if (n == 1){
        matrix[x][y] = start;
        return;
    }
    for (i = x; i < x + n-1; i++)            /* �ϲ� */
        matrix[y][i] = start++;
    for (j = y; j < y + n-1; j++)            /* �ұ� */
        matrix[j][x+n-1] = start++;
    for (i = x+n-1; i > x; i--)              /* �ײ� */
        matrix[y+n-1][i] = start++;
    for (j = y+n-1; j > y; j--)              /* ��� */
        matrix[j][x] = start++;
    SetMatrix(matrix, x+1, y+1, start, n-2); /* �ݹ� */
}

void sparalMat(int *array[],int n) //�ǵݹ�ʵ�� 
{    
    int time = 0;
    int start = 1; //���Ͻ���ʼ��,�������䣬�����ÿһ����ǣ���һ����ʼ�㡣
    while (time < n)
    {
        if (n-1-time==0)
        {
            array[time / 2][time / 2] = start;
        }
        for (int i = 0; i < n-1-time; ++i)
        {
            array[(time / 2)][time/2+i] = start + i;
            array[time / 2 + i][n - 1 - time / 2] = start + (n - time - 1) + i;
            array[n-1 - time / 2][n-1 - time / 2 - i] = start + 2 * (n - 1 - time) + i;
            array[n - 1 - time / 2 - i][time / 2] = start + 3 * (n - 1 - time) + i;
        }
        start += 4 * (n - 1 - time);
        time += 2;
    }
}

int main(){
    int i, j;
    int n;
    int **matrix; //�������󣨶�ά���飩
      
    cin>>n;
    matrix = (int **)malloc(n * sizeof(int *)); //Ϊ�������ռ�
    for (i = 0; i<n; i++)
        matrix[i] = (int *)malloc(n * sizeof(int));
      
    SetMatrix(matrix, 0, 0, 1, n);
    //��ӡ��������
    for(i = 0; i < n; i++){
        for (j = 0; j < n; j++)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }
    
    
    cout<<"*****************************************"<<endl; 
    
    sparalMat(matrix, n);
    //��ӡ��������
    for(i = 0; i < n; i++){
        for (j = 0; j < n; j++)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }
    
    
    return 0;
}

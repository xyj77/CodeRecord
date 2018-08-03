#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std; 

//功能：打印螺旋矩阵
//参数说明：matrix ：螺旋矩阵(x，y) ：第一个元素的坐标
//          start ：第一个元素的值     n ：矩阵的大小
void SetMatrix(int **matrix, int x, int y, int start, int n){ //递归实现 
    int i, j;
    if (n <= 0)
        return;
    if (n == 1){
        matrix[x][y] = start;
        return;
    }
    for (i = x; i < x + n-1; i++)            /* 上部 */
        matrix[y][i] = start++;
    for (j = y; j < y + n-1; j++)            /* 右边 */
        matrix[j][x+n-1] = start++;
    for (i = x+n-1; i > x; i--)              /* 底部 */
        matrix[y+n-1][i] = start++;
    for (j = y+n-1; j > y; j--)              /* 左边 */
        matrix[j][x] = start++;
    SetMatrix(matrix, x+1, y+1, start, n-2); /* 递归 */
}

void sparalMat(int *array[],int n) //非递归实现 
{    
    int time = 0;
    int start = 1; //左上角起始点,做个补充，这个是每一个外壳，第一个起始点。
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
    int **matrix; //螺旋矩阵（二维数组）
      
    cin>>n;
    matrix = (int **)malloc(n * sizeof(int *)); //为矩阵分配空间
    for (i = 0; i<n; i++)
        matrix[i] = (int *)malloc(n * sizeof(int));
      
    SetMatrix(matrix, 0, 0, 1, n);
    //打印螺旋矩阵
    for(i = 0; i < n; i++){
        for (j = 0; j < n; j++)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }
    
    
    cout<<"*****************************************"<<endl; 
    
    sparalMat(matrix, n);
    //打印螺旋矩阵
    for(i = 0; i < n; i++){
        for (j = 0; j < n; j++)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }
    
    
    return 0;
}

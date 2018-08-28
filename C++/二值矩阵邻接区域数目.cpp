/*
二值矩阵，求矩阵中八邻接区域数目以及最大区域元素数目 
*/

#include <iostream>
#include <cstring> 
#include <stdio.h>

FILE *fin = freopen("binMapArea.in", "r", stdin);  
//FILE *fout = freopen("data.out", "w", stdout); 
 
using namespace std;

int data[1001][1001];
int maxnum = 0;

template<typename T>
T &val(T *matrix, int w, int h, int i, int j){
    return *(matrix + j * w + i);
}

int unguarded_count_area_size(bool *visit, int w, int h, int i, int j, int value){
    if (i < 0 || i >= w) return 0;
    if (j < 0 || j >= h) return 0;
 
    if (val(visit, w, h, i, j) == true || data[i][j] != value){
        return 0;
    }
 
    val(visit, w, h, i, j) = true; //访问标记 
 
    const int left = unguarded_count_area_size(visit, w, h, i - 1, j, value);
    const int right = unguarded_count_area_size(visit, w, h, i + 1, j, value);
    const int top = unguarded_count_area_size(visit, w, h, i, j - 1, value);
    const int bottom = unguarded_count_area_size(visit, w, h, i, j + 1, value);
    
    const int lt = unguarded_count_area_size(visit, w, h, i - 1, j - 1, value);
    const int rt = unguarded_count_area_size(visit, w, h, i + 1, j - 1, value);
    const int lb = unguarded_count_area_size(visit, w, h, i - 1, j + 1, value);
    const int rb = unguarded_count_area_size(visit, w, h, i + 1, j + 1, value);
 
    return left + right + top + bottom + lt + rt + lb + rb + 1;
}
 
int count_area(int w, int h){	
    if (w <= 0 || h <= 0) return 0;
    
    bool *visit = new bool[w * h]; //访问矩阵 
    int sum = 0;
 
    memset(visit, 0, sizeof(bool) * w * h);
 
    for (int j = 0; j < h; ++j){
        for (int i = 0; i < w; ++i){
        	int value = data[i][j];
        	if(value == 1){
        		const int size = unguarded_count_area_size(visit, w, h, i, j, value);
 
                if(size >= 1) ++sum;
                if(size > maxnum) maxnum = size;
        	}
        }
    }

    delete[] visit;
    return sum;
}

int main(int argc, char **argv){
	int m,n;
	scanf("%d,%d", &m, &n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n-1;j++){
			scanf("%d,", &data[i][j]);
		}
		scanf("%d", &data[i][n-1]);
	}
	int result = count_area(n, m);
    cout << result << "," << maxnum <<endl;
    return 0;
}

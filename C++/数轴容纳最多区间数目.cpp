/*
-999~999������������ɵ�С������Ŀ
̰�Ĳ���

���룺
3
6 3
1 3
2 5
�����
2

���У������������ҿ����෴ 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
 
struct interval{
	int begin;
	int end;
};
 
bool cmp(interval x,interval y){
	return x.end < y.end;
}

long solve(int n, vector<interval> vec){
	sort(vec.begin(),vec.end(),cmp);
 
	int end = -1000;
	int res = 0;
	for (int i = 0; i < n;i++){
		if(end<=vec[i].begin){
			res++;
			end = vec[i].end;
		}
	}	
	return res;
}

int main(){
	int n;
	cin>>n;
	vector<interval> vec(n);
	for(size_t i = 0; i < n; i++){
		int s, e;
		cin>>s>>e;
		vec[i].begin = s < e ? s:e;
		vec[i].end = s > e ? s:e;
	}
	
	long result = solve(n, vec);
	
	cout<<result<<endl;
	return 0;
} 



/*
��Ŀ������
��һ��������Ҫ�޽�������N����ӵ�����X,Y���ʰ���ô�����ȫ���������еĻ�������������С����Ƕ���
��ע�⣬����Ϊƽ����������������Σ�
��һ��ΪN����ʾ�����Ŀ��2��N��1000��

����ΪN�У�ÿ����������Xi��Yi����ʾ�þ�������꣨-1e9��xi,yi��1e9��
����������С���

*/

#include<iostream>
#include<algorithm>

using namespace std;

long long solve(int n){
	long long x_min=1e9,x_max=-1e9,y_min=1e9,y_max=-1e9;
	for(int i=0;i<n;i++){
	    long long x,y;
		cin>>x>>y;
		x_max = max(x_max,x);
		x_min = min(x_min,x);
		y_min = min(y_min,y);
		y_max = max(y_max,y);
	}
	return max((x_max-x_min),(y_max-y_min));
}

int main(){
	int n;
	while(cin>>n){
		long long result = solve(n);
		cout<<result*result<<endl;
	}
	return 0;
} 

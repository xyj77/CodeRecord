/*
题目描述：
有一个城市需要修建，给你N个民居的坐标X,Y，问把这么多民居全都包进城市的话，城市所需最小面积是多少
（注意，城市为平行于坐标轴的正方形）
第一行为N，表示民居数目（2≤N≤1000）

下面为N行，每行两个数字Xi，Yi，表示该居民的坐标（-1e9≤xi,yi≤1e9）
城市所需最小面积

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

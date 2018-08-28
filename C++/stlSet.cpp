/*
题目描述：
小明有一个花园，花园里面一共有m朵花，对于每一朵花，都是不一样的，小明用1～m中的一个整数表示每一朵花。
他很喜欢去看这些花，有一天他看了n次，并将n次他看花的种类是什么按照时间顺序记录下来。
记录用a[i]表示，表示第i次他看了a[i]这朵花。
小红很好奇，她有Q个问题,问[l,r]的时间内，小明一共看了多少朵不同的花儿，小明因为在忙着欣赏他的花儿，
所以想请你帮他回答这些问题。
输入两个数n,m;(1<=n<=2000,1<=m<=100);分别表示n次看花，m表示一共有m朵花儿。
接下来输入n个数a[1]~a[n]，a[i]表示第i次，小明看的花的种类;
输入一个数Q(1<=Q<=1000000);表示小红的问题数量。
输入Q行 每行两个数 l,r(1<=l<=r<=n); 表示小红想知道在第l次到第r次，小明一共看了多少新类别的花。
一共Q行
每一行输出一个数 表示小明在[l,r]的时间内又看了多少种新类别的花。

样例输入
5 3
1 2 3 2 2
3
1 4
2 4
1 5
样例输出
3
2
3

*/

#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

void solve(int* b, int Q){
    int l, r;
    for(int i=0;i<Q;i++){
    	cin>>l>>r;
    	cout<<b[r]-b[l-1]<<endl;
    }
}

void setTut(){
	set<int> st1;                //创建一个int类型的set
    set<int>::iterator it1;        //创建一个他对应的迭代器
	//empty是判断他是否为空，而且如果要判断空，最好用这个来判断
    //如果为空返回true
    if (st1.empty()){            //判断空,如果是空，则输出empty
        cout << "empty\n";
    }
    
    //插入数据。
    st1.insert(10);                //插入数据
    st1.insert(30);
    st1.insert(20);
    st1.insert(40);
    st1.insert(30);     //重复数据不会插入 
	st1.insert(40);     //重复数据不会放入set 

    //遍历数据，用迭代器遍历数据
    for (it1 = st1.begin(); it1 != st1.end(); ++it1){
        cout << *it1 << endl;
    }
    
    //查找数据，find。返回值是找到的情况的迭代器，如果没有找到，
    //迭代器为end，如果找到，为找到的数据，所以这里一定要先
    //判断一下是否找到数据了。
    cout<<"find 40 ..."<<endl;
    it1 = st1.find(40);            //查找数据
    if (it1 != st1.end()){        //如果找到就输出数据
        cout <<  *it1 << endl;
    }    

    //删除数据这里返回的是是否删除成功，这里是1
    cout<<"delete ..."<<endl; 
    size_t kk = st1.erase(40);
    cout << kk << endl;
    cout << st1.erase(80) << endl;

    //清除全部数据。
    st1.clear();
} 


int main(){
	
	setTut(); 
	
	int n, m, f;
	set<int> si;  //定义set类型存储已经看过的花 
	//set<int>::iterator it; 
	int b[2001];  //用于存储当前时刻已经看过的花的数目 
	memset(b, 0, sizeof(b)); //初始化为全零 
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>f;
		if(si.find(f) == si.end()){ //之前还没看过的花 
			si.insert(f);           //加入已经看过 
			b[i] = b[i-1] + 1;      //看过的花种类+1 
		}
		else{                       //之前已经看过了 
			b[i] = b[i-1];          //看过的花种类不变 
		}
	}
	long Q;
	cin>>Q;
    solve(b, Q);
    return 0;
}

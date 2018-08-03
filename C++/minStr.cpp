/**
十进制中任意一个正整数都可以用 0-9表示出来，但是如果数字只有有限个，有些正整数就无法表示出来。
假如现在手上有0-9的各若干个数字，找出无法组成的最小正整数。
输入：由0-9组成的字符串（1<= length <=1000）；
输出：无法组成的最小正整数。 
样例输入：
    55
样例输出：
    1

Hint：
    Input：
	    123456789
	Output:
	    10 
*/
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
#define Max 1002
char str[Max];
char result[Max];

int least1(int a[], int n){
	int Min = Max, i, j=0;
	for(i=1;i<n;i++){
		if(a[i] < Min){
			Min = a[i];
			j = i;
		}
	}
	return j;
}
void combine(int num, int x, bool haveZero){
	int i;
	for(i=0;i<num;i++){
		result[i] = x+'0';
	}
	//if(!haveZero)
	    result[i] = x+'0';
	//else
	    //result[i] = '0';
}

int main(){
	int count[10];
	memset(count, 0, sizeof(count));
	cin>>str;
	int len = strlen(str);
	for(int i=0;i<len;i++) count[str[i]-'0']++;
	int m_least = least1(count, 10);
	//cout<<m_least<<endl;
	bool haveZero = count[0]!=0;
    combine(count[m_least], m_least, haveZero);
	cout<<result;
	return 0;
} 

/*
	int s=0, e=0;	
	while(count[s++]);
	while(!count[e++]);
	cout<<s<<" "<<e<<endl;
*/

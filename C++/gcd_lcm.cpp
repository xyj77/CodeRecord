#include<iostream>
using namespace std;

int gcd(int a, int b){ //辗转相除求最大公约数 
	return b==0 ? a:gcd(b, a%b);
}
int lcm(int a, int b){  //求最小公倍数 
	return (a/gcd(a, b))*b;//先除再乘，防止溢出 
}

int main(){
	int m,n;
	while(cin>>m>>n){
		cout<<gcd(m, n)<<" "<<lcm(m, n)<<endl;
	}
	return 0;
} 

#include<iostream>
using namespace std;

int gcd(int a, int b){ //շת��������Լ�� 
	return b==0 ? a:gcd(b, a%b);
}
int lcm(int a, int b){  //����С������ 
	return (a/gcd(a, b))*b;//�ȳ��ٳˣ���ֹ��� 
}

int main(){
	int m,n;
	while(cin>>m>>n){
		cout<<gcd(m, n)<<" "<<lcm(m, n)<<endl;
	}
	return 0;
} 

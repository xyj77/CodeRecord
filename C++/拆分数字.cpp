/*
����������ɵ��ַ������Ȱ��ַ����ָ�������֣�
�����ڸ����������С���㣬Ҳ���Բ���ӣ�
1.����������С���������ǰ׺0���Ϸ�
2.����С��������ĺ�׺0���Ϸ���
3. .1��1.���Ϸ� 
�����кϷ�������Ŀ�� 

���磺
���룺123
�����4

��Ϊ��[1, 23]��[12, 3]��[1.2, 3]��[1, 2.3] 

*/
#include<iostream>
#include<cstring>
using namespace std;

long addD(string subStr){
	int len = subStr.length();
	if(len < 2) return 0;
	else if(subStr[len-1] == '0') return 0;
	else if(subStr[0] == '0') return 1;
    else return len-1;
}
long noD(string subStr){
	int len = subStr.length();
	if(len < 1) return 0;
	else if(subStr[0] == '0') return 0;
	else return 1;
}

long solve(string s){
	long len = s.length();
	long n_0=0, n_1=0, n_2=0, n_zero=0;
	
	// ����.
	///for(int i=0;i<len;i++){
	///	if(s[i] == '0') ++n_zero;
	///}
	//n_0 = len -1 - n_zero;
	
	for(int i=1;i<len;i++){
		n_0 += noD(s.substr(0, i)) * noD(s.substr(i, len));
	}
	cout<<n_0<<endl;
	// ��2��.
	for(int i=1;i<len;i++){
		n_2 += addD(s.substr(0, i)) * addD(s.substr(i, len));
	}
	cout<<n_2<<endl;
	 
	// �Ӹ�1.
	for(int i=1;i<len;i++){
		n_1 += noD(s.substr(0, i)) * addD(s.substr(i, len));
		n_1 += addD(s.substr(0, i)) * noD(s.substr(i, len));
	}
	cout<<n_1<<endl;

	return n_0 + n_1 + n_2;
}

int main(){
	string s;
	while(cin>>s){
	    for(int i=1;i<s.length();i++) cout<<s.substr(0, i)<<"  "<<s.substr(i, s.length())<<endl;
	    long result;
	    result = solve(s);
	    cout<<result<<endl;
	}
	return 0;
} 

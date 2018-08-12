/*
判断密码是否规范，规则如下： 
1、长度小于8 ； 
2、没有同时使用数字字母和特殊字符； 
3、出现三个数字构成等比数列，包含三个相同的情况； 
4、出现连续的三个字母，区分大小写； 
5、存在常见字符串，如："pasword"、"admin"、"iloveyou"、"hello"、"qwerty"、"112233"
*/
#include<iostream>
#include<cstring>
#include<ctype.h>
#include<vector>

using namespace std;

bool p1(string s){
	if(s.length()<8) return false;
	else return true;
}

bool p2(string s){
	bool have = false;
	string str = "!@#$%^&*()-=+[]{},.<>/?";
	for(int i=0;i<str.length();i++){
		if(s.find(str[i])!= string::npos){
			have = true;
			break;
		}
	}
	
    bool haveDigit = false;
	for(int i=0;i<s.length();i++){
		if(isdigit(s[i])){
			haveDigit = true;
			break;
		}
	}
	
    bool haveAlpha = false;
	for(int i=0;i<s.length();i++){
		if(isalpha(s[i])){
			haveAlpha = true;
			break;
		}
	}
	return 	bool(have&&haveDigit&&haveAlpha);
}
bool p3(string s){
	int len = s.length();
	for(int i=0;i<len-2;i++){
		if(isdigit(s[i]) && isdigit(s[i+1]) && isdigit(s[i+2])&& s[i+1]-s[i] == s[i+2]-s[i+1]) return false;
	}
	return true;
}
bool p4(string s){
	int len = s.length();
	for(int i=0;i<len-2;i++){
		int a1 = s[i+1]-s[i];
		int a2 = s[i+2]-s[i+1];
		if(isupper(s[i]) && isupper(s[i+1]) && isupper(s[i+2])&& a1==a2 && a1==1) return false;
		if(islower(s[i]) && islower(s[i+1]) && islower(s[i+2])&& a1==a2 && a1==1) return false;
	}
	return true;	
}

bool isfind(string s, string str){
	string::size_type position = s.find(str);
	return position != string::npos;
}
bool p5(string s){
	vector<string> vs;
	vs.push_back("password");
	vs.push_back("admin");
	vs.push_back("qwerty");
	vs.push_back("hello");
	vs.push_back("iloveyou");
	vs.push_back("112233");
	vector<string>::iterator it;
	
	for(it = vs.begin(); it != vs.end(); it++){
		if(isfind(s, *it)) return false;
	}
    return true;
}

void solve(string s){
	//cout<<p1(s)<<p2(s)<<p3(s)<<p4(s)<<p5(s)<<endl;
	if(p1(s)&&p2(s)&&p3(s)&&p4(s)&&p5(s)) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
}

int main(){
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		solve(s);
	}
	return 0;
} 

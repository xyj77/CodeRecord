#include<iostream>
#include<cstring>
#include<vector>
#include<sstream>
using namespace std;

bool isPalindrome(int n){
	stringstream ss;  
    ss << n;
    string str = ss.str(); //int ת string 
	string rev(str.rbegin(), str.rend());
	return str == rev;
	
	/*
	int rev = 0;
	while(x > rev){
		rev = rev*10 + x%10;
		if(rev == 0) return false;
		x /= 10;
    }
    return (rev == x || x == rev/10);
	*/ 
}

int main(){
	int n;
	cin>>n;
	
	bool result = isPalindrome(n);
	
	cout<<result<<endl;
	return 0;
} 

#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define Max 1002

int LCS(string str1, string str2){
    int len1 = str1.length();  
    int len2 = str2.length();
    vector<int> c(len2, 0);
    vector<int> d(len2, 0);
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++){
			if(str1[i] == str2[j]) d[j+1] = c[j] + 1;
			else{
				d[j+1] = c[j+1] > d[j] ? c[j+1]:d[j];
			} 
		}
		for(int j=0;j<len2;j++){
			c[j] = d[j];
		}
	}
	return d[len2];
}

int main(){
	string s1, s2;
	cin>>s1>>s2;
	int lcs = LCS(s1, s2);
	
	cout<<lcs<<endl;
	return 0;
}

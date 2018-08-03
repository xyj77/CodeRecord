/**
最长公共子序列长度 
最长公共字串长度 
*/

#include<iostream>
#include<cstring>
using namespace std;
#define Max 1002
int c[Max][Max];

int LCS(string str1, string str2){//最长公共子序列 
    int len1 = str1.length();  
    int len2 = str2.length();
/*	   
    for (int i = 0; i <= len1; i++) {  
        for( int j = 0; j <= len2; j++) {  
            if(i == 0 || j == 0) {  
                c[i][j] = 0;  
            } else if (str1[i-1] == str2[j-1]) {  
                c[i][j] = c[i-1][j-1] + 1;  
            } else {  
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);  
            }  
        }  
    }  
    return c[len1][len2]; 
*/
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++){
			if(str1[i] == str2[j]) c[i+1][j+1] = c[i][j] + 1;
			else{
				c[i+1][j+1] = c[i][j+1] > c[i+1][j] ? c[i][j+1]:c[i+1][j];
			} 
		}
	}
	return c[len1][len2];
}

int LCS1(string str1, string str2){  //最长公共子串 
    int len1 = str1.length();  
    int len2 = str2.length();  
    int result = 0;     //记录最长公共子串长度   
    for (int i = 0; i <= len1; i++){  
        for( int j = 0; j <= len2; j++){  
            if(i == 0 || j == 0) {  
                c[i][j] = 0;  
            } 
			else if (str1[i-1] == str2[j-1]){  
                c[i][j] = c[i-1][j-1] + 1;  
                result = max(c[i][j], result);  
            } 
			else{  
                c[i][j] = 0;  
            }  
        }  
    }  
    return result;  
} 

int main(){
	memset(c, 0, sizeof(c));
	string s1, s2;
	cin>>s1>>s2;
	int lcs = LCS(s1, s2);
	int lcs1 = LCS1(s1, s2);
	
	cout<<lcs<<"  "<<lcs1<<endl;
	return 0;
}

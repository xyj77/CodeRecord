/**
题意：
给定一字符串，求它的回文子序列个数。内容相同位置不同的子序列算不同的子序列。
例如字符串aba中，回文子序列为"a", "a", "aa", "b", "aba"，共5个。

思路：
对于任意字符串，
如果头尾字符不相等，
则字符串的回文子序列个数就等于去掉头的字符串的回文子序列个数+去掉尾的字符串的回文子序列个数-去掉头尾的字符串的回文子序列个数；
如果头尾字符相等，
则字符串的回文子序列个数就等于去掉头的字符串的回文子序列个数+去掉尾的字符串的回文子序列个数+1。
 
用dp[i][j]表示第i到第j个字符间的最长回文子序列的长度（i<=j），则状态转移方程为：
dp[i][j]=dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] ， if（s[i]！=s[j]）
dp[i][j]=dp[i+1][j] + dp[i][j-1] +1 ， if （s[i]==s[j]）

dp初始矩阵对角线上为1， 即单位矩阵 
*/ 

#include<iostream>
#include<algorithm>
#include<cstring>
 
using namespace std;
#define Max 1002
int dp[Max][Max];
string str;

int solve(){    //非递归解法 ，求回文子序列数目 
    int l=str.length();  
    for(int j=0;j<l;++j){  
        dp[j][j]=1;  
        for(int i=j-1;i>=0;--i){  
            if(str[i]==str[j]) dp[i][j]=dp[i+1][j]+dp[i][j-1]+1;  
            else dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];  
        }  
    }  
    return dp[0][l-1];  
}

int solve_d(int i, int j){ //递归解法 ，求回文子序列数目 
	if(i>j) return 0;
	if(i==j) return 1;
	if(str[i] == str[j]){
		return solve_d(i+1, j) + solve_d(i, j-1) + 1;
	}
	else{
		return solve_d(i+1, j) + solve_d(i, j-1) - dp[i+1][j-1];   //使用记录下的结果 
		//return solve_d(i+1, j) + solve_d(i, j-1) - solve_d(i+1, j-1); //没有记录结果，比较慢 
	}
}  

int longestPalindromeSubSequence(){ //求最长回文子序列长度 
    int len=str.length();
    for(int j=0;j<len;j++){
        dp[j][j]=1;
        for(int i=j-1;i>=0;i--){
            if(str[i]==str[j])
                dp[i][j]=dp[i+1][j-1]+2;
            else
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        }
    }
    return dp[0][len-1];
}
 
int LagPalindrome(){      // 最长回文子串的长度
    int n = str.length(), count = 0; 
    int max = 0;//记录最长回文子串的长度  
    if(n<1){  
        return 0;  
    }  
    for (int i = 0; i < n; i++){         
        //子串为奇数时  
        for (int j = 0; (i-j)>=0&&(i+j)<n; j++){  
            if (str[i - j] != str[i + j]) break; 
            count = 2 * j + 1;  
        }  
        if (count > max)  max = count;   
        //子串为偶数时  
        for (int k = 0; (i - k)>=0 && (i + k + 1) < n; k++){  
            if (str[i - k] != str[i + k+1]) break; 
            count=2*k + 2;  
        }  
        if (count > max) max = count;  
    } 
    return max;  
}   
 
int main(){
	memset(dp, 0, sizeof(dp));
    while(cin>>str){  
        cout<<solve()<<endl;     //非递归求回文子序列数目 
		cout<<solve_d(0, str.length()-1)<<endl; // 递归解法 ，求回文子序列数目
		cout<<longestPalindromeSubSequence()<<endl; //最长回文子序列长度 
		cout<<LagPalindrome()<<endl; //最长回文子串长度
    }  
    return 0;  
}  



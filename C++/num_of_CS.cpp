/**
求非空回文子序列数目
输入：XXY
输出：4 
*/
#include <algorithm>  
#include <cstring>  
#include <iostream>  
using namespace std;   
int dp[52][52];    
int main(){
    string s;
    memset(dp, 0, sizeof(dp));
    while(cin>>s){
        string rs = s;
        int len = s.length();
        reverse(rs.begin(), rs.end());
        for(int i=1;i<=len;i++)
            for(int j=1;j<=len;j++){  
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]; 
                if(s[i-1]==rs[j-1]) dp[i][j]+=dp[i-1][j-1]+1; 
            }
        cout<<dp[len][len]<<endl;
        //cout<<s<<" "<<rs<<endl;
    }
    return 0; 
} 

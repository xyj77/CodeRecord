/**
���⣺
����һ�ַ����������Ļ��������и�����������ͬλ�ò�ͬ���������㲻ͬ�������С�
�����ַ���aba�У�����������Ϊ"a", "a", "aa", "b", "aba"����5����

˼·��
���������ַ�����
���ͷβ�ַ�����ȣ�
���ַ����Ļ��������и����͵���ȥ��ͷ���ַ����Ļ��������и���+ȥ��β���ַ����Ļ��������и���-ȥ��ͷβ���ַ����Ļ��������и�����
���ͷβ�ַ���ȣ�
���ַ����Ļ��������и����͵���ȥ��ͷ���ַ����Ļ��������и���+ȥ��β���ַ����Ļ��������и���+1��
 
��dp[i][j]��ʾ��i����j���ַ��������������еĳ��ȣ�i<=j������״̬ת�Ʒ���Ϊ��
dp[i][j]=dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] �� if��s[i]��=s[j]��
dp[i][j]=dp[i+1][j] + dp[i][j-1] +1 �� if ��s[i]==s[j]��

dp��ʼ����Խ�����Ϊ1�� ����λ���� 
*/ 

#include<iostream>
#include<algorithm>
#include<cstring>
 
using namespace std;
#define Max 1002
int dp[Max][Max];
string str;

int solve(){    //�ǵݹ�ⷨ ���������������Ŀ 
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

int solve_d(int i, int j){ //�ݹ�ⷨ ���������������Ŀ 
	if(i>j) return 0;
	if(i==j) return 1;
	if(str[i] == str[j]){
		return solve_d(i+1, j) + solve_d(i, j-1) + 1;
	}
	else{
		return solve_d(i+1, j) + solve_d(i, j-1) - dp[i+1][j-1];   //ʹ�ü�¼�µĽ�� 
		//return solve_d(i+1, j) + solve_d(i, j-1) - solve_d(i+1, j-1); //û�м�¼������Ƚ��� 
	}
}  

int longestPalindromeSubSequence(){ //������������г��� 
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
 
int LagPalindrome(){      // ������Ӵ��ĳ���
    int n = str.length(), count = 0; 
    int max = 0;//��¼������Ӵ��ĳ���  
    if(n<1){  
        return 0;  
    }  
    for (int i = 0; i < n; i++){         
        //�Ӵ�Ϊ����ʱ  
        for (int j = 0; (i-j)>=0&&(i+j)<n; j++){  
            if (str[i - j] != str[i + j]) break; 
            count = 2 * j + 1;  
        }  
        if (count > max)  max = count;   
        //�Ӵ�Ϊż��ʱ  
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
        cout<<solve()<<endl;     //�ǵݹ��������������Ŀ 
		cout<<solve_d(0, str.length()-1)<<endl; // �ݹ�ⷨ ���������������Ŀ
		cout<<longestPalindromeSubSequence()<<endl; //����������г��� 
		cout<<LagPalindrome()<<endl; //������Ӵ�����
    }  
    return 0;  
}  



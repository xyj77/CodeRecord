/*
判断给出的若干字符串中是否含有双生串，
将字符串首尾连接，再从某个位置切开。
如果两个字符串通过以上操作能得到相同的字符串，
则这两个字符串为双生串，注意切开字符串后有两个方向。
例如：
abcde 和 eabcd 是双生串 
helloworld 和  hdlrowolle 是双生串

abcde 和 bacde 不是双生串 


输入：
第一行：n   表示数据组数
接下来n组数，
每组数第一行一个整数m，接下来m行，每行一个字符串。
判断m个字符串中是否存在双生串。
存在输出Yeah，不存在输出Sad 

*/ 
#include<iostream>
#include<cstring>
#include <algorithm>
#include<vector>

using namespace std;


/*
//方法一： 先找到字符串的最小表示法，再比较是否相同，会超时。 
 
//用最小表示法求字符串S的最小字典序返回字典序最小的串的首字母位置
int minstr(char* s){
    int len=strlen(s);
    int i=0,j=1;
    while(i<=len-1 && j<=len-1){
        int k=0;
        while(k<=len-1 && s[(i+k)%len]==s[(j+k)%len])
            k++;
        if(k>=len)
            break;
            
        //此时s[i+1]到s[i+k]都不可能是最小字符串的开头，
		//而且s[i+1]到s[j]也不可能是最小字符串的开头(s[i]开头的字符串与s[j]开头的字符串在比较，
		//本身已经说明s[i]开头的字符串小于以s[i+1]开头到以s[j-1]开头的字符串了)
        if(s[(i+k)%len]>s[(j+k)%len])
            i=max(i+k+1,j+1);
        else
            j=max(j+k+1,i+1);
    }
    return min(i,j);
}

//用最大表示法求字符串S的最大字典序返回字典序最大的串的首字母位置
int maxstr(char s[]){
    int len=strlen(s);
    int i=0,j=1;
    while(i<=len-1 && j<=len-1){
        int k=0;
        while(k<=len-1 && s[(i+k)%len]==s[(j+k)%len])
                k++;
        if(k>=len)
            break;
        if(s[(i+k)%len]<s[(j+k)%len])
            i=max(i+k+1,j+1);
        else
            j=max(j+k+1,i+1);
    }
    return min(i,j);
}

void reconcatstr(int loc, string str, char* s){
	int len = str.length(), i=loc, index=0;
	while(i<len){
		s[index++] = str[i++];
	}
	i=0;
	while(i<loc){
		s[index++] = str[i++];
	}
	s[index] = '\0';
}

bool isDouble(string str1, string str2){
	int len1 = str1.length(), len2 = str2.length();
	if(len1 != len2){
		return false;
	}
	int loc1 = minstr((char*)str1.c_str());
	int loc2 = minstr((char*)str2.c_str());
	//cout<<loc1<<" "<<loc2<<endl;
	char s1[33], s2[33];
	reconcatstr(loc1, str1, s1);
	reconcatstr(loc2, str2, s2);
	//cout<<s1<<endl;
	//cout<<s2<<endl;
	if(strcmp(s1, s2) == 0){
		return true;
	}
	else{
		return false;
	}
}

bool solve(vector<string> vs){
	int len = vs.size();
	for(int i=0;i<len;i++){
		for(int j=i+1;j<len;j++){
			string str1 = vs[i], str2 = vs[j];
			string revs(str1.rbegin(),str1.rend());
			if(isDouble(str1, str2) || isDouble(revs, str2)){
				return true;
			}	
		}
	}
	return false;
}
*/

//方法二：拼接字符串自身，包含了循环串所有情况
bool solve(vector<string> vs){
	int len = vs.size();
	for(int i=0;i<len;i++){
		for(int j=i+1;j<len;j++){
			string str1 = vs[i], str2 = vs[j];
			string concatStr = str1 + str1;
			reverse(str1.begin(), str1.end());
			string reverseStr = str1 + str1;
            if(concatStr.find(str2)!=string::npos || reverseStr.find(str2)!=string::npos){
            	return true;
            }
		}
	}
	return false;
} 

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		if(t<=1){
			cout<<"Sad"<<endl;
			break;
		}
		vector<string> vs;
		for(int i=0;i<t;i++){
			string str;
			cin>>str;
			vs.push_back(str);
		}
	    bool result = solve(vs);
	    if(result){
	    	cout<<"Yeah"<<endl;
	    }
	    else{
	    	cout<<"Sad"<<endl;
	    }
	}
	return 0;
} 

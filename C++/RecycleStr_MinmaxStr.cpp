/*
�жϸ����������ַ������Ƿ���˫������
���ַ�����β���ӣ��ٴ�ĳ��λ���п���
��������ַ���ͨ�����ϲ����ܵõ���ͬ���ַ�����
���������ַ���Ϊ˫������ע���п��ַ���������������
���磺
abcde �� eabcd ��˫���� 
helloworld ��  hdlrowolle ��˫����

abcde �� bacde ����˫���� 


���룺
��һ�У�n   ��ʾ��������
������n������
ÿ������һ��һ������m��������m�У�ÿ��һ���ַ�����
�ж�m���ַ������Ƿ����˫������
�������Yeah�����������Sad 

*/ 
#include<iostream>
#include<cstring>
#include <algorithm>
#include<vector>

using namespace std;


/*
//����һ�� ���ҵ��ַ�������С��ʾ�����ٱȽ��Ƿ���ͬ���ᳬʱ�� 
 
//����С��ʾ�����ַ���S����С�ֵ��򷵻��ֵ�����С�Ĵ�������ĸλ��
int minstr(char* s){
    int len=strlen(s);
    int i=0,j=1;
    while(i<=len-1 && j<=len-1){
        int k=0;
        while(k<=len-1 && s[(i+k)%len]==s[(j+k)%len])
            k++;
        if(k>=len)
            break;
            
        //��ʱs[i+1]��s[i+k]������������С�ַ����Ŀ�ͷ��
		//����s[i+1]��s[j]Ҳ����������С�ַ����Ŀ�ͷ(s[i]��ͷ���ַ�����s[j]��ͷ���ַ����ڱȽϣ�
		//�����Ѿ�˵��s[i]��ͷ���ַ���С����s[i+1]��ͷ����s[j-1]��ͷ���ַ�����)
        if(s[(i+k)%len]>s[(j+k)%len])
            i=max(i+k+1,j+1);
        else
            j=max(j+k+1,i+1);
    }
    return min(i,j);
}

//������ʾ�����ַ���S������ֵ��򷵻��ֵ������Ĵ�������ĸλ��
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

//��������ƴ���ַ�������������ѭ�����������
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

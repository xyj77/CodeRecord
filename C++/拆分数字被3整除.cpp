#include<iostream>
#include<cstring>
#include <limits> 
using namespace std;

string str;

int main(){
    cin>>str;
    int result=0, count=0, x=0, len=str.length();
    for (int i=0;i<len;i++){
        int tmp = str[i]-'0';
        count++; x += tmp%3;
        if (tmp%3==0 || x%3 == 0 || count == 3){
            ++result;
            count = x = 0;
        }
    }
    cout<<result<<endl;
	return 0;
}

/*
����������ɵ��ַ����������ֶ��������ÿ�����ֶ��ܱ�3����
�������ܲ�ɶ��ٸ����֡�
���룺 
12345 
�����
3

��Ϊ��[12,3,45]��[123,45] 
*/

/*
寻找数组中差异最大的两个数，并求出其组合数 
*/

#include<iostream>
using namespace std;
#define Max 200002
int b[Max];

int getMaxOrMin(int *arr, int count, bool isMax)
{  
    int temp=arr[0];  
    for(int i=1;i<count;i++){  
        if(isMax){  
            if(temp<arr[i]){  
                temp=arr[i];  
            }  
        }
		else{  
            if(temp>arr[i]){  
                temp=arr[i];  
            }             
        }     
    }  
    return temp;      
} 
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>b[i];
	int max = getMaxOrMin(b, n, 1);
	int min = getMaxOrMin(b, n, 0);
	int n_max = 0;
	int n_min = 0;
	for(int i=0;i<n;i++)
	{
		if(b[i] == max) n_max++;
		if(b[i] == min) n_min++;
	}
	int diff = max - min;
	long long count;
	if(diff)
	    count = n_max*n_min;
	else
	    count = n*(n-1)/2;
	cout<<diff<<" "<<count<<endl;
	return 0;
} 

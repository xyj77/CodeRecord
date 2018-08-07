#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1001

using namespace std;

bool compare(const int& a, const int& b) {
    return a > b;  //从大到小，sort默认从小到大排序 
}

void inputVector(vector<int>& vec, int n){
    for(size_t i=0;i<n;i++){
		int temp;
		cin>>temp;
		vec.push_back(temp); 
	}
}

void inputVector2d(vector<vector<int> >& vec2d, int m, int n){
	int temp;
	vector<int> tempV;
	for(size_t i=0;i<m;i++){
		tempV.clear(); //每次清空 
		for(size_t i=0;i<n;i++){
		    cin>>temp;
		    tempV.push_back(temp); 
	    }
	    vec2d.push_back(tempV);
	}
}

void printVector(vector<int>& vec){
	// 方法一 
	//vector<int>::iterator it;
    //for(it = vec.begin(); it != vec.end(); it++){
    //	cout << *it << endl;
    //}
    //方法二 
    for(size_t i = 0;i < vec.size();i++) {
        cout << vec.at(i) << endl;
    }
}
void printVector2d(vector<vector<int> >& vec2d){
    for(size_t i=0;i < vec2d.size();i++){
    	for(size_t j=0;j<vec2d.at(i).size();j++){
    		cout << vec2d[i][j]<<" ";
    	}
    	cout<<endl;
    }
}  

int main(){
	int n;
	cin>>n;
	// 一维数组 
	vector<int> vec;
	inputVector(vec, n);
	sort(vec.begin(), vec.end(), compare);
	printVector(vec);
	
	int m2d, n2d;
	cin>>m2d>>n2d;
	// 二维数组
	vector<vector<int> > vec2d;
	inputVector2d(vec2d, m2d, n2d);
	printVector2d(vec2d);
	
	return 0;
}

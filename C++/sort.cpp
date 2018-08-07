#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1001

using namespace std;

bool compare(const int& a, const int& b) {
    return a > b;  //�Ӵ�С��sortĬ�ϴ�С�������� 
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
		tempV.clear(); //ÿ����� 
		for(size_t i=0;i<n;i++){
		    cin>>temp;
		    tempV.push_back(temp); 
	    }
	    vec2d.push_back(tempV);
	}
}

void printVector(vector<int>& vec){
	// ����һ 
	//vector<int>::iterator it;
    //for(it = vec.begin(); it != vec.end(); it++){
    //	cout << *it << endl;
    //}
    //������ 
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
	// һά���� 
	vector<int> vec;
	inputVector(vec, n);
	sort(vec.begin(), vec.end(), compare);
	printVector(vec);
	
	int m2d, n2d;
	cin>>m2d>>n2d;
	// ��ά����
	vector<vector<int> > vec2d;
	inputVector2d(vec2d, m2d, n2d);
	printVector2d(vec2d);
	
	return 0;
}

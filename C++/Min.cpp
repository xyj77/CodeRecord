#include<iostream>
using namespace std; 


int Min(int number1, int number2, int number3) {
    int min = (number1 < number2) ? number1 : number2;
    min = (min < number3) ? min : number3;
    return min;
}

int main(){
	int a, b, c;
	cin>>a>>b>>c;
	cout<<Min(a, b, c)<<endl;
	return 0;
}

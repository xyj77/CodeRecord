#include <math.h> // for fabs sqrt
#include <float.h> // for DBL_EPSILON DBL_DIG etc.
#include <time.h> // for clock
#include <stdio.h>
#include <assert.h>
#include <iostream>
using namespace std;
double A;
//f(x)��������f(a)*f(b)<0,��(a,b)֮�������� 
//���ַ�������ⷽ�̽��ƽ� 
double bisection(double (*f)(double), double a, double b, double eps){
	double m;
	assert( f != NULL && f(a) * f(b) < 0.0 && (b-a) > DBL_EPSILON); // (b-a) > DBL_EPSILON �� b > a
 
	while( b - a > eps ) {
		m = (a + b)/2;
		if( f(m) * f(a) < 0.0 ) b = m;
		else a = m;
	}
	return m;
}

//ţ�ٷ���x_k+1 = x_k - f(x_k)/f'(x_k) 
//���߷���x_k+1 = x_k - f(x_k)*(x_k - x_k-1)/[f(x_k)-f(x_k-1)] 
//���߷���һ�㷽�̵Ľ��ƽ� 
double secant(double (*f)(double), double x0, double x1, double eps){
	double x2;
	while(true){
		x2 = x1 - f(x1)/(f(x1) - f(x0))*(x1 - x0);//�ø��ߴ����� 
		if( fabs(x2-x1) < eps ) 
			break;
		x0 = x1;
		x1 = x2;
	}
	return x2;
}

double f(double x){
	return x*x - A;//��sqrt(A)��Ӧ�ķ��� 
}

int main(){
	while(true){
		cin>>A;
		//�������ѡ��sqrt [0, A+1/4] 
		//��A<1ʱ��A+1/4 >= sqrt(A) >=0;��A>1ʱ��A+1/4 > A > sqrt(A) >= 0
		//���sqrt(A)һ����[0, A+1/4]֮�� 
	    cout<<bisection(f, 0, A+0.25, 1e-6)<<endl;
	    cout<<secant(f, 0, A+0.25, 1e-6)<<endl;
	}

	return 0;
}


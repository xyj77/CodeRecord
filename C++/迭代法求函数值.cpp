#include <math.h> // for fabs sqrt
#include <float.h> // for DBL_EPSILON DBL_DIG etc.
#include <time.h> // for clock
#include <stdio.h>
#include <assert.h>
#include <iostream>
using namespace std;
double A;
//f(x)连续，若f(a)*f(b)<0,则(a,b)之间存在零点 
//二分法求解任意方程近似解 
double bisection(double (*f)(double), double a, double b, double eps){
	double m;
	assert( f != NULL && f(a) * f(b) < 0.0 && (b-a) > DBL_EPSILON); // (b-a) > DBL_EPSILON 即 b > a
 
	while( b - a > eps ) {
		m = (a + b)/2;
		if( f(m) * f(a) < 0.0 ) b = m;
		else a = m;
	}
	return m;
}

//牛顿法：x_k+1 = x_k - f(x_k)/f'(x_k) 
//割线法：x_k+1 = x_k - f(x_k)*(x_k - x_k-1)/[f(x_k)-f(x_k-1)] 
//割线法求一般方程的近似解 
double secant(double (*f)(double), double x0, double x1, double eps){
	double x2;
	while(true){
		x2 = x1 - f(x1)/(f(x1) - f(x0))*(x1 - x0);//用割线代替求导 
		if( fabs(x2-x1) < eps ) 
			break;
		x0 = x1;
		x1 = x2;
	}
	return x2;
}

double f(double x){
	return x*x - A;//求sqrt(A)对应的方程 
}

int main(){
	while(true){
		cin>>A;
		//解区间的选择：sqrt [0, A+1/4] 
		//当A<1时：A+1/4 >= sqrt(A) >=0;当A>1时：A+1/4 > A > sqrt(A) >= 0
		//因此sqrt(A)一定在[0, A+1/4]之间 
	    cout<<bisection(f, 0, A+0.25, 1e-6)<<endl;
	    cout<<secant(f, 0, A+0.25, 1e-6)<<endl;
	}

	return 0;
}


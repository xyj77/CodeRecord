/*
��Ŀ��С��������Ů����������飬������ָ�Ͽ���һ�����İ��ġ�
���ɿ��������뿼��һ��С��������һ���⡣����(x^2+y^2-1)^2-(xy)^2=0�ܻ���һ�������İ��ģ�
���ڸ���һ����(x,y)�����У�X��N((��1,��1^2)��Y��N((��2,��2^2)��������������������ĸ����Ƕ��٣�
��ȷ��0.1��С�������һλС��������0.1, 0.2�ȣ�
*/ 


#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

/*���ɱ�׼��̬�ֲ������*/
double gaussRand(){
    static double V1,V2,S;
    static int  phase=0;
    double X;

    if(phase==0){
        do{
            double U1=(double)rand()/RAND_MAX;
            double U2=(double)rand()/RAND_MAX;

            V1=2*U1-1;
            V2=2*U2-1;
            S=V1*V1+V2*V2;
        }while(S>=1||S==0);

        X=V1*sqrt(-2*log(S)/S);
    }
    else
        X=V2*sqrt(-2*log(S)/S);

    phase=1-phase;

    return X;
}

/*�����ֵ����̬�ֲ�N(0,1)ת������˹�ֲ�N(mu,sigma)*/
double gaussValue(double val,double mu,double sigma)
{
    return mu+sigma*val;
}
/*�ж����ֵ�Ƿ���������*/
bool isInside(double x,double y)
{   
    double x2=x*x;
    double y2=y*y;
    double temp=x2+y2-1;
    return (temp*temp-x2*y2)>0?false:true;
}
/*ģ��*/
double learnCurve(double mu1,double sigma1,double mu2,double sigma2)
{
    int n=10000;//ģ�����
    int count=0;
    int i=n;
    while(i-->0){
        double x=gaussValue(gaussRand(),mu1,sigma1);
        double y=gaussValue(gaussRand(),mu2,sigma2);
        if(isInside(x,y))
            count++;
    }
    return (double) count/n;
}

int main()
{
    double mu1,mu2,sigma1,sigma2;
    cin>>mu1>>sigma1>>mu2>>sigma2;

    double res=learnCurve(mu1,sigma1,mu2,sigma2);
    printf("%.1f\n",res);

    return 0;
}


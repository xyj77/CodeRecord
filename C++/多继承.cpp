#include <iostream>
using namespace std;
//����

class D{
public:
    D(){cout<<"D()"<<endl;}
    ~D(){cout<<"~D()"<<endl;}
protected:
    int d;
};

class B:virtual public D{//��̳�(��״�̳�),A->D, B->D, C->(A��B)
public:
    B(){cout<<"B()"<<endl;}
    ~B(){cout<<"~B()"<<endl;}
protected:
    int b;//4
};

class A:virtual public D{//����̳л�ʹD������������,Ҫ������������Ҫ������̳и�ʽ,�ڴ��������ʱ��ᴴ��һ�����
                         //��ʽ��class ����: virtual �̳з�ʽ ������
public:
    A(){cout<<"A()"<<endl;}
    ~A(){cout<<"~A()"<<endl;}
protected:
    int a;//4 
};

class C:public B, public A{
public:
    C(){cout<<"C()"<<endl;}
    ~C(){cout<<"~C()"<<endl;}
protected:
    int c;//4�ֽ� 
};

int main(){
    C c;   //D, B, A ,C
    cout<<sizeof(c)<<endl;
    return 0;
}

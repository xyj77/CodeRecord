#include <iostream>
using namespace std;
//基类

class D{
public:
    D(){cout<<"D()"<<endl;}
    ~D(){cout<<"~D()"<<endl;}
protected:
    int d;
};

class B:virtual public D{//多继承(环状继承),A->D, B->D, C->(A，B)
public:
    B(){cout<<"B()"<<endl;}
    ~B(){cout<<"~B()"<<endl;}
protected:
    int b;//4
};

class A:virtual public D{//这个继承会使D创建两个对象,要解决上面问题就要用虚拟继承格式,在创建对象的时候会创建一个虚表
                         //格式：class 类名: virtual 继承方式 父类名
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
    int c;//4字节 
};

int main(){
    C c;   //D, B, A ,C
    cout<<sizeof(c)<<endl;
    return 0;
}

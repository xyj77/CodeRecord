#include <iostream>  
#include <cstdio>  
#define INT_MIN 0x80000000
#define INT_MAX 0x7fffffff  
using namespace std;
 
int main()
{
    //32λ����������������Ϊ��2147483647
    cout<<"32λ����������Χ"<<endl;
    cout<<(int)INT_MIN<<" -- "<<INT_MAX<<endl;
    cout<<endl;
	
    //����int��ʾ��ΧcoutĬ��unsigned int�������:2147483648
    cout<<"�����C++Ĭ��ת�����޷����������"<<endl;
    cout<<"0x80000000:"<<0x80000000<<endl;
    //����int��ʾ��ΧcoutĬ��unsigned int�������:2147483649
    cout<<"0x80000001:"<<0x80000001<<endl;
    cout<<endl;
    //ָ��������ͣ������-2147483648
    printf("Cֱ�������������\n0x7fffffff:%d\n",0x7fffffff);
    printf("0x80000000:%d\n",0x80000000);//ָ��������ͣ������-2147483648
    //��������Ϊʮ�����Ʊ�ʾ�Ĳ��룬��������Ӧ��ԭ�����ֵΪ��-2147483647 
    printf("0x80000001:%d\n",0x80000001);
    //��������Ϊʮ�����Ʊ�ʾ�Ĳ��룬��������Ӧ��ԭ�����ֵΪ��-1	
    printf("���������0xffffffff��%d\n",0xffffffff);
	
    int b=0x0001;
    //~b�Ƕ�b�Ĳ��루��������λ����λȡ����~b,0xfffe,�˲����Ӧ��ֵΪ-2������0xffff��Ӧ-1 
    printf("\n0x0001:%d\n~0x0001:%d\n",b, ~b);//���Ϊ-2
    return 0;
}

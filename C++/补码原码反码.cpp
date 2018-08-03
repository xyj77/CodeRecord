#include <iostream>  
#include <cstdio>  
#define INT_MIN 0x80000000
#define INT_MAX 0x7fffffff  
using namespace std;
 
int main()
{
    //32位机器最大整数，输出为：2147483647
    cout<<"32位机器整数范围"<<endl;
    cout<<(int)INT_MIN<<" -- "<<INT_MAX<<endl;
    cout<<endl;
	
    //超过int表示范围cout默认unsigned int类型输出:2147483648
    cout<<"溢出后（C++默认转换成无符号输出）："<<endl;
    cout<<"0x80000000:"<<0x80000000<<endl;
    //超过int表示范围cout默认unsigned int类型输出:2147483649
    cout<<"0x80000001:"<<0x80000001<<endl;
    cout<<endl;
    //指定输出整型，输出：-2147483648
    printf("C直接输出溢出结果：\n0x7fffffff:%d\n",0x7fffffff);
    printf("0x80000000:%d\n",0x80000000);//指定输出整型，输出：-2147483648
    //函数参数为十六进制表示的补码，输出补码对应的原码的数值为：-2147483647 
    printf("0x80000001:%d\n",0x80000001);
    //函数参数为十六进制表示的补码，输出补码对应的原码的数值为：-1	
    printf("最大负整数：0xffffffff：%d\n",0xffffffff);
	
    int b=0x0001;
    //~b是对b的补码（包括符号位）按位取反，~b,0xfffe,此补码对应的值为-2，补码0xffff对应-1 
    printf("\n0x0001:%d\n~0x0001:%d\n",b, ~b);//输出为-2
    return 0;
}

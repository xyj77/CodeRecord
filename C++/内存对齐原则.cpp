/* 
struct 和 union内存对齐三原则： 
原则1：struct或者union的成员，第一个成员在偏移0的位置，之后的每个成员的起始位置必须是当前成员大小的整数倍；
原则2：如果结构体A含有结构体成员B，那么B的起始位置必须是B中最大元素大小整数倍地址；
原则3：结构体的总大小，必须是内部最大成员的整数倍；
*/
#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct bb{
 int id;            //[0]....[3]
 double weight;     //[8].....[15]　　　　　　   原则1
 float height;      //[16]..[19],总长要为８的整数倍,补齐[20]...[23]　　　　　原则3
}BB;

typedef struct aa{
 char name[2];     //[0],[1]
 int  id;          //[4]...[7]　　　　　　　　　原则１

 double score;     //[8]....[15]　　　　
 short grade;      //[16],[17]　　　　　　　　
 BB b;             //[24]......[47]　　　　　　　原则２
}AA;

int main(){
  AA a;
  cout<<sizeof(a)<<" "<<sizeof(BB)<<endl;
  return 0;
}

/*输出
48 24
*/


///////////////////////////////////////////// 
typedef struct stu{
    char a;
    int b;
    char ex;
    double c;
    char d;
}STU;

/*32位输出
STU的大小是 = 24
*/

/*64位输出
STU的大小是 = 32
*/

/*计算：
32位：a( 4 )+b( 4 )+ex( 4 )+c( 4+4 )+d( 4 ) == 24 
64位：a( 4 )+b( 4 )+ex( 8 )+c( 8 )+d( 8 ) == 32

char遇到int型，产生3个空白，遇上double要产生7个空白。而这里32位中的char遇上double却只是产生了3个空白，
是因为32位限制了一次只能读入4个字节数据处理，也就是说8字节的double被分成了2个4字节字符被处理，
可以认为，32位平台下就定死了4字节对齐（当然你可以设定更小，但是没什么意义），
接着说结构体，那结构体中最大的数就是4字节的了，sizeof(STU)也只需要遵守是4的整数倍即可。
最后得到24字节。

64位就按正常的三原则计算。
*/ 



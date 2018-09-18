#include<iostream>
using namespace std;
/*
4的幂次方写成二进制形式后，很容易就会发现有一个特点：
二进制中只有一个1（1在奇数位置），并且1后面跟了偶数个0；
因此问题可以转化为判断1后面是否跟了偶数个0就可以了。

4的整数次幂的二进制数都为 (4)100、(16)10000、(64)1000000

4的幂次方4^n也可以写为2^(2*n)，即也可以写为2的幂次方，当然就满足2的幂次方的条件了，即num & num-1==0。
思路：首先用条件num & num-1==0来判断是否为2的幂次方，若不满足，则不是。
若满足，在用条件num & 0x55555555来判断，若为真，则这个整数是4的幂次方，否则不是。
*/
bool isPow4(unsigned int x){ //判断x是否是4的幂次方
  if ( x & (x - 1) )         //判断x是否为2的幂次方
	  return false;
  return x & 0x55555555;     //判断1是否在奇数位置上
}
 
int log4(int value){         //递归判断一个数是4的多少次方
	if (value == 1)
		return 0;
	else{
		value>>=1;          //往右移位
		return 1+log4(value>>1); //往右移位
	}
}
 
int main(){
	int num;
	cin>>num;
	if(isPow4(num))     //使用与运算判断一个数是否是2的幂次方
		cout<<"Yes   "<<num<<"=4^"<<log4(num)<<endl;
	else
		cout<<"No"<<endl;

	return 0;
}


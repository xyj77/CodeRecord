/*
给定 x, k ，求满足 x + y = x | y 的第 k 小的正整数 y 。 | 是二进制的或(or)运算，例如 3 | 5 = 7。
比如当 x=5，k=1时返回 2，因为5+1=6 不等于 5|1=5，而 5+2=7 等于 5 | 2 = 7。

输入描述:
每组测试用例包含n组数据，每组数据为两个正整数 x , k。 满足 0 < x , k ≤ 2,000,000,000。

输出描述:
输出一个数y。

示例1
输入
  2
  5 1
  4 2
输出
  2
  2

牛客题解： 
https://www.nowcoder.com/questionTerminal/729f5e6e2acc4f3cb14a2262888f86fb
*/
#include<iostream>
#include <cstring>
#include <bitset>

using namespace std;
typedef long long LL;

LL solve(LL x, LL k){
    //x+y=x|y
    //这里可以推出一个结论，x&y=0。也就是说，在二进制上看，x取1的地方，y必定不能取1。
	//从最低位考虑，若x与y在某一位上同时取1，则x+y在该位上为0，x|y在该位上为1，
	//前面说这是最低一位x y同时取1，也就是说没有更低位加法的进位，所以这里两个结果不相等，出现了矛盾。
    //结论：x在二进制取1的位上，y不能做出改变，只能取0 
    //可以进一步推出只要在x取0的地方，y可以做出改变
	LL num = 1, res = 0;
    //目标是把k的各位依次填在x中是0的位上
    //bitNum用来移动到x中零的位置，然后把k的最低位放在x的零位上, k左移，
	//将下一位变成最低位,bitNum一直左移，知道x中的下一个为0的位上。 
    while(k){
        if((x & num) == 0){//x中当前位置为0的话,把k的最低位放在这儿
            //k&1是将k的最低位取出来, bitNum*(k&1)的结果就是得到num位和当前k的最低位一样的一个数,而其它位都是0 
            res += (num * (k & 1));
            //而ans原来的num肯定为0，ans+(num*(k&1)) 就将k的最低位放在x的这个零上了。
            k >>= 1;
        }
        num <<= 1;//bitNum的1一直左移到x中第k个零的位置
    }

	return res;
}

LL solve1(LL x, LL k){ 
    //算法大概是，将 x 和 k 都转成二进制串， 
	//然后将 k 的二进制串依次塞进 x 串中为 0 的部位，得到的一个新值，
    //把这个值中原先 x 为 1 的 位 都给改成 0，就能得到 y 值。

    //比如 k = 3 = b(1 1), x = 5 = b(0101)
    //第一步将 k 塞入 x， 得到 b(1111)， 第二步将原先 x 中为 1 的变成 0,得到 b(1010),即 y = 10
	
    std::bitset<64> xbs(x), kbs(k);//将整数转换成二进制数 
 
    for (size_t i = 0, kpos = 0; i < xbs.size(); ++i) {
        if (! xbs.test(i)) { // xbs[i] == 0
            xbs.set(i, kbs[kpos++]);
        }
    }
 
    unsigned long long y = xbs.to_ullong();
    y ^= x; //将有和x异或，使原来x为1的位置变为0 
    
    return y;
}



int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		LL x, k;
		cin>>x>>k;
		LL result = solve(x, k);
		LL result1 = solve1(x, k);
		cout<<result<<endl;
		cout<<result1<<endl;
	}
	return 0;
} 

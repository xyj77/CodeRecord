#include<stdio.h>
//找出n个数中两个出现两次的数 ，其他数字均只出现一次 
void find_duplicates(int* num, int start, int end){
    int size = end-start+1;
    int bit_flag = 0;
    int i=0;
    for(i=0; i<size; i++){
        bit_flag ^= num[i];
    }

    for(i=1; i<size-1; i++){
        bit_flag ^= i;
    }
    //根据bit_flag二进制中最右边的1将数组中的整数划分成两个部分
    int division_bit = bit_flag & ~(bit_flag-1);//从右往左第一个为1的位是1，其它位是0 

    int a = 0;//部分I的xor结果
    int b = 0;//部分II的xor结果
    for(i=0; i<size; i++){
        if(num[i] & division_bit)
            a ^= num[i];
        else
            b ^= num[i]; 
    }
    for(i=1; i<size-1; i++){
        if(i & division_bit)
            a ^= i;
        else
            b ^= i;
    }
    printf("duplicate numbers a=%d \t b=%d\n", a, b);
}

void main(){

    int A[]={5,2,4,3,1,3,2};
    find_duplicates(A, 0, 6);
}

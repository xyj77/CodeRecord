#include<stdio.h>
//�ҳ�n�����������������ε��� ���������־�ֻ����һ�� 
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
    //����bit_flag�����������ұߵ�1�������е��������ֳ���������
    int division_bit = bit_flag & ~(bit_flag-1);//���������һ��Ϊ1��λ��1������λ��0 

    int a = 0;//����I��xor���
    int b = 0;//����II��xor���
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

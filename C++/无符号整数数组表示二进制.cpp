/* 
��Ϸ�����кܶ���ָ���������������һ���������ֻ����һ�Σ���������һ����1024����
����ID��Χ[1,1024].����32��unsigned int��������¼��1024�������Ƿ��Ѿ���ɡ���ʼ״̬Ϊδ��ɡ�
����������������������ID����Ҫ���õ�һ��ID������Ϊ�Ѿ���ɣ������ڶ���ID�������Ƿ��Ѿ���ɡ�
���һ������������ڶ���ID�������Ѿ�������1�����δ������0,�������һ��ڶ���ID����[1,1024]��Χ�������1.
�磺
���룺1024 1024
�����1
*/ 
//ÿ��unsigned int ��32λ��unsigned int target[32]�Ϳɱ�ʾ 32*32������ID��״̬��
#include<iostream>
using namespace std;
 
int main(){
    unsigned int target[32] = {0};
    int ID1, ID2;
    cin>>ID1>>ID2;
    if(ID1<1||ID1>1024||ID2<1||ID2>1024){
        cout<<-1<<endl;
        return 0;
    }
    int groupID = ID1/32;
    int indexID = ID1%32;
    int marktmp = 1<<indexID;
    target[groupID] = target[groupID]|marktmp;
 
    groupID = ID2/32;
    indexID = ID2%32;
    marktmp = 1<<indexID;
 
    if(marktmp & target[groupID]) cout<<1<<endl;
    else cout<<0<<endl;
 
    return 0;
}

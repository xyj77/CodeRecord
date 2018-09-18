/* 
游戏里面有很多各种各样的任务，其中有一种任务玩家只能做一次，这类任务一共有1024个，
任务ID范围[1,1024].请用32个unsigned int类型来记录着1024个任务是否已经完成。初始状态为未完成。
输入两个参数，都是任务ID，需要设置第一个ID的任务为已经完成；并检查第二个ID的任务是否已经完成。
输出一个参数，如果第二个ID的任务已经完成输出1，如果未完成输出0,。如果第一或第二个ID不在[1,1024]范围，则输出1.
如：
输入：1024 1024
输出：1
*/ 
//每个unsigned int 有32位，unsigned int target[32]就可表示 32*32个任务ID的状态。
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

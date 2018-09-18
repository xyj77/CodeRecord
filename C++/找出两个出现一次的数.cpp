#include<iostream>
#include<vector>
using namespace std;
//�ҳ�����������ֻ����һ�ε����֣��������־�ֻ�������� 
vector<int> FindTwoOnce(vector<int> num){
    if(num.size()<=2)               //�Է���Ҫ���num���飬ֻ������Ԫ����ֱ�ӷ���
        return num;
    int res=0;                      //�洢��������Ԫ�����Ľ��
    for(int i=0;i<num.size();i++){
        res ^= num[i];
    }
    int index=0;                    //�洢����������Ʊ�ʾ�У����������һ��Ϊ1���±�
    for(int i=0;i<32;i++){
        int temp=res;
        if((temp>>i) & 1 == 1){     //��iλΪ1
            index=i;
            break;
        }
    }
    vector<int> result;             //�洢������������
    result.push_back(0);
    result.push_back(0);
    for(int i=0;i<num.size();i++){
        if((num[i]>>index) & 1 == 1)//��iλ��1��һ��
            result[0] ^= num[i];
        else                        //��iλ��0��һ��
            result[1] ^= num[i];
    }
    return result;
}
 
int main(){
    vector<int> num;
    num.push_back(2);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    num.push_back(5);
    num.push_back(5);
    vector<int> result=FindTwoOnce(num);
    cout<<result[0]<<' '<<result[1]<<endl;
    return 0;
}


#include<iostream>
using namespace std;

struct node{
    int val;
    struct node* next;
    node(int x) :val(x){}
};
/***�ǵݹ鷽ʽ***/
node* reverseList(node* H){
    if (H == NULL || H->next == NULL) //����Ϊ�ջ��߽�1����ֱ�ӷ���
        return H;
    node* p = H, *newH = NULL;
    while (p != NULL)                 //һֱ��������β
    {
        node* tmp = p->next;          //�ݴ�p��һ����ַ����ֹ�仯ָ��ָ����Ҳ�����������
        p->next = newH;               //p->nextָ��ǰһ���ռ�
        newH = p;                     //��������ͷ�ƶ���p������һ������
        p    = tmp;                   //pָ��ԭʼ����pָ�����һ���ռ�
    }
    return newH;
}
/***�ݹ鷽ʽ***/
node* In_reverseList(node* H){
    if (H == NULL || H->next == NULL)       //����Ϊ��ֱ�ӷ��أ���H->nextΪ���ǵݹ��
        return H;
    node* newHead = In_reverseList(H->next); //һֱѭ������β 
    H->next->next = H;                       //��ת������ָ��
    H->next = NULL;                          //�ǵø�ֵNULL����ֹ��������
    return newHead;                          //������ͷ��Զָ�����ԭ��������β
}
void printList(node* H){  //��ӡ���� 
	if(H == NULL) return;
	node* p=H;
	while(p){
		cout<<p->val<<" -> ";
		p=p->next;
	}
	cout<<"NULL"<<endl;
} 
int main(){
    node* first = new node(1);
    node* second = new node(2);
    node* third = new node(3);
    node* forth = new node(4);
    node* fifth = new node(5);
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = NULL;
    printList(first);
    
    //�ǵݹ�ʵ��
    node* H1 = first;
    H1 = reverseList(H1);    //��ת
    
    printList(H1);
    //�ݹ�ʵ��
    node* H2 = H1;
    H2 = In_reverseList(H2); //�ٷ�ת
    printList(H2);

    return 0;
}
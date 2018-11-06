#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>

using namespace std;

void convertTreeCore(BTNode *pNode, BTNode **pLastInList){
    if (!pNode){
        //���ݷǷ���
        return;
    }
    BTNode *pc = pNode;

    if (pNode->left){
        convertTreeCore(pNode->left,pLastInList);
    }
    pc->left = *pLastInList;//��֮ǰ������ҵ���ǰ�Ķ������ڵ�
    if (*pLastInList){//˵����ǰ�������ǿ���������ǰ�������ڵ�ҵ�˫������ĺ���
        (*pLastInList)->right = pc;
    }
    *pLastInList = pc;//˫�������βָ����ƣ�ָ��ǰ�����β�ڵ�
    if (pNode->right){
        convertTreeCore(pNode->right, pLastInList);
    }
}
BTNode* convertTree(BTNode *root){
    BTNode *pLastInList = NULL;
    convertTreeCore(root, &pLastInList);
    //ִ�������溯����pLastInListָ��ǰ�����β�ڵ�
    BTNode *head = pLastInList;
    while (head != NULL&&head->left){//�ж�head�Ƿ�Ϊ�յ�Ŀ�������жϴ����Ԫ�صڷ�Ϸ�
        head = head->left;
    }
    return head;

}

//����������Ľڵ�
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}BTNode;

//��������������
BTNode* creatBinSortTree(int data[], int len){
    BTNode *root = NULL, *p = NULL, *pa = NULL, *c = NULL;
    for (int i = 0; i < len; i++){
        //Ϊ�µĽڵ���䵥Ԫ
        p = (BTNode*)malloc(sizeof(BTNode));
        p->data = data[i];
        p->left = p->right = NULL;
        if (!root){
            root = p;
        }
        else{
            c = root;
            while (c){
                pa = c;
                if (c->data < p->data){
                    c = c->right;
                }
                else{
                    c = c->left;
                }
            }
            if (pa->data < p->data){
                pa->right = p;
            }
            else{
                pa->left = p;
            }
        }
    }
    return root;
}
//�������������
void inOrder(BTNode *root){
    if (root){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
//��ӡ˫������
void printLink(BTNode *head){
    for (BTNode *p = head; p; p = p->right){
        printf("%d ",p->data);
    }
}
//������
int main(void){
    int data[8] = { 3, 2, 5, 8, 4, 7, 6, 9 };
    BTNode *root = creatBinSortTree(data, 8);
    //�������������
    inOrder(root);
    printf("\n");
    BTNode *head = convertTree(root);
    //��ӡ˫������
    printLink(head);
    system("pause");
    return 0;
}

#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>

using namespace std;

void convertTreeCore(BTNode *pNode, BTNode **pLastInList){
    if (!pNode){
        //数据非法，
        return;
    }
    BTNode *pc = pNode;

    if (pNode->left){
        convertTreeCore(pNode->left,pLastInList);
    }
    pc->left = *pLastInList;//将之前的链表挂到当前的二叉树节点
    if (*pLastInList){//说明当前的链表不是空链表，将当前二叉树节点挂到双向链表的后面
        (*pLastInList)->right = pc;
    }
    *pLastInList = pc;//双向链表的尾指针后移，指向当前链表的尾节点
    if (pNode->right){
        convertTreeCore(pNode->right, pLastInList);
    }
}
BTNode* convertTree(BTNode *root){
    BTNode *pLastInList = NULL;
    convertTreeCore(root, &pLastInList);
    //执行完上面函数，pLastInList指向当前链表的尾节点
    BTNode *head = pLastInList;
    while (head != NULL&&head->left){//判断head是否为空的目的是想判断传入的元素第否合法
        head = head->left;
    }
    return head;

}

//定义二叉树的节点
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}BTNode;

//创建二叉搜索树
BTNode* creatBinSortTree(int data[], int len){
    BTNode *root = NULL, *p = NULL, *pa = NULL, *c = NULL;
    for (int i = 0; i < len; i++){
        //为新的节点分配单元
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
//中序遍历二叉树
void inOrder(BTNode *root){
    if (root){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
//打印双向链表
void printLink(BTNode *head){
    for (BTNode *p = head; p; p = p->right){
        printf("%d ",p->data);
    }
}
//主函数
int main(void){
    int data[8] = { 3, 2, 5, 8, 4, 7, 6, 9 };
    BTNode *root = creatBinSortTree(data, 8);
    //中序遍历二叉树
    inOrder(root);
    printf("\n");
    BTNode *head = convertTree(root);
    //打印双向链表
    printLink(head);
    system("pause");
    return 0;
}

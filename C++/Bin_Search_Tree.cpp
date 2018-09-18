/*
�Ӷ����������в�����ӽ�ֵ������ж��������С�ģ�
ʾ���� 

��һ�У��ڵ���ĿN 
�ڶ��У�N��ֵ 
�����У�������ĿM
�����У�M�������ҵ�ֵ 

10 
32 47 91 20 59 0 1 88 74 62
10
0 1 80 81 82 58 59 60 61 20 

�����
0
1
74
74
88
59
59
59
62
20 
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cmath>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

int findClosest(TreeNode* root, int value){
    // write your code here...
    // suppose root is not NULL
    
    //�ݹ� 
    // ѡ�������ĸ��ڵ�
    TreeNode* kid = value < root->value ? root->left : root->right;
    // ���û��������Ҳ���ǵݹ鵽��ʱ��ֱ�ӷ��ص�ǰ�ڵ�ֵ
    if(kid == NULL) return root->value;
    // �ҳ�������������Ǹ��ڵ�
    int closest = findClosest(kid, value);
    // ���ظ��ڵ����������ڵ��У��������Ǹ��ڵ�
    return abs(root->value - value) < abs(closest - value) ? root->value : closest;
    
    
    /*//�ǵݹ� 
    int closest = root->value;
    while(root != NULL){
        // ����ýڵ����Ŀ�����������µ�ĿǰΪֹ�����ֵ
        closest = abs(closest - value) < abs(root->value - value) ? closest : root->value;
        // ��������
        root = value < root->value ? root->left : root->right;
    }
    return closest;
    */ 
    
}

bool BSTInsert(TreeNode*& p, int element)
{
    if (NULL == p) // ����
    {
        p = new TreeNode;
        p->value = element;
        p->left = p->right = NULL;
        return true;
    }

    if (element == p->value) // BST�в�������ȵ�ֵ
        return false;

    if (element < p->value) // �ݹ�
        return BSTInsert(p->left, element);

    return BSTInsert(p->right, element); // �ݹ�
}

bool createBST(TreeNode*& T, vector<int> values, int n)
{
    T = NULL;
    int i;
    for (i = 0; i < n; i++) {
		if(!BSTInsert(T, values[i])){
			return false;
		}
    }
	return true;
}

int main()
{
	// test and not consider free the used memory
	int n;
	cin >> n;
    vector<int> values(n, 0);
	for(int i = 0; i < n; i++){
	   cin >> values[i];
    }
    TreeNode* T;

    // �������е�a[]���ܹ����BST,���ԣ���ö�createBST�ķ���ֵ�����ж�
    if (createBST(T, values, n)) {
		int m;
		cin >> m;
		for(int i = 0; i < m; i++){
			int tmp;
			cin >> tmp;
            printf("%d\n", findClosest(T, tmp));
			// cout << findClosest(T, tmp) << endl;
		}
    }
    return 0;
}

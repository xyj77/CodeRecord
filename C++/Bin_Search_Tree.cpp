/*
从二叉搜索树中查找最接近值，如果有多个返回最小的：
示例： 

第一行：节点数目N 
第二行：N个值 
第三行：搜索数目M
第四行：M个待查找的值 

10 
32 47 91 20 59 0 1 88 74 62
10
0 1 80 81 82 58 59 60 61 20 

结果：
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
    
    //递归 
    // 选出子树的根节点
    TreeNode* kid = value < root->value ? root->left : root->right;
    // 如果没有子树，也就是递归到底时，直接返回当前节点值
    if(kid == NULL) return root->value;
    // 找出子树中最近的那个节点
    int closest = findClosest(kid, value);
    // 返回根节点和子树最近节点中，更近的那个节点
    return abs(root->value - value) < abs(closest - value) ? root->value : closest;
    
    
    /*//非递归 
    int closest = root->value;
    while(root != NULL){
        // 如果该节点的离目标更近，则更新到目前为止的最近值
        closest = abs(closest - value) < abs(root->value - value) ? closest : root->value;
        // 二叉搜索
        root = value < root->value ? root->left : root->right;
    }
    return closest;
    */ 
    
}

bool BSTInsert(TreeNode*& p, int element)
{
    if (NULL == p) // 空树
    {
        p = new TreeNode;
        p->value = element;
        p->left = p->right = NULL;
        return true;
    }

    if (element == p->value) // BST中不能有相等的值
        return false;

    if (element < p->value) // 递归
        return BSTInsert(p->left, element);

    return BSTInsert(p->right, element); // 递归
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

    // 并非所有的a[]都能构造出BST,所以，最好对createBST的返回值进行判断
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

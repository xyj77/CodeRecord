// 求数组的最大连续子序列和
#include <iostream> 
using namespace std;
int MaxSubsequenceSum1(int a[], int n);
int MaxSubsequenceSum2(int a[], int n);
int MaxSubsequenceSum3(int a[], int n);
static int MaxSubSum(int a[], int, int);
int MaxSubsequenceSum4(int a[], int n);

int main(){
    int a[6] = { -2,11,-4,13,-5,-2 };
    cout<<"Alg1:"<<MaxSubsequenceSum1(a, 6)<<endl;
    cout<<"Alg2:"<<MaxSubsequenceSum2(a, 6)<<endl;
    cout<<"Alg3:"<<MaxSubsequenceSum3(a, 6)<<endl;
    cout<<"Alg4:"<<MaxSubsequenceSum4(a, 6)<<endl;
    return 0;
}

//算法1：时间复杂度O(n3)--暴力遍历
int MaxSubsequenceSum1(int a[],int n) {
    int thisSum, maxSum, i, j, k;
    maxSum = 0;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            thisSum = 0;
            for (k = i; k < j; k++) {
                thisSum += a[k];
            }
            if (thisSum>maxSum)
            {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

//算法2：时间复杂度O(n2)--暴力遍历
int MaxSubsequenceSum2(int a[], int n) {
    int thisSum, maxSum, i, j;
    maxSum = 0;
    for (i = 0; i < n; i++) {
        thisSum = 0;
        for ( j = i; j < n; j++){
            thisSum += a[j];
            if (thisSum>maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

//算法3：时间复杂度为O(nlogn)--递归 分治(divide-and-conquer)
int MaxSubsequenceSum3(int a[], int n) {
    return MaxSubSum(a, 0, n - 1);
}

static int MaxSubSum(int a[], int left, int right) {
    int maxLeftSum, maxRightSum;
    int maxLeftBorderSum, maxRightBorderSum;
    int leftBorderSum, rightBorderSum;
    int center, i;

    if (left == right) {
        if (a[left]>0){
            return a[left];
        }
        else {
            return 0;
        }
    }

    center = (left + right) / 2;
    maxLeftSum = MaxSubSum(a, left, center);
    maxRightSum = MaxSubSum(a, center + 1, right);

    maxLeftBorderSum = 0;
    leftBorderSum = 0;
    for ( i = center; i >=left ; i--)
    {
        leftBorderSum += a[i];
        if (leftBorderSum > maxLeftBorderSum) {
            maxLeftBorderSum = leftBorderSum;
        }
    }

    maxRightBorderSum = 0;
    rightBorderSum = 0;
    for ( i = center+1; i < right; i++)
    {
        rightBorderSum += a[i];
        if (rightBorderSum > maxRightBorderSum) {
            maxRightBorderSum = rightBorderSum;
        }
    }

    //max(maxLeftSum,maxRightSum,maxLeftBorderSum+maxRightBorderSum)
    return (maxLeftSum > maxRightSum ? maxLeftSum : maxRightSum) > (maxLeftBorderSum + maxRightBorderSum) ?
        (maxLeftSum > maxRightSum ? maxLeftSum : maxRightSum) : (maxLeftBorderSum + maxRightBorderSum);
}

//算法4：时间复杂度为O(n)--几乎是完美的算法（需要常量空间并以线性时间运行的联机算法）
//联机算法，在任意时刻都能对他已经读入的数据给出子序列问题的正确答案
int MaxSubsequenceSum4(int a[], int n) {
    int thisSum, maxSum, i;
    thisSum = maxSum = 0;
    for ( i = 0; i < n; i++){
        thisSum += a[i];
        if (thisSum > maxSum) {
            maxSum = thisSum;
        }
        else if (thisSum < 0) {
            thisSum = 0;//负数在求和中永远是累赘，出现负数即跳过，置零重新开始
        }
    }
    return maxSum;
}

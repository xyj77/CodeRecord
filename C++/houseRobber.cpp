/*https://blog.csdn.net/lis_12/article/details/55187884
题目描述

假设你是一个专业的窃贼，准备沿着一条街打劫房屋。每个房子都存放着特定金额的钱。你面临的唯一约束条件是：
相邻的房子装着相互联系的防盗系统，且 当相邻的两个房子同一天被打劫时，该系统会自动报警。

给定一个非负整数列表，表示每个房子中存放的钱， 算一算，如果今晚去打劫，在不触动报警装置的情况下， 
你最多可以得到多少钱。

分析： 

在数组中取出一个或多个不相邻数，使其和最大，即找到max(不相邻元素组成的子数组)

解决方法 = 动态规划 

状态转移方程：dp[n] = max(dp[n - 2] + a[n] , dp[n - 1])

*/

long long houseRobber(vector<int> nums) {
  int size = nums.size();
  if (size == 0) {
    return 0;
  }
  if (size == 1) {
    return nums[0];
  }
  if (size == 2) {
    return nums[0] > nums[1] ? nums[0]:nums[1];
  }
  long long n1 = nums[0];
  long long n2 = n1 > nums[1] ? n1:nums[1];
  long long n3, n4;
  for (int i = 2; i < size; i++) {
    n3 = n1 + nums[i];
    n4 = n3 > n2 ? n3:n2;
    n1 = n2;
    n2 = n4;
  }
  return n1 > n2 ? n1:n2;
}

/*https://blog.csdn.net/lis_12/article/details/55187884
��Ŀ����

��������һ��רҵ��������׼������һ���ִ�ٷ��ݡ�ÿ�����Ӷ�������ض�����Ǯ�������ٵ�ΨһԼ�������ǣ�
���ڵķ���װ���໥��ϵ�ķ���ϵͳ���� �����ڵ���������ͬһ�챻���ʱ����ϵͳ���Զ�������

����һ���Ǹ������б���ʾÿ�������д�ŵ�Ǯ�� ��һ�㣬�������ȥ��٣��ڲ���������װ�õ�����£� 
�������Եõ�����Ǯ��

������ 

��������ȡ��һ����������������ʹ�����󣬼��ҵ�max(������Ԫ����ɵ�������)

������� = ��̬�滮 

״̬ת�Ʒ��̣�dp[n] = max(dp[n - 2] + a[n] , dp[n - 1])

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

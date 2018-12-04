/*ԭ�ģ�https://blog.csdn.net/laojiu_/article/details/62217217 */
#include<iostream>
using namespace std;

//����һ����������飬����value�Ƿ��������У������ڷ���-1
int BinarySearch(int array[], int n, int value)
{
    int left = 0;
    int right = n - 1;
    //���������int right = n �Ļ�����ô�����������ط���Ҫ�޸ģ��Ա�֤һһ��Ӧ��
    //1������ѭ������������while(left < right)
    //2��ѭ���ڵ� array[middle] > value ��ʱ��right = mid

    while (left <= right)  //ѭ����������ʱ����
    {
        int middle = left + ((right - left) >> 1);  //��ֹ�������λҲ����Ч��ͬʱ��ÿ��ѭ������Ҫ���¡�
        if (array[middle] > value)
            right = middle - 1;  //right��ֵ����ʱ����
        else if (array[middle] < value)
            left = middle + 1;
        else
            return middle;
        //���ܻ��ж�����Ϊ�տ�ʼʱ��Ҫ�ж���ȣ����Ͼ������в���ȵ��������
        //���ÿ��ѭ�����ж�һ���Ƿ���ȣ����ķ�ʱ��
    }
    return -1;
}

//����һ����������飬����value��һ�γ��ֵ��±꣬�����ڷ���-1
int BinarySearch(int array[], int n, int value)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)  
    {
        int middle = left + ((right - left) >> 1);
        if (array[middle] >= value)  //��Ϊ���ҵ���С�ĵ�ֵ�±꣬���Ե��ںŷ�������
            right = middle - 1;
        else
            left = middle + 1;
    }
    return array[right + 1] == value ? right + 1 : -1;
}
//��������Ϊ����value���һ�γ��ֵ��±��أ�ֻ��Ķ�����λ�ã� 
//1.if (array[middle] >= value)�еĵȺ�ȥ���� 
//2.return��right+1��Ϊleft-1


//����һ����������飬������ӽ�value�Ҵ���value�������±꣨����������ڶ�������ص�һ���±꣩�������ڷ���-1
int BinarySearch(int array[], int n, int value)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)  
    {
        int middle = left + ((right - left) >> 1);
        if (array[middle] > value)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return array[right + 1] > value ? right + 1 : -1;
}
//��������Ϊ������ӽ�value��С��value�������±꣨����������ڶ�����������һ���±꣩�أ�ֻ��Ķ�����λ�ã� 
//1.if (array[middle] > value)����һ���Ⱥţ� 
//2.return array[right + 1] > value ? right + 1 : -1;��Ϊreturn array[left-1] < value ? left - 1 : -1;





/*
���գ�Zeller����ʽ����һ���������ڵĹ�ʽ������һ�����ڣ������������ʽ����������ڼ�
���չ�ʽֻ�ʺ���1582�꣨�й���������ʮ�꣩10��15��֮������Ρ�
����̻ʸ������ʮ������1582����֯��һ������ѧ�ң����ݸ��������˵������������ݣ��������������޸ġ�
��1582��10��5�յ�14��֮���10��������������10��4��֮��Ϊ10��15�ա�
�������ǽ���һ�µ�������Ϊ���������������Ҳ���ǽ�����������ͨ�õ���������Ƹ�����������

1582��10��4�պ�
    w=y+[y/4]+[c/4]-2c+[26(m+1��/10]+d-1
    w = w MOD 7 ���wΪ�������� w = (w%7 +7) % 7
	 
���У�
w�����ڣ� w��7ȡģ�ã�0-�����գ�1-����һ��2-���ڶ���3-��������4-�����ģ�5-�����壬6-������
c�����ͣ�ע���ڹ�ʽ��ȡֵΪ�Ѿ�������������Ҳ������ݳ���һ�ٵĽ�������������ڽ��е����ͣ�����Ҫ��1��
y���꣨����λ����
m���£�m���ڵ���3��С�ڵ���14�����ڲ��չ�ʽ�У�ĳ���1��2��Ҫ������һ���13��14�������㣬����2003��1��1��Ҫ����2002���13��1�������㣩
d����
[ ]����ȡ������ֻҪ�������֡�

*/


 
// C++ 
#include<iostream>
using namespace std;
int main(){
	int year,month,day;
	while(cin>>year>>month>>day){
		if(month<3){
		    year-=1;
		    month+=12;
	    }
		char b[7][10]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
		int c = int(year/100), y = year-100*c;
		int w = int(c/4)- 2*c + y + int(y/4) + (26*(month+1)/10) + day - 1;
		w = (w%7+7) % 7;
		cout<<b[w]<<endl;
	}
	return 0;
}



/*
// C���� 
#include<stdio.h>
int main()
{
	int year,month,day;
	while(scanf("%d%d%d",&year,&month,&day)!=EOF)
	{
	    if(month==1||month==2)//�ж�month�Ƿ�Ϊ1��2��
		{
		    year--;
		    month+=12;
		}
		int c=year/100;
		int y=year-c*100;
		int week=(c/4)-2*c+(y+y/4)+(13*(month+1)/5)+day-1;
		week = (week%7+7) % 7;
		switch(week)
		{
			case 1:printf("Monday\n");break;
			case 2:printf("Tuesday\n");break;
			case 3:printf("Wednesday\n");break;
			case 4:printf("Thursday\n");break;
			case 5:printf("Friday\n");break;
			case 6:printf("Saturday\n");break;
			case 0:printf("Sunday\n");break;
	    }
    }
    return 0;
}
*/


/*
// ������ʽ
#include <iostream>
using namespace std;
int CaculateWeekDay(int y,int m,int d)
{
	if(m==1) m=13,y--;
	if(m==2) m=14,y--;
	// w = (d + 2m+ 3*(m+1)/5 + y + y/4 - y/100 + y/100) MOD 7 
	int week=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
	return week;
}
int main()
{
    int y,m,d;
    while(cin>>y>>m>>d){
    	int week=CaculateWeekDay(y,m,d);
    	// ���ּ��㷽ʽ 0��Ӧ����һ��6��Ӧ������ 
        char w[7][10]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"}; 
        cout<<w[week]<<endl;
    }
    return 0;
} 

*/

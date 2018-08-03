/*
蔡勒（Zeller）公式，是一个计算星期的公式，随便给一个日期，就能用这个公式推算出是星期几
蔡勒公式只适合于1582年（中国明朝万历十年）10月15日之后的情形。
罗马教皇格里高利十三世在1582年组织了一批天文学家，根据哥白尼日心说计算出来的数据，对儒略历作了修改。
将1582年10月5日到14日之间的10天宣布撤销，继10月4日之后为10月15日。
后来人们将这一新的历法称为“格里高利历”，也就是今天世界上所通用的历法，简称格里历或公历。

1582年10月4日后：
    w=y+[y/4]+[c/4]-2c+[26(m+1）/10]+d-1
    w = w MOD 7 如果w为负数，则 w = (w%7 +7) % 7
	 
其中：
w：星期； w对7取模得：0-星期日，1-星期一，2-星期二，3-星期三，4-星期四，5-星期五，6-星期六
c：世纪（注：在公式中取值为已经过的世纪数，也就是年份除以一百的结果，而不是正在进行的世纪，不需要加1）
y：年（后两位数）
m：月（m大于等于3，小于等于14，即在蔡勒公式中，某年的1、2月要看作上一年的13、14月来计算，比如2003年1月1日要看作2002年的13月1日来计算）
d：日
[ ]代表取整，即只要整数部分。

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
// C语言 
#include<stdio.h>
int main()
{
	int year,month,day;
	while(scanf("%d%d%d",&year,&month,&day)!=EOF)
	{
	    if(month==1||month==2)//判断month是否为1或2　
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
// 其他公式
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
    	// 这种计算方式 0对应星期一，6对应星期日 
        char w[7][10]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"}; 
        cout<<w[week]<<endl;
    }
    return 0;
} 

*/

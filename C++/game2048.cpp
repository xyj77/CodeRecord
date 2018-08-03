// C++2048游戏 
#include <iostream>
#include <stdlib.h>
#include "time.h"
using namespace std;
int a[5][5],b[5],c[5][5],d[5][5],i,j,k,m,n,score,tem[5][5];
char x;
bool is[5][5];
void renew();
void choose();
void store();
void out()
{
	system("cls");
	cout<<endl<<"score="<<score<<endl;
	cout<<"__________________________"<<endl;
	for (i=1;i<=4;i++)
	{
		for (j=1;j<=4;j++)
		{
			if (a[i][j]!=0) cout<<a[i][j]<<'\t';
			if (a[i][j]==0) cout<<'\t';
		}
		cout<<endl<<endl;
	}
	cout<<"__________________________"<<endl<<endl;
	cout<<"****************************"<<endl;
	cout<<"键盘wsad键分别代表上下左右"<<endl; 
	cout<<"****************************"<<endl; 
}


//输出
 
void process()
{
	store();
	for (i=1;i<=4;i++)
	{
		for (j=1;j<=4;j++)
		{
			if (a[i][j]!=0)
			{
				b[i]++;				
				c[i][b[i]]=a[i][j];
			}
		}
	}

	for (i=1;i<=4;i++)
	{
		for (j=1;j<=4;j++)
		{
			if (j<=b[i])	a[i][j]=c[i][j];
			else a[i][j]=0;
		}
	}
	
	//把每个数全部靠在一边 
		bool kkk=false;
	for (i=1;i<=4;i++)
	{
		for (j=1;j<=3;j++)
		{
			if (a[i][j]==a[i][j+1]&&a[i][j]!=0)
			{
				a[i][j]=2*a[i][j];
				a[i][j+1]=0;
				score=score+a[i][j];
				kkk=true;
			}
		}
	}
	
	//相加 
	renew();

		for (i=1;i<=4;i++)
	{
		for (j=1;j<=4;j++)
		{
			if (a[i][j]!=0)
			{
				b[i]++;				
				c[i][b[i]]=a[i][j];

			}
		}
	}
	for (i=1;i<=4;i++)
	{
		for (j=1;j<=4;j++)
		{
			if (j<=b[i])	a[i][j]=c[i][j];
			else a[i][j]=0;
		}
	}
	//靠边 
	renew();
	choose();
}
void turn()
{
	int pop[5][5];
	for (i=1;i<=4;i++)
	{
		for (j=1;j<=4;j++)
		{
			pop[i][j]=a[i][j];
		}
	}
	a[1][1]=pop[4][1];
	a[1][2]=pop[3][1];
	a[1][3]=pop[2][1];
	a[1][4]=pop[1][1];
	a[2][1]=pop[4][2];
	a[2][2]=pop[3][2];
	a[2][3]=pop[2][2];
	a[2][4]=pop[1][2];
	a[3][1]=pop[4][3];
	a[3][2]=pop[3][3];
	a[3][3]=pop[2][3];
	a[3][4]=pop[1][3];
	a[4][1]=pop[4][4];
	a[4][2]=pop[3][4];
	a[4][3]=pop[2][4];
	a[4][4]=pop[1][4];
}

void store()
{
	for (i=1;i<=4;i++)
	{
		for (j=1;i<=4;i++) 
		tem[i][j]=a[i][j];
	}
}


void choose()
{
	int nonumber=0;
	int appear1=0,appear2=0; 
	for (i=1;i<=4;i++)
	{
		for (j=1;j<=4;j++)
		{
			if (a[i][j]==0) nonumber++;
		}
	}

	srand((unsigned int)time(NULL));
	appear1=rand()%4+1;
	appear2=rand()%nonumber+1;
	if (appear1>=1&&appear1<=3) appear1=2;
	int number=0;
	for (i=1;i<=4;i++)
	{
		for (j=1;j<=4;j++)
		{
			if (a[i][j]==0) number++;
			if (number==appear2&&a[i][j]==0)
			{
				a[i][j]=appear1;
				break;
			}
		}
	}
} 

void renew()
{
	for (i=0;i<=4;i++)
	{
		for (j=0;j<=4;j++)
		{
			b[i]=0;
			c[i][j]=0;
		}
	}
}
int main()
{
	//for (i=1;i<=5;i++) b[i]=1;
	srand((unsigned int)time(NULL));
	n=rand()%16+1;
	a[n/4+1][n%4]=2;
 	out();
    while (1)
    {
    	cout<<"请输入方向：";
    	cin>>x;
    	if (x=='a')
    		process();
    	
    	if (x=='s')
		{
		 	turn();
		 	process();
		 	turn();
		 	turn();
		 	turn();
		}
		if (x=='d')
		{
			turn();
			turn();
			process();
			turn();
			turn();
		} 
		if (x=='w')
		{
			turn();
			turn();
			turn();
			process();
			turn();
		}
    	out();
    }
}

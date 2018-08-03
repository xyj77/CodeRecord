#include<stdio.h>
#include<stdlib.h>
int main()
{
    system("color fc"); 
    for(double y=2.1;y>=-1.5;y=y-0.2)
	{
	    for(double x=-1.8;x<=2;x=x+0.09)
		    ((x*x+y*y-1)*(x*x+y*y-1)*(x*x+y*y-1)<=3.6*x*x*y*y*y)?printf("*"):printf(" ");
	    printf("\n");
    }
	getchar();getchar();
	return 0; 
}


/*
���⣺
1.����<br>����
2.����<hr>�����-��
3.ÿһ�еļ������ڵĵ���������ȳ���80���У�ÿ������ǰ��һ���ո�
4.����ʱҪ�������

���룺
Hallo, dies ist eine 
ziemlich lange Zeile, die in Html
aber nicht umgebrochen wird.
<br>
Zwei <br> <br> produzieren zwei Newlines. 
Es gibt auch noch das tag <hr> was einen Trenner darstellt.
Zwei <hr> <hr> produzieren zwei Horizontal Rulers.
Achtung       mehrere Leerzeichen irritieren

Html genauso wenig wie


mehrere Leerzeilen.

�����
Hallo, dies ist eine ziemlich lange Zeile, die in Html aber nicht umgebrochen
wird.
Zwei

produzieren zwei Newlines. Es gibt auch noch das tag
--------------------------------------------------------------------------------
was einen Trenner darstellt. Zwei
--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
produzieren zwei Horizontal Rulers. Achtung mehrere Leerzeichen irritieren Html
genauso wenig wie mehrere Leerzeilen.

*/
#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
char c[1000];
int main(){
    string s;
    int index=0;
    while(scanf("%s",&c)!=EOF){
       if(!strcmp(c,"<br>")){
            index=0;
            printf("\n");
       }else if(!strcmp(c,"<hr>")){
           if(index){
             printf("\n--------------------------------------------------------------------------------\n");
           }else{
             printf("--------------------------------------------------------------------------------\n");
           }
           index=0;
       }else{
            int i=strlen(c);
            if(!index){
                index=i;
                printf("%s",c);
            }else if(index+i+1>80){
                index=i;
                printf("\n%s",c);
            }else{
                index+=i+1;
                printf(" %s",c);
            }
       }
    }
    printf("\n");
}


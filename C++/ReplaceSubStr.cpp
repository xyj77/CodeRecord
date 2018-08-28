/*
C语言实现string的替换子串功能。 
*/
#include<string.h>
#include<stdio.h>
 
void ReplaceSubstr(char * cp, int n, char * str){
	int lenofstr;
	int i;
	char * tmp;
	lenofstr = strlen(str); 
	if(lenofstr < n){
		tmp = cp+n;
		while(*tmp){
			*(tmp-(n-lenofstr)) = *tmp;
			tmp++;
		}
		*(tmp-(n-lenofstr)) = *tmp;
	}
	else if(lenofstr > n){
		tmp = cp;
		while(*tmp) tmp++;
		while(tmp>=cp+n){
			*(tmp+(lenofstr-n)) = *tmp;
			tmp--;
		}   
	}
	strncpy(cp,str,lenofstr);
}
 
int main(){
   	char str1[1024]; 
	char str2[1024],str3[1024];	 
   	char *p;  	
   	
   	gets(str1);//获取带空格的输入 
   	gets(str2);
    gets(str3);
	
   	p = strstr(str1,str2);
   	while(p){
		ReplaceSubstr(p,strlen(str2),str3);
		p = p+strlen(str3);
		p = strstr(p,str2);
	}   	
	printf("%s\n",str1); 
	return 0;       
}


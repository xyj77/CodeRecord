#include <stdio.h>  
/**
��쳲��������е�n�� 
*/
int FibonacciNum(int n){  
    if(n < 0){  
        return -1;  
    }  
    if(n == 0){  
        return 0;  
    }else if(n == 1){  
        return 1;  
    }else {  
        return(FibonacciNum(n-1) + FibonacciNum(n-2));  
    }  
}  
  
int main(){  
    int num;  
    if(scanf("%d", &num)){  
        if((num >= 0) && (num <= 50)){  
            printf("%d", FibonacciNum(num));  
        }else{  
            printf("error!");  
            return 0;  
        }  
    }else{  
        printf("error!");  
        return 0;  
    }  
      
    return 0;  
}  
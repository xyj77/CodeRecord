/* //方法一： 
#include<iostream>
using namespace std;
class Singleton{
	private:
		static int st; 
		Singleton(){
			cout<<"Create Instance!"<<endl;
		}

	public:
		static Singleton* getInstance(){
			static Singleton instance;
			return &instance;
		}
		
		int test(){
		    return ++st;
		}
};

int Singleton::st = 0;//private 静态变量允许在全局初始化,只有这种情况下可以在类外访问私有变量，但仅限初始化时 

int main(){
	//int Singleton::st = 0; //出错，private静态变量不可在类外访问 
	//Singleton ins;//报错，已经将构造函数声明为private，只能通过getInstance途径获取实例 

	Singleton *singletonObj = Singleton::getInstance();
	cout<<singletonObj->test()<<endl;
	
	singletonObj = Singleton::getInstance();
	cout<<singletonObj->test()<<endl;
	
	return 0;
} 
*/



#include<iostream>
using namespace std;
class Singleton{
	private:
		static int st; 
		static Singleton* instance;
		Singleton(){
			cout<<"Create Instance!"<<endl;
		}

	public:
		
		static Singleton* getInstance(){
			if(instance == NULL){
				instance = new Singleton();
			}
			return instance;
		}
		
		int test(){
		    return ++st;
		}
};

int Singleton::st = 0;//private 静态变量允许在全局初始化,只有这种情况下可以在类外访问私有变量，但仅限初始化时 
Singleton* Singleton::instance = NULL; //第二种单例模式，初始化 

int main(){
	//int Singleton::st = 0; //出错，private静态变量不可在类外访问 
	//Singleton ins;//报错，已经将构造函数声明为private，只能通过getInstance途径获取实例 

	Singleton *singletonObj = Singleton::getInstance();
	cout<<singletonObj->test()<<endl;
	
	singletonObj = Singleton::getInstance();
	cout<<singletonObj->test()<<endl;
	
	return 0;
} 



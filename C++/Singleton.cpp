/* //����һ�� 
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

int Singleton::st = 0;//private ��̬����������ȫ�ֳ�ʼ��,ֻ����������¿������������˽�б����������޳�ʼ��ʱ 

int main(){
	//int Singleton::st = 0; //����private��̬����������������� 
	//Singleton ins;//�����Ѿ������캯������Ϊprivate��ֻ��ͨ��getInstance;����ȡʵ�� 

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

int Singleton::st = 0;//private ��̬����������ȫ�ֳ�ʼ��,ֻ����������¿������������˽�б����������޳�ʼ��ʱ 
Singleton* Singleton::instance = NULL; //�ڶ��ֵ���ģʽ����ʼ�� 

int main(){
	//int Singleton::st = 0; //����private��̬����������������� 
	//Singleton ins;//�����Ѿ������캯������Ϊprivate��ֻ��ͨ��getInstance;����ȡʵ�� 

	Singleton *singletonObj = Singleton::getInstance();
	cout<<singletonObj->test()<<endl;
	
	singletonObj = Singleton::getInstance();
	cout<<singletonObj->test()<<endl;
	
	return 0;
} 



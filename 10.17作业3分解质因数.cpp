#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n=0,i=2,product=1,k=0,isprime=0;
	cin>>n;
	//�ж�������A���ͻ���B���� 
	if(n%4==0){//�ô��ķ�֧����ɽ�ʱ�临�Ӷȼ���һ�� 
         for(i=2;i<=sqrt(n);i=i+2){//��ʱ�临�Ӷȿ�ƽ���������й������ĳ�������к���Ҫ 
		     if(n%(i*i)==0){
			 isprime=1;
			 break;
		     }
         }
	}else{
		 for(i=3;i<=sqrt(n);i=i+2){
		     if(n%(i*i)==0){
			 isprime=1;
			 break;
	         }
	     }
	} 
	if(isprime==1){
		 cout<<"B"<<endl;
	}else{
		 cout<<"A"<<endl;
	}
	//���������ֽ��зֽ������� 
	k=n;
	for( i=2;i<=sqrt(n);i++){//��ʱ�临�Ӷȿ�ƽ���������й������ĳ�������к���Ҫ 
	     if(n%i==0){
			 cout<<i<<endl;
			 n=n/i;
		   	 product=i*product;
			 i--;
	     	}
	}
	cout<<k/product<<endl;//�������ֽ����������������� 
    return 0;

}

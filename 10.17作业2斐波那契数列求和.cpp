//д���룬������ѧ��һ����Ҫ���⡣��Ȼ�����д������������ѧ���ף����ǽ��һЩ�ض�����ѧ����ʱ��������ȫ��������ѧ�������˼������������ʣ�����д���Ĵ��������ײ�������ģ�����˵�����ѧ˼ά�������������� 
#include<iostream>
using namespace std;
//���ս�ѭ���϶�Ϊһ�ļ��ɣ��������󽵵�ʱ�临�Ӷ� 
int main(){
	int sum=2,a=1,b=1,fibonacci=0,tmp=0,n=0,c=0,d=0;
	const int p=1000000007;//��ǰ�涨��������Ҫ��Ϊ����������Ӱ�������������۶� 
	cin>>n;
	//�ų�ǰ��������ѭ�� 
	if(n==1){
		sum=1;
	}else if(n==2){
		sum=2;
	}else{
		for(int i=3;i<=n;i++){
			fibonacci=(a+b)%p;//ע��ȡ���λ����ֵ��Ҫ�ϸ��������еĹ涨  
			//������ 
			tmp=b;
			b=fibonacci;
			a=tmp;
			//�򻯴��볤�ȣ������������ 
			c=sum%p;
			d=fibonacci%p;
			if(c<=d){
				sum=(sum+fibonacci)%p;//ע��ȡ���λ����ֵ��Ҫ�ϸ��������еĹ涨 
			} else{
		    	sum=(sum-fibonacci)%p;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}

//ָ��˼�룺��������ȥ�أ�������������޶ȵĽ�ʡʱ�临�Ӷ�
//������ȥ������������һ��Ͱ������뷨���������ڣ����Ǹ�������ֵ���󣬼����ص��˷��˿ռ䣬Ҳ�˷���ʱ�� 
#include<iostream>
using namespace std;
int input[100001];
int output[100001];
//�������� 
void swap(int *a,int *b){
	int c=*b;
	*b=*a;
	*a=c;
}
//���ź��� 
void quick_sort(int *p,int n) {
    if (n<=1){
    	return;
    }
    int t=p[n-1],l=0,r=n-2;
    do{
       for (;r>=l;l++){
       	    if(p[l]>t){
       	    	break;
			}
        }
        for(;r>=l;r--){
        	if(p[r]<t){
        		break;
			}
        }
        if(r>=l){
        	swap(&p[l],&p[r]);
		}
    }while(r>=l);
    swap(&p[l],&p[n - 1]);
    quick_sort(&p[0],l);
    quick_sort(&p[l+1],n-l-1);
}
int main(){
	int N=0;//�������� 
	cin>>N;
    for(int i=0;i<N;i++){
		cin>>input[i];
	}
	quick_sort(input,N);
	int number=1;
	output[1]=input[0];//��Ϊһ���ź��˵������������� 
	for(int i=1;i<N;i++){
		//����һ��ȥ�صĹ��� 
		if(input[i]!=input[i-1]){
			number++;
			output[number]=input[i];
		}
	}
	cout<<number<<endl;
	for(int i=1;i<=number;i++){
		cout<<output[i]<<" ";
	}
	return 0; 
}

#include<iostream>
#include<cstdio>
using namespace std;
int input[10000005];
//���ŵ�һ�������������������� 
void swap(int *a,int *b){
	int c=*b;
	*b=*a;
	*a=c;
}
//���п�������quick sort�� 
void quick_sort(int *p,int n) {
    //�������ֻ��һ��ʱ����ֹ���� 
	if (n<=1){
    	return;
    }
    //��ȡ���Ҳ��Ԫ��Ϊ��� 
	int t=p[n-1],l=0,r=n-2;
    //ʹ�ñȱ�ߴ��Ԫ���ڱ�ߵ��Ҳ࣬�ȱ��С��Ԫ���ڱ�ߵ���� 
	do{
        //�ֱ�����������Ҳ࿪ʼ�������ң�һ��������ҵ��ȱ�ߴ���������Ҳ��ҵ��ȱ��С�������ͽ����ǽ��н��� 
		for(;r>=l;l++){
       	    if(p[l]>t){
       	        break;
			}
        }
       for(;r>=l;r--){
        	if(p[r]<t){
        		break;
			}
        }
        //��������ɨ��������Ϊֹ 
		if(r>=l){
        	swap(&p[l],&p[r]);
		}
    }while(r>=l);
    //����߽����������һ��λ�� 
	swap(&p[l],&p[n - 1]);
    //֮��ݹ飬�ֱ��������Ҳ������˵����� 
	quick_sort(&p[0],l);
    quick_sort(&p[l+1],n-l-1);
}
int main(){
	int N=0;
	long int sum=0;
	cin>>N;
	//����� 
	for(int i=0;i<N;i++){
		scanf("%d",&input[i]);//ע��˴�Ӧ��scanf�������룬��ʡʱ�� 
	}
	quick_sort(input,N);
	//�ж�ʯ����������ż�� ���Ӷ����м��� 
	if(N%2==0){
		for(int i=0;i<(N/2);i++){
			sum+=input[i+N/2]-input[i];
		}
	}else{
		for(int i=0;i<(N-1)/2;i++){
			sum+=input[i+(N-1)/2]-input[i];
		}
		sum=sum+input[N-1];
	}
	cout<<sum<<endl;
	return 0;
}

#include<iostream>
using namespace std;
//��̬�滮
//dp���壺��iΪ��β������������еĳ���
//״̬ת�Ʒ��̣�dp[i]= max(dp[j])+1,j<i,input[j]<input[i]
int dp[1005];
int input[1005];
int longest(int input[],int n){
	int max=0,judge=0;
	if(n==1){//��ֹ������nΪ1ʱ 
		dp[n-1]=1;
		return dp[n-1];
	}
    if(dp[n-1]>0){//�洢��ǿ 
    	return dp[n-1];
    }
	if(n>=2){//����״̬ת�Ʒ��� 
		for(int i=0;i<n-1;i++){
			if(input[i]<input[n-1]){
				judge=1;//�ж��Ƿ���״̬ת�Ʒ����������� 
				if(longest(input,i+1)>max){
					max=longest(input,i+1);//ȡ�����е����ֵ 
				}
			}
		}
		if(judge==0){
			dp[n-1]=1;
		}else{
			dp[n-1]=max+1;
		}
		return dp[n-1];
	}
}
int main(){
	int n=0,max=0;
	cin>>n;
	for(int i=0;i<n;i++){//���� 
		scanf("%d",&input[i]);
	}
	max=longest(input,n);
	for(int i=n-1;i>=0;i--){
		if(longest(input,i+1)>max){
			max=longest(input,i+1);//��ע�⣺�˴�һ�εݹ鲢����ʹ�����е�dp�����е�ֵ�������ǵ���������Ҫ��εݹ� 
		}
	}
	cout<<max;
	return 0;
}

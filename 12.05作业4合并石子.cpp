#include<iostream>
using namespace std;
//��̬�滮
//dp���壺��i��j����С����
//״̬ת�Ʒ��̣�dp[i][j]=min(dp[i][k]+dp[k][j])+sum[j]-sum[i-1] 
int input[1005];
int sum[1005];
int dp[1005][1005];
int price(int i,int j){
	if(i==j){//������ֹ������i=jʱ�ϲ�����Ϊ0 
		dp[i-1][j-1]=0;
		return dp[i-1][j-1];
	}
	if(dp[i-1][j-1]>-1){//�洢��ǿ 
		return dp[i-1][j-1];
	}
	if(i<j){//״̬ת�Ʒ��̵����� 
	    int min=2147483647;
	    for(int k=i;k<j;k++){//ע��ϸ�ڣ�һ�����Ŷ��п��ܵ�����������ı��� 
	    	if((price(i,k)+price(k+1,j))<min){
	    		min=price(i,k)+price(k+1,j);
	    	}
	    }
	    if(i==1){
	    	dp[i-1][j-1]=min+sum[j-1];
		}else{
			dp[i-1][j-1]=min+sum[j-1]-sum[i-2];
		}
		return dp[i-1][j-1];
	}
}
int main(){
	int n=0;
	cin>>n;
	for(int i=0;i<n;i++){//���� 
		scanf("%d",&input[i]);
	}
	for(int i=0;i<1005;i++){//��ʼ�� 
		for(int j=0;j<1005;j++){
			dp[i][j]=-1;
		} 
	}
	sum[0]=input[0];
	for(int i=1;i<n;i++){//ע��˴���sumΪǰ׺�ͣ���sum[i]��ʾ���Ǵ�1�ӵ�i�ĺ� 
		sum[i]=sum[i-1]+input[i];
	}
	int output=0;
	output=price(1,n);
	cout<<output;//��� 
	return 0;
}

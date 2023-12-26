#include<iostream>
using namespace std;
//动态规划
//dp含义：从i到j的最小代价
//状态转移方程：dp[i][j]=min(dp[i][k]+dp[k][j])+sum[j]-sum[i-1] 
int input[1005];
int sum[1005];
int dp[1005][1005];
int price(int i,int j){
	if(i==j){//描述终止条件：i=j时合并代价为0 
		dp[i-1][j-1]=0;
		return dp[i-1][j-1];
	}
	if(dp[i-1][j-1]>-1){//存储增强 
		return dp[i-1][j-1];
	}
	if(i<j){//状态转移方程的描述 
	    int min=2147483647;
	    for(int k=i;k<j;k++){//注意细节：一个符号都有可能导致整个程序的崩盘 
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
	for(int i=0;i<n;i++){//输入 
		scanf("%d",&input[i]);
	}
	for(int i=0;i<1005;i++){//初始化 
		for(int j=0;j<1005;j++){
			dp[i][j]=-1;
		} 
	}
	sum[0]=input[0];
	for(int i=1;i<n;i++){//注意此处的sum为前缀和，即sum[i]表示的是从1加到i的和 
		sum[i]=sum[i-1]+input[i];
	}
	int output=0;
	output=price(1,n);
	cout<<output;//输出 
	return 0;
}

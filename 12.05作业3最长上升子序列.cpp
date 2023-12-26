#include<iostream>
using namespace std;
//动态规划
//dp含义：以i为结尾的最长上升子序列的长度
//状态转移方程：dp[i]= max(dp[j])+1,j<i,input[j]<input[i]
int dp[1005];
int input[1005];
int longest(int input[],int n){
	int max=0,judge=0;
	if(n==1){//终止条件：n为1时 
		dp[n-1]=1;
		return dp[n-1];
	}
    if(dp[n-1]>0){//存储增强 
    	return dp[n-1];
    }
	if(n>=2){//描述状态转移方程 
		for(int i=0;i<n-1;i++){
			if(input[i]<input[n-1]){
				judge=1;//判断是否有状态转移方程满足条件 
				if(longest(input,i+1)>max){
					max=longest(input,i+1);//取遍历中的最大值 
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
	for(int i=0;i<n;i++){//输入 
		scanf("%d",&input[i]);
	}
	max=longest(input,n);
	for(int i=n-1;i>=0;i--){
		if(longest(input,i+1)>max){
			max=longest(input,i+1);//需注意：此处一次递归并不能使得所有的dp数组中的值都被覆盖到，所以需要多次递归 
		}
	}
	cout<<max;
	return 0;
}

#include<iostream>
using namespace std;
int input[50005];
long long int dp[50005]; 
//运用动态规划解题
//dp[i]含义：以第i个数结尾的最大连续子序列的和
//状态转移方程：dp[i]=max(input[i],dp[i-1]+input[i])
int dynamic(int input[],int N){
	if(N==1){//终止条件：只有一个数的时候，所求值就是它本身 
		dp[N-1]=input[0];
		return dp[N-1];
	}
	if(dp[N-1]<10000000000){//存储增强：大幅度节省时间 
		return dp[N-1];
	}
	if(N>=2){//描述状态转移方程 
		if(dynamic(input,N-1)<=0){
			dp[N-1]=input[N-1];
		}else{
			dp[N-1]=dynamic(input,N-1)+input[N-1];
		}
	    return dp[N-1];
	}
} 
int main(){
	int N=0,max=0;
	//输入端 
	cin>>N;
	for(int i=0;i<N;i++){
		scanf("%d",&input[i]);
		dp[i]=10000000000;
	}
    max=dynamic(input,N);//先算第N个数后的“dp”值，由该次递归的特质可以知道，在经行第N个数的递归值之后，可以获得dp数组中的每一个值 
	for(int i=N-1;i>=1;i--){
		if(dp[i]>max){
			max=dp[i];//选择其中最大的即为本题答案 
		}
	}
	cout<<max;
	return 0;
}

#include<iostream>
using namespace std;
//运用动态规划解题
//dp含义：“线性数组”的条件下，到第i个数为止的按照题中规则选出的最大的和
//状态转移方程：dp[i]=min（input[i]+dp[i-2],dp[i-1])
//为防止数值越界：将所有数值类型改为long long int 
long long int input[100005];
long long int input_improve1[100005];
long long int input_improve2[100005];
long long int dp[100005];
long long int pick(long long int input[],int i){
	//注意：本题的终止条件有两个 
	if(i==1){//终止条件1：只有一个时，就只能选择它自己 
		dp[i-1]=input[0];
		return dp[i-1];
	}
	if(i==2){//终止条件2：只有两个时，选择两个之中较大的那一个 
		if(input[0]>=input[1]){
			dp[i-1]=input[0]; 
		}else{
			dp[i-1]=input[1];
		}
		return dp[i-1];
	}
	if(dp[i-1]>0){//记忆存储：节省了大量的时间 
		return dp[i-1];
	}
	if(i>2){//描述状态转移方程 
		if((input[i-1]+pick(input,i-2))>=pick(input,i-1)){
			dp[i-1]=input[i-1]+pick(input,i-2);
		}else{
			dp[i-1]=pick(input,i-1);
		}
		return dp[i-1];
	}
}
int main(){
	long long int n=0,output=0,output1=0,output2=0;
	cin>>n;
	for(int i=0;i<n;i++){//输入端 
		scanf("%lld",&input[i]);
	}
	//下面是对于循环数组的一种特殊的处理方式:化循环数组为线性数组
	//分析本题的含义可知：元素个数为n循环数组可以转化为从1到n-1的线性数组和从2到n的循环数组，然后取两者之中的最大值 
	for(int i=0;i<n-1;i++){
		input_improve1[i]=input[i];
	}
	for(int i=0;i<n-1;i++){
		input_improve2[i]=input[i+1];
	}
	output1=pick(input_improve1,n-1);//注意此处需将函数调用两次，所以在调用第二次函数之前dp函数应该被初始化一次 
	for(int i=0;i<100005;i++){
		dp[i]=0;
	}
	output2=pick(input_improve2,n-1);
	if(output1>output2){//两者之中取较大的那一个数组作为输出值 
		output=output1;
	}else{
		output=output2;
	}
	cout<<output;
	return 0;
}

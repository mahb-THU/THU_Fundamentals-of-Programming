#include<iostream>
using namespace std;
int input[55];
bool dp[55][1005];
//用bool状态dp[i][j]表示弹第i首歌前音量是否可能是j，写出状态转移方程 
int main(){
    int n=0,begin=0,max=0;	
	//输入端 
	cin>>n>>begin>>max;
	for(int i=0;i<n;i++){
		scanf("%d",&input[i]);
	}
	//dp数组初始化 
	dp[0][begin]=true;
	//双重循环对于dp数组进行扫描
	//特殊之处：本题用如下的递推关系描述状态转移方程比用递归关系描述更为简便 
	for(int i=1;i<=n;i++){
		for(int j=0;j<=max;j++){
			//可视为一个分支的不断延伸，将false改为true 
			if((dp[i-1][j]==true)&&(j+input[i-1])<=max){
				dp[i][j+input[i-1]]=true;
			}
			if((dp[i-1][j]==true)&&(j-input[i-1])>=0){
				dp[i][j-input[i-1]]=true;
			}
		}
	}
    bool judge=false;
    int output=-1;
	//因为是要寻找最大值，所以将数组从最大值向最小值开始扫描，找到符合条件的数后，马上脱离循环 
	for(int i=max;i>=0;i--){
		if(dp[n][i]){
			judge=true;
            output=i;
			break;		
		}
	}
	cout<<output;
	return 0;
}

#include<iostream>
using namespace std;
int input[55];
bool dp[55][1005];
//��bool״̬dp[i][j]��ʾ����i�׸�ǰ�����Ƿ������j��д��״̬ת�Ʒ��� 
int main(){
    int n=0,begin=0,max=0;	
	//����� 
	cin>>n>>begin>>max;
	for(int i=0;i<n;i++){
		scanf("%d",&input[i]);
	}
	//dp�����ʼ�� 
	dp[0][begin]=true;
	//˫��ѭ������dp�������ɨ��
	//����֮�������������µĵ��ƹ�ϵ����״̬ת�Ʒ��̱��õݹ��ϵ������Ϊ��� 
	for(int i=1;i<=n;i++){
		for(int j=0;j<=max;j++){
			//����Ϊһ����֧�Ĳ������죬��false��Ϊtrue 
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
	//��Ϊ��ҪѰ�����ֵ�����Խ���������ֵ����Сֵ��ʼɨ�裬�ҵ�����������������������ѭ�� 
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

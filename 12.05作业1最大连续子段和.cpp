#include<iostream>
using namespace std;
int input[50005];
long long int dp[50005]; 
//���ö�̬�滮����
//dp[i]���壺�Ե�i������β��������������еĺ�
//״̬ת�Ʒ��̣�dp[i]=max(input[i],dp[i-1]+input[i])
int dynamic(int input[],int N){
	if(N==1){//��ֹ������ֻ��һ������ʱ������ֵ���������� 
		dp[N-1]=input[0];
		return dp[N-1];
	}
	if(dp[N-1]<10000000000){//�洢��ǿ������Ƚ�ʡʱ�� 
		return dp[N-1];
	}
	if(N>=2){//����״̬ת�Ʒ��� 
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
	//����� 
	cin>>N;
	for(int i=0;i<N;i++){
		scanf("%d",&input[i]);
		dp[i]=10000000000;
	}
    max=dynamic(input,N);//�����N������ġ�dp��ֵ���ɸôεݹ�����ʿ���֪�����ھ��е�N�����ĵݹ�ֵ֮�󣬿��Ի��dp�����е�ÿһ��ֵ 
	for(int i=N-1;i>=1;i--){
		if(dp[i]>max){
			max=dp[i];//ѡ���������ļ�Ϊ����� 
		}
	}
	cout<<max;
	return 0;
}

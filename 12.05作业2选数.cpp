#include<iostream>
using namespace std;
//���ö�̬�滮����
//dp���壺���������顱�������£�����i����Ϊֹ�İ������й���ѡ�������ĺ�
//״̬ת�Ʒ��̣�dp[i]=min��input[i]+dp[i-2],dp[i-1])
//Ϊ��ֹ��ֵԽ�磺��������ֵ���͸�Ϊlong long int 
long long int input[100005];
long long int input_improve1[100005];
long long int input_improve2[100005];
long long int dp[100005];
long long int pick(long long int input[],int i){
	//ע�⣺�������ֹ���������� 
	if(i==1){//��ֹ����1��ֻ��һ��ʱ����ֻ��ѡ�����Լ� 
		dp[i-1]=input[0];
		return dp[i-1];
	}
	if(i==2){//��ֹ����2��ֻ������ʱ��ѡ������֮�нϴ����һ�� 
		if(input[0]>=input[1]){
			dp[i-1]=input[0]; 
		}else{
			dp[i-1]=input[1];
		}
		return dp[i-1];
	}
	if(dp[i-1]>0){//����洢����ʡ�˴�����ʱ�� 
		return dp[i-1];
	}
	if(i>2){//����״̬ת�Ʒ��� 
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
	for(int i=0;i<n;i++){//����� 
		scanf("%lld",&input[i]);
	}
	//�����Ƕ���ѭ�������һ������Ĵ���ʽ:��ѭ������Ϊ��������
	//��������ĺ����֪��Ԫ�ظ���Ϊnѭ���������ת��Ϊ��1��n-1����������ʹ�2��n��ѭ�����飬Ȼ��ȡ����֮�е����ֵ 
	for(int i=0;i<n-1;i++){
		input_improve1[i]=input[i];
	}
	for(int i=0;i<n-1;i++){
		input_improve2[i]=input[i+1];
	}
	output1=pick(input_improve1,n-1);//ע��˴��轫�����������Σ������ڵ��õڶ��κ���֮ǰdp����Ӧ�ñ���ʼ��һ�� 
	for(int i=0;i<100005;i++){
		dp[i]=0;
	}
	output2=pick(input_improve2,n-1);
	if(output1>output2){//����֮��ȡ�ϴ����һ��������Ϊ���ֵ 
		output=output1;
	}else{
		output=output2;
	}
	cout<<output;
	return 0;
}

#include<iostream>
using namespace std;
int main(){
	//�������ݶ� 
	int N=0,M=0;
	cin>>N>>M;
	int price[N+1][M+1];
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin>>price[i][j];
		}
	}
	//��ʼ���м��� 
	//Ԥ��������������ϽǶ��㵽��a�У���b�еľ����sum��M*(a-1)+b��
	int sum[M*N+1]={0};
	for(int a=1;a<=N;a++){
		for(int b=1;b<=M;b++){
			for(int i=1;i<=a;i++){
				for(int j=1;j<=b;j++){
					sum[M*(a-1)+b]=sum[M*(a-1)+b]+price[i][j];
				}
			}
		}
	}
	//������ͨ��Ԥ����Ľ��ۺͼ��ݳ�ԭ����⣨u��v������x��y���ľ���ͣ����ǲ����u��v�����ڣ�x��y��������·�����������غ� 
	//�����б�Ҫ����x=1����y=1���������Ϊ���ǵ��ݳ�ԭ�������̲�����ͬ
	int max=-200000,profit=0;
	for(int x=1;x<=M;x++){
		for(int y=1;y<=N;y++){
			for(int u=x;u<=M;u++){
				for(int v=y;v<=N;v++){
					if((x==1)&&(y==1)){
						profit=sum[M*(v-1)+u];
						if(profit>=max){
							max=profit;
						}
					}else if((x==1)&&(y!=1)){
						profit=sum[M*(v-1)+u]-sum[M*(y-2)+u];
						if(profit>=max){
							max=profit;
						}
					}else if((x!=1)&&(y==1)){
						profit=sum[M*(v-1)+u]-sum[M*(v-1)+x-1];
						if(profit>=max){
							max=profit;
						}
					}else{
						profit=sum[M*(v-1)+u]-sum[M*(v-1)+x-1]-sum[M*(y-2)+u]+sum[M*(y-2)+x-1];
						if(profit>=max){
							max=profit;
						}
					}
				}
			}
		}
	}
	cout<<max<<endl;
	return 0; 
}

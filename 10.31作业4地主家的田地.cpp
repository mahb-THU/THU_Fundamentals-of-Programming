#include<iostream>
using namespace std;
int main(){
	//输入数据端 
	int N=0,M=0;
	cin>>N>>M;
	int price[N+1][M+1];
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin>>price[i][j];
		}
	}
	//开始进行计算 
	//预处理：首先求得左上角顶点到第a行，第b列的矩阵和sum【M*(a-1)+b】
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
	//接下来通过预处理的结论和简单容斥原理求解（u，v）到（x，y）的矩阵和，我们不妨令（u，v）点在（x，y）点的右下方，两点可以重合 
	//我们有必要考虑x=1或是y=1的情况，因为它们的容斥原理计算过程并不相同
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

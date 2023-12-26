#include<iostream>
using namespace std;
//注意left，right，try等均为c++中的关键字若要使用，需将首字母大写，不然编译会报错 
int number=0;//记录方案数
int queen[15]={0};//记录N个皇后所占用的列号
bool Column[15];//c[1]~c[N]当前列是否安全 
bool Left[29];//l[2]~l[2*N]（i+j）对角线是否安全
bool Right[29];//r[2]~r[2*N](i-j)对角线是否安全
void Try(int i,int N,int x,int y){//i为行数，N为棋盘总行数，（x，y）为问题点坐标，其中x为行，y为列 
	for(int j=1;j<=N;j++){
		if((Column[j])&&(Left[i-j+N+1])&&(Right[i+j])&&((i!=x)||(j!=y))){//第i行，第j列是安全的，两条对角线是安全的，同时将要放置皇后的那一个点不在问题点上 
			//第一件事，占用位置（i，j）
			queen[i]=j; 
			//修改安全位置，包括所在的列和两条对角线
			Column[j]=false;
			Left[i-j+N+1]=false;
			Right[i+j]=false;
			//第二件事，判断是否放完了N个皇后
			if(i<N){//未放完N个皇后 
				Try(i+1,N,x,y);//继续放下一个 
			} else{//已经放完N个皇后 
				number++;//方案数加1 
			}
			//第三件事，修改安全标志，回溯
			Column[j]=true;
			Left[i-j+N+1]=true;
			Right[i+j]=true; 
		}
	}
}
int main(){
	number=0;//方案数清零
	int N,x,y;
	cin>>N>>x>>y;//输入总行数及问题点的坐标
	for(int i=0;i<N+1;i++){
		Column[i]=true;//置所有列为安全 
	} 
	for(int i=0;i<2*N+1;i++){
		Left[i]=Right[i]=true;//置所有的对角线为安全 
	} 
	Try(1,N,x,y);//递归放置N个皇后，从第一个开始放
	cout<<number<<endl;//输出方案数 
	return 0; 
} 

#include<iostream>
using namespace std;
int main(){
	//输入部分，输入各组数据 
	int n=0;
	cin>>n;
	int carpet[n][4];
	for(int i=0;i<n;i++){
		for(int j=0;j<4;j++){
			cin>>carpet[i][j];
		}
	}
	int loc[2];
	for(int k=0;k<2;k++){
		cin>>loc[k];
	}
	//计算与输出部分
	int num=-1;
	//注意数组的标号问题，从“0”开始是关键 
	for(int p=0;p<n;p++){
		if((loc[0]>=carpet[p][0])&&(loc[0]<=(carpet[p][0]+carpet[p][2]))&&(loc[1]>=carpet[p][1])&&(loc[1]<=(carpet[p][1]+carpet[p][3]))){
			num=p+1;
		}
	} 
	cout<<num<<endl;
	return 0;
}

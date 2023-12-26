#include<iostream>
using namespace std;
int input[15][2015];
int N[15];
int output[15];
int max(int a,int b){
	if(a>=b){
		return a;
	}else{
		return b;
	}
}
int min(int a,int b){
	if(a<=b){
		return a;
	}else{
		return b;
	}
}
int gcdcompute(int a,int b){
	int c,d,r=1;
	c=max(a,b);
	d=min(a,b);
	while(r!=0){
		r=c%d;
		c=d;
		d=r;
	}
	return c;
}
int main(){
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>N[i];
		for(int j=1;j<=N[i];j++){
			scanf("%d",&input[i][j]);
		}
	}
	for(int i=1;i<=T;i++){
		int g=0,maxinum=0;
		for(int j=1;j<=N[i]-1;j++){
			for(int k=j+1;k<=N[i];k++){
				g=gcdcompute(input[i][j],input[i][k]);
				if(g>=maxinum){
					maxinum=g;
				}
			}
		}
		output[i]=maxinum;
	}
	for(int i=1;i<=T;i++){
		cout<<output[i]<<endl;
	}
	return 0;
}

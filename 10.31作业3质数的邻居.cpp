#include<iostream>
using namespace std;
bool isprime[11000001];
int mat[726518]={0};
int main(){
	 //用筛法穷尽11000000内的素数并将其进行数组上的标号
	int count=0;
	for(int i=2;i<=11000000;i++){
		isprime[i]=true;
	}
	for(int i=2;i*i<=11000000;i++){
		if(isprime[i]==true){
			for(int j=i*i;j<=11000000;j+=i){
				isprime[j]=false;
			}
		}
	}
	for(int i=2;i<=11000000;i++){
		if(isprime[i]==true){
			count++;
			mat[count]=i;
		}
	}
    //输入数据端 
	int T=0,r=0;
	cin>>T>>r;
    int judge[T+1];
	for(int i=1;i<=T;i++){
		cin>>judge[i];
	}
	//在11000000内共提取到726517个质数，并将它们按大小顺序编排在数组mat中，此时耗时约为70ms
	//用折半抽取的方式取到最接近的质数 
	for(int i=1;i<=T;i++){
		int low=1,high=726517,middle=0,anw=0,sign=0;
		//先检索含不含素数，并在检索的同时将范围缩小 
		while(low<=high){
			middle=(high+low)/2;
			if(judge[i]==mat[middle]){
				if((judge[i]-mat[middle-1])<=(mat[middle+1]-judge[i])){
					anw=mat[middle-1];
					sign=1;
					break;
				}else{
					anw=mat[middle+1];
					sign=1;
					break;
				}
			}else if(judge[i]<mat[middle]){
				high=middle-1;
			}else{
				low=middle+1;
			}
		} 
		if(sign==1){
			if(((anw-judge[i])>=-r)&&((anw-judge[i])<=r)){//注意析取与合取之间的逻辑关系 
				cout<<"T"<<endl;
			}else{
				cout<<"F"<<endl;
			}
		}
		//最接近的数只有三种可能：第middle-1个，第middle个，第middle+1个 
		if(sign!=1){//注意析取与合取之间的逻辑关系 
			if((((mat[middle-1]-judge[i])>=-r)&&((mat[middle-1]-judge[i])<=r))||(((mat[middle]-judge[i])>=-r)&&((mat[middle]-judge[i])<=r))||(((mat[middle+1]-judge[i])>=-r)&&((mat[middle+1]-judge[i])<=r))){
				cout<<"T"<<endl;
			}else{
				cout<<"F"<<endl;
			}
		}
	} 
	return 0; 
}

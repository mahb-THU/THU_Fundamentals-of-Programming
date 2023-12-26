#include<iostream>
using namespace std;
int local[50005];
int maxinum(int p,int q){
	if(p>=q){
		return p;
	}else{
		return q;
	}
}
int main(){
	int N=0;
	cin>>N;
	for(int i=1;i<=N;i++){
		scanf("%d",&local[i]);
	}
	int nowremote=1;   
    int count=0;            
    int nextremote=1;    
    for(int i=1;i<N;i++){ 
        nextremote=maxinum(local[i]+i,nextremote); 
        if(i==nowremote){                 
           	nowremote=nextremote;        
            count++;
        }
    }
	cout<<count<<endl;
	return 0;
}

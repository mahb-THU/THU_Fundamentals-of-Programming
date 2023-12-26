#include<iostream>
using namespace std;
int price[100005];
int profit=0;
int main(){
	int N=0; 
	cin>>N;
	for(int i=1;i<=N;i++){
		scanf("%d",&price[i]);
	}
	for(int i=2;i<=N;i++){
		if(price[i-1]<price[i]){
			profit=profit+price[i]-price[i-1];
		}
	}
	cout<<profit<<endl;
	return 0;
}

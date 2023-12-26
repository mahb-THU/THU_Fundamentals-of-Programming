#include<iostream>
using namespace std;
int main(){
	int n=0,i=0,j=0,sum=0;
	cin>>n;
	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			sum=i*j+(j*(j-1))/2;
			if(sum==n){
				printf("%d %d\n",i,i+j-1);
			}
		} 
	}
	return 0;
}

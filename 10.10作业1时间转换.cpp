#include<iostream>
using namespace std;
int main(){
	int n=0,day=0,hour=0,minute=0;
	cin>>n;
	day=n/(24*60);
	hour=(n%(24*60))/60;
	minute=(n%(24*60))%60;
	printf("%d %d %d",day,hour,minute);
	return 0;
	
}

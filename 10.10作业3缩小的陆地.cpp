#include<iostream>
using namespace std;
int main(){
	double x=0,y=0,i=0,s=0,z=0;
	const double PI=3.1415926;
	scanf("%lf %lf",&x,&y);
	s=0.5*PI*(x*x+y*y);
	for(i=0;i<=s/50;i++){
		z=i+1;
	}
	cout<<z<<endl;
	return 0;
}

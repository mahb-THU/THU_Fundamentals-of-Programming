#include<iostream>
using namespace std;
int main(){
	int L=0,R=0,n=0,i=0,j=0,b=0,count=0,I=0,J=0;
	scanf("%d %d",&L,&R);
	for(i=L;i<=R;i++){
		I=i;
		J=I;
        int ret=0,a=1;
		while(J>0){
	    	J=J/10;
			ret++;
			a=a*10;
		}
		n=a/10;
		for(j=1;j<=ret;j++){
			b=I/n;
			if(b==2){
				count++;
			}
			I=I%n;
			n=n/10;
	    } 	 
   }
    cout<<count<<endl; 
    return 0; 
}

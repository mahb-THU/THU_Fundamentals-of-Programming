#include<iostream>
using namespace std;
//declaring the array "occasion" here ,its element are all ZERO
int occasion[205][10];
int divide(int total,int times){
	//STORAGE ENHANCED:preventing the "time limit exceeded"
	if(occasion[total][times]>0){
		return occasion[total][times];
	}else{
		//ending condition
		if(total==times){
		    occasion[total][times]=1;
		    return occasion[total][times];
	    }
	    //initially,giving each column a number"1",so we reduce the independent variable "total"
	    //according to this idea,we can find the relationship of different independent variables of the function "divide"
		//then,we can make the recursion
		//processing the classified discussion 
		if((total-times)>=times){
	    	for(int i=1;i<=times;i++){
	    		occasion[total][times]+=divide(total-times,i);
			}
			return occasion[total][times];
		}
		if((total-times)<times){
	    	for(int i=1;i<=total-times;i++){
	    		occasion[total][times]+=divide(total-times,i);
			}
			return occasion[total][times];
	    }
	}
}
int main(){
	int n,k;
	int output=0;
	cin>>n>>k;//indicating that divides the integar"n" into "k" pieces 
	output=divide(n,k);
	cout<<output<<endl; 
	return 0; 
}

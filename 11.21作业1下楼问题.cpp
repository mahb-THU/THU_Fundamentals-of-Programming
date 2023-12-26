#include<iostream>
using namespace std;
int floor(int h){
    int floor_p[25];//storage enhanced;highly improving the running speed 
    for(int i=1;i<=24;i++){
    	floor_p[i]=-1;
	}
	//the ending condition;ATTENTION:these conditions must be considered completely
	if(h==0){
		return 0;
	}
	if(h==1){
		return 1;
	}
	if(h==2){
		return 2;
	}
	if(h==3){
		return 4;
	}
	//if the statistic had been calculated,it shouldn't have been completed again
	if(floor_p[h]>0){
		return floor_p[h];
	}
	//the crucial equation
	floor_p[h]=floor(h-1)+floor(h-2)+floor(h-3);
	return floor_p[h];
}
int main(){
	int h,output;
	cin>>h;//"h"steps in total
	//according to the question,the statistic range is from 4 to 20
	if((h>=4)&&(h<=20)){
		output=floor(h);
	}else{
		output=0;
	}
	cout<<output;
	return 0; 
}

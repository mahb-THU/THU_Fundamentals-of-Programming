#include<iostream>
using namespace std;
int main(){
	int N=0,num=0;//输入数组 
	cin>>N;
    int input[N];
	for(int i=0;i<N;i++){
		cin>>input[i];
	}
    //极为巧妙的运算方式，对于数组中的数据进行统计，这很重要，也很普适，提醒我们对于数组中数的第一思维是将它们进行处理 
	int count[1001]={0};
	for(int j=0;j<N;j++){
		int k=1;
		k=input[j];
		count[k]++;
	} 
	//计算重复数的过程，在已有统计的基础上显得格外简单 
	num=N;
	for(int h=1;h<=1000;h++){
		if(count[h]>1){
			num=num-count[h]+1;
		}
	}
	//给数字排序的过程，建立在数组中数据统计和循环遍历的基础上，显得比较简单 
	int output[num],cnt=-1;
	for(int g=1;g<=1000;g++){
	    if(count[g]>0){
			cnt++;
			output[cnt]=g;
		}
	}
	//输出一个数组中数字的过程，需要用循环进行输出 
	cout<<num<<endl;
	for(int f=0;f<num;f++){
		cout<<output[f]<<" ";
	}
	return 0;

}

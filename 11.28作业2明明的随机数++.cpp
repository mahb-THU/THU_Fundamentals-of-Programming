//指导思想：先排序再去重：这样可以最大限度的节省时间复杂度
//若是先去重再排序：这是一种桶排序的想法，问题在于：若是给定的数值过大，既严重地浪费了空间，也浪费了时间 
#include<iostream>
using namespace std;
int input[100001];
int output[100001];
//交换函数 
void swap(int *a,int *b){
	int c=*b;
	*b=*a;
	*a=c;
}
//快排函数 
void quick_sort(int *p,int n) {
    if (n<=1){
    	return;
    }
    int t=p[n-1],l=0,r=n-2;
    do{
       for (;r>=l;l++){
       	    if(p[l]>t){
       	    	break;
			}
        }
        for(;r>=l;r--){
        	if(p[r]<t){
        		break;
			}
        }
        if(r>=l){
        	swap(&p[l],&p[r]);
		}
    }while(r>=l);
    swap(&p[l],&p[n - 1]);
    quick_sort(&p[0],l);
    quick_sort(&p[l+1],n-l-1);
}
int main(){
	int N=0;//输入数组 
	cin>>N;
    for(int i=0;i<N;i++){
		cin>>input[i];
	}
	quick_sort(input,N);
	int number=1;
	output[1]=input[0];//作为一个排好了的数组的输出数组 
	for(int i=1;i<N;i++){
		//这是一个去重的过程 
		if(input[i]!=input[i-1]){
			number++;
			output[number]=input[i];
		}
	}
	cout<<number<<endl;
	for(int i=1;i<=number;i++){
		cout<<output[i]<<" ";
	}
	return 0; 
}

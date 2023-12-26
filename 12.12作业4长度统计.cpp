#include<iostream>
using namespace std;
int start[1005];
int endnum[1005];
int start_new[1005];
int end_new[1005];
int end_old[1005];
int dp[1005];
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
//求取最小值的函数 
int minimum(int a,int b){
	if(a>=b){
		return b;
	}else{
		return a;
	}
}
int main(){
	int n=0,count1=0;
	//输入端 
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&start[i]);
		scanf("%d",&endnum[i]);
	}
	//以结尾为基准对所有区间进行排序 
	for(int i=0;i<n;i++){
		end_old[i]=endnum[i];
	}
	quick_sort(endnum,n);
	end_new[0]=endnum[0];
	for(int i=1;i<n;i++){
		if(endnum[i]!=endnum[i-1]){
			count1++;
			end_new[count1]=endnum[i];
		}
	} 
    //同一结尾只保留区间长度最长的区间 
	for(int i=0;i<=count1;i++){
		int min=2147483647;
		for(int k=0;k<n;k++){
		    if(end_new[i]==end_old[k]){
				if(start[k]<min){
					min=start[k];
				}
			}
		}
		start_new[i]=min;
	}
	int sum=0;
	int judge=2147483647;//可将judge视作一个扫描线，扫过时判断大小来进行长度的累加 
	for(int i=count1;i>=0;i--){
		if(start_new[i]<=judge){
			sum+=minimum(judge,end_new[i])-start_new[i];
			judge=start_new[i];
		}
	}
	cout<<sum;
    return 0;
}

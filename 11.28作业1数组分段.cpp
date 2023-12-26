//本题采用贪心算法加二分查找进行解决，同样也可以直接使用动态规划进行解决 
#include<iostream>
#include<cstdio>
using namespace std;
//贪心算法
//判断一个数是否可以在规定的段数内（小于等于）作为分段数组和的的最大值 
int judge(long long int number,int N,long long int array[]){
    //初始的段数为1，即无论怎么分都一定有一组存在 
	int count=1;
    long long int sum_array=0;
    for(int i=0;i<N;i++){
        //使用贪心算法的核心，把这个数看作一个一定容量的桶，只要可以“往里装就装到不能装为止” 
		if((sum_array+array[i])>number){//先试试，装“冒”了，就开一个新的桶去装 
            count++;
            sum_array=array[i];
        }else{//先试试，装不冒，就继续装 
            sum_array+=array[i];
        }
    }
    return count;
}
int main(){
    int N,M;
    cin>>N>>M;
    long long int array[N];
    long long int total=0;
    //逐个输入数组里的项，并顺势求和 
	for(int i=0;i<N;i++){
        scanf("%lld",&array[i]);
        total+=array[i];
    }
    long long int max=array[0];
    //求得数组里的最大项 
    for(int i=1;i<N;i++){
        if(array[i]>=max){
            max=array[i];
        }
    }	
    //最终所得的这个项一定处于数组中的最大项和数组中所有数的和之间 
	//对这个数运用二分查找进行逼近 
	long long int low=max;
    long long int high=total;
    long long int middle=0;
    //请注意，这个是二分查找的一个范式，这其中的每一个加1减1，取等符号都不能出错，出错了便容易出现“time limit eceeded” 
	while(low<=high){
        middle=(low+high)/2;
        if(judge(middle,N,array)>M){
            low=middle+1;
        }
        if(judge(middle,N,array)<=M){
            high=middle-1;
        }
    }
    //如果low大于了high就说明对于区间的估计到了那条线，low本身就是刚过那条线的第一个数，所以直接选择low输出即可 
	cout<<low; 
    return 0;
}


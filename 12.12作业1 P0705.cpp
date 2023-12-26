#include<iostream>
using namespace std;
int input1[1005];
int input2[1005]; 
int intersection[1005];
int origin_set[2010];
int union_set[2010];
int difference_set[1005];
int count1=-1;
int count2=0;
int count3=-1;
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
//求交集，自变量为两个集合的元素和元素的个数 
void intersect(int input1[],int input2[],int n,int m){
	for(int i=0;i<n;i++){//遍历，从而寻找共有的元素 
		for(int j=0;j<m;j++){
			if(input1[i]==input2[j]){
				count1++;
				intersection[count1]=input1[i];
			}
		}
	}
	quick_sort(intersection,count1+1);//进行排序 
}
//求并集，自变量为两个集合的元素和元素的个数
void unite(int input1[],int input2[],int n,int m){
	//将两个集合的元素整合至一个集合中 
	for(int i=0;i<n;i++){
		origin_set[i]=input1[i];
	}
	for(int j=n;j<(m+n);j++){
		origin_set[j]=input2[j-n];
	}
	//先排序，再去重，类似于明明的随机数，从而得到最后的并集 
	quick_sort(origin_set,m+n);
	union_set[0]=origin_set[0];
	for(int i=1;i<(m+n);i++){
		if(origin_set[i]!=origin_set[i-1]){
			count2++;
			union_set[count2]=origin_set[i];
		}
	}
}
//求差集，自变量为两个集合的元素和元素的个数 
void difference(int input1[],int input2[],int n,int m){
	for(int i=0;i<n;i++){
		int count_special=0;//作为一个标志 
		for(int j=0;j<=count1;j++){
			if(input1[i]!=intersection[j]){
				count_special++;
			}
		}
		if(count_special==(count1+1)){
			count3++;
			difference_set[count3]=input1[i];
		}
	}
	quick_sort(difference_set,count3+1);
}
int main(){
	int n=0,m=0;
	//输入端 
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&input1[i]);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		scanf("%d",&input2[i]);
	}
  	//进行主要的函数运算 
	intersect(input1,input2,n,m);
  	unite(input1,input2,n,m);
  	difference(input1,input2,n,m);
	//输出端 
	for(int i=0;i<=count1;i++){
  		cout<<intersection[i]<<" "; 
  	}
  	cout<<endl;
  	for(int i=0;i<=count2;i++){
  		cout<<union_set[i]<<" ";
  	}
  	cout<<endl;
    for(int i=0;i<=count3;i++){
  		cout<<difference_set[i]<<" ";
  	}
    return 0;
}

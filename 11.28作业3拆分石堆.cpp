#include<iostream>
#include<cstdio>
using namespace std;
int input[10000005];
//快排的一个附带函数：交换函数 
void swap(int *a,int *b){
	int c=*b;
	*b=*a;
	*a=c;
}
//进行快速排序（quick sort） 
void quick_sort(int *p,int n) {
    //排序个数只有一个时，终止排序 
	if (n<=1){
    	return;
    }
    //先取最右侧的元素为标尺 
	int t=p[n-1],l=0,r=n-2;
    //使得比标尺大的元素在标尺的右侧，比标尺小的元素在标尺的左侧 
	do{
        //分别从最左侧和最右侧开始遍历查找，一旦在左侧找到比标尺大的数，在右侧找到比标尺小的数，就将它们进行交换 
		for(;r>=l;l++){
       	    if(p[l]>t){
       	        break;
			}
        }
       for(;r>=l;r--){
        	if(p[r]<t){
        		break;
			}
        }
        //换到左右扫描线相遇为止 
		if(r>=l){
        	swap(&p[l],&p[r]);
		}
    }while(r>=l);
    //将标尺交换到中央的一个位置 
	swap(&p[l],&p[n - 1]);
    //之后递归，分别在左侧和右侧进行如此的排序 
	quick_sort(&p[0],l);
    quick_sort(&p[l+1],n-l-1);
}
int main(){
	int N=0;
	long int sum=0;
	cin>>N;
	//输入端 
	for(int i=0;i<N;i++){
		scanf("%d",&input[i]);//注意此处应用scanf进行输入，节省时间 
	}
	quick_sort(input,N);
	//判断石块总数的奇偶性 ，从而进行计算 
	if(N%2==0){
		for(int i=0;i<(N/2);i++){
			sum+=input[i+N/2]-input[i];
		}
	}else{
		for(int i=0;i<(N-1)/2;i++){
			sum+=input[i+(N-1)/2]-input[i];
		}
		sum=sum+input[N-1];
	}
	cout<<sum<<endl;
	return 0;
}

#include<iostream>
using namespace std;
int price[1005];
int discount[1005];
int output[1005];
int discount_goods_num[1005];
double discount_goods_price[1005];
int normal_goods_num[1005];
int normal_goods_price[1005];
double list[1005][2]; 
bool able;
//交换函数 （整数） 
void int_swap(int *a,int *b){
	int c=*b;
	*b=*a;
	*a=c;
}
//交换函数（双精度浮点数） 
void double_swap(double *a,double *b){
	double c=*b;
	*b=*a;
	*a=c;
}
int main(){
	double S=0;//注意将S的数据类型定为double，因为有折扣，所以很可能出现小数 
	int N=0;
	//输入端 
	cin>>S>>N;
	for(int i=0;i<N;i++){
		scanf("%d",&price[i]);
		scanf("%d",&discount[i]);
	}
	//先判断是否至少能购买一件商品 
	for(int i=0;i<N;i++){
		if(discount[i]==0){
			if(S>=price[i]){
				able=true;
			}
		}
		if(discount[i]==1){
			if(S>=0.5*price[i]){
				able=true;
			}
		}
	}
	//一件商品都购买不了 
	if(able==false){
		cout<<"0"<<endl; 
	}else{//至少可以购买一件商品 
	    int count_discount=0,count_normal=0;
	    //将打折与不打折的区分开，分别放到两个数组里面 
		for(int i=0;i<N;i++){
	    	if(discount[i]==1){
	    		count_discount++;
	    		discount_goods_num[count_discount]=i+1;
			    discount_goods_price[count_discount]=0.5*price[i];
	    	}
	    	if(discount[i]==0){
	    		count_normal++;
	    		normal_goods_num[count_normal]=i+1;
                normal_goods_price[count_normal]=price[i]; 
	    	}
	    }
	    //对打折数组进行冒泡排序 
		for(int j=1;j<=count_discount-1;j++){
	    	for(int i=1;i<=count_discount-j;i++){
	    		if(discount_goods_price[i]<discount_goods_price[i+1]){
	    			double_swap(&discount_goods_price[i],&discount_goods_price[i+1]);
	    			int_swap(&discount_goods_num[i],&discount_goods_num[i+1]);
	    		}
	    	}
	    }
	    //修正同价格同打折状态的两商品的序号问题 
		for(int i=2;i<=count_discount;i++){
	    	if(discount_goods_price[i]==discount_goods_price[i-1]){
	    		if(discount_goods_num[i]<discount_goods_num[i-1]){
	    			double_swap(&discount_goods_price[i],&discount_goods_price[i-1]);
	    			int_swap(&discount_goods_num[i],&discount_goods_num[i-1]);
	    		}
	    	}
	    }
		//对不打折数组进行冒泡排序 
		for(int j=1;j<=count_normal-1;j++){
	    	for(int i=1;i<=count_normal-j;i++){
	    		if(normal_goods_price[i]>normal_goods_price[i+1]){
	    			int_swap(&normal_goods_price[i],&normal_goods_price[i+1]);
	    			int_swap(&normal_goods_num[i],&normal_goods_num[i+1]);
	    		}
	    	}
	    }
	    //修正同价格同打折状态的两商品的序号问题 
		for(int i=2;i<=count_normal;i++){
	    	if(normal_goods_price[i]==normal_goods_price[i-1]){
	    		if(normal_goods_num[i]<normal_goods_num[i-1]){
	    			int_swap(&normal_goods_price[i],&normal_goods_price[i-1]);
	    			int_swap(&normal_goods_num[i],&normal_goods_num[i-1]);
	    		}
	    	}
	    }
		//将两数组按先打折后不打折的原则放入心愿清单数组中，该list数组中按照意愿从高到低进行排序 
		for(int i=1;i<=count_discount;i++){
			list[i][0]=discount_goods_num[i];
			list[i][1]=discount_goods_price[i];
		}
		for(int i=count_discount+1;i<=count_discount+count_normal;i++){
			list[i][0]=normal_goods_num[i-count_discount];
			list[i][1]=normal_goods_price[i-count_discount];
		}
		int count=0;
		//按心愿清单顺序进行购买，买不起就顺次到下一件，直到将心愿清单遍历完毕或者钱花光 
		for(int i=1;i<=count_discount+count_normal;i++){
			if(S>=list[i][1]){
				count++;
				S=S-list[i][1];
				output[count]=list[i][0];
			}
		}
		//将序号进行冒泡排序 
		for(int j=1;j<=count-1;j++){
	    	for(int i=1;i<=count-j;i++){
	    		if(output[i]>output[i+1]){
	    			int_swap(&output[i],&output[i+1]);
	    		}
	    	}
	    }	
	    //输出端 
		for(int i=1;i<=count;i++){
	    	cout<<output[i]<<" ";
	    }
	}
	return 0;
}

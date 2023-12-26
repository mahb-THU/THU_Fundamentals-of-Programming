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
//�������� �������� 
void int_swap(int *a,int *b){
	int c=*b;
	*b=*a;
	*a=c;
}
//����������˫���ȸ������� 
void double_swap(double *a,double *b){
	double c=*b;
	*b=*a;
	*a=c;
}
int main(){
	double S=0;//ע�⽫S���������Ͷ�Ϊdouble����Ϊ���ۿۣ����Ժܿ��ܳ���С�� 
	int N=0;
	//����� 
	cin>>S>>N;
	for(int i=0;i<N;i++){
		scanf("%d",&price[i]);
		scanf("%d",&discount[i]);
	}
	//���ж��Ƿ������ܹ���һ����Ʒ 
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
	//һ����Ʒ�������� 
	if(able==false){
		cout<<"0"<<endl; 
	}else{//���ٿ��Թ���һ����Ʒ 
	    int count_discount=0,count_normal=0;
	    //�������벻���۵����ֿ����ֱ�ŵ������������� 
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
	    //�Դ����������ð������ 
		for(int j=1;j<=count_discount-1;j++){
	    	for(int i=1;i<=count_discount-j;i++){
	    		if(discount_goods_price[i]<discount_goods_price[i+1]){
	    			double_swap(&discount_goods_price[i],&discount_goods_price[i+1]);
	    			int_swap(&discount_goods_num[i],&discount_goods_num[i+1]);
	    		}
	    	}
	    }
	    //����ͬ�۸�ͬ����״̬������Ʒ��������� 
		for(int i=2;i<=count_discount;i++){
	    	if(discount_goods_price[i]==discount_goods_price[i-1]){
	    		if(discount_goods_num[i]<discount_goods_num[i-1]){
	    			double_swap(&discount_goods_price[i],&discount_goods_price[i-1]);
	    			int_swap(&discount_goods_num[i],&discount_goods_num[i-1]);
	    		}
	    	}
	    }
		//�Բ������������ð������ 
		for(int j=1;j<=count_normal-1;j++){
	    	for(int i=1;i<=count_normal-j;i++){
	    		if(normal_goods_price[i]>normal_goods_price[i+1]){
	    			int_swap(&normal_goods_price[i],&normal_goods_price[i+1]);
	    			int_swap(&normal_goods_num[i],&normal_goods_num[i+1]);
	    		}
	    	}
	    }
	    //����ͬ�۸�ͬ����״̬������Ʒ��������� 
		for(int i=2;i<=count_normal;i++){
	    	if(normal_goods_price[i]==normal_goods_price[i-1]){
	    		if(normal_goods_num[i]<normal_goods_num[i-1]){
	    			int_swap(&normal_goods_price[i],&normal_goods_price[i-1]);
	    			int_swap(&normal_goods_num[i],&normal_goods_num[i-1]);
	    		}
	    	}
	    }
		//�������鰴�ȴ��ۺ󲻴��۵�ԭ�������Ը�嵥�����У���list�����а�����Ը�Ӹߵ��ͽ������� 
		for(int i=1;i<=count_discount;i++){
			list[i][0]=discount_goods_num[i];
			list[i][1]=discount_goods_price[i];
		}
		for(int i=count_discount+1;i<=count_discount+count_normal;i++){
			list[i][0]=normal_goods_num[i-count_discount];
			list[i][1]=normal_goods_price[i-count_discount];
		}
		int count=0;
		//����Ը�嵥˳����й��������˳�ε���һ����ֱ������Ը�嵥������ϻ���Ǯ���� 
		for(int i=1;i<=count_discount+count_normal;i++){
			if(S>=list[i][1]){
				count++;
				S=S-list[i][1];
				output[count]=list[i][0];
			}
		}
		//����Ž���ð������ 
		for(int j=1;j<=count-1;j++){
	    	for(int i=1;i<=count-j;i++){
	    		if(output[i]>output[i+1]){
	    			int_swap(&output[i],&output[i+1]);
	    		}
	    	}
	    }	
	    //����� 
		for(int i=1;i<=count;i++){
	    	cout<<output[i]<<" ";
	    }
	}
	return 0;
}

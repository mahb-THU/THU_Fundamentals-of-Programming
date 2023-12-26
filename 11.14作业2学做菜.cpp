#include<iostream>
using namespace std;
//做交换 
void swap(int *a,int *b){
	int c=*b;
	*b=*a;
	*a=c;
}
//选择两个数字中的最小值
int min2(int a,int b){
	int min;
	if(a>=b){
		swap(&a,&b);
	}
	return a;
}
//选择三个数字中的最小值
int min3(int a,int b,int c){
	if(a>=b){
		swap(&a,&b);
	}
	if(a>=c){
		swap(&a,&c);
	}
	return a;
}
//选择四个数字中的最小值
int min4(int a,int b,int c,int d){
	if(a>=b){
		swap(&a,&b);
	}
	if(a>=c){
		swap(&a,&c);
	}
	if(a>=d){
		swap(&a,&d);
	}
	return a;
} 
int main(){
	int a,b,c,d;
	int m1=0,m2=0,m3=0,m4=0,m5=0;
	cin>>a>>b>>c>>d;
    //判断第一道菜能否做及做的数量 
    if((a>=2)&&(b>=1)&&(d>=2)){
    	m1=min3(a/2,b,d/2);
    	a=a-m1*2;
    	b=b-m1;
    	d=d-m1*2;
    }
	//判断第二道菜能否做及做的数量 
	if((a>=1)&&(b>=1)&&(c>=1)&&(d>=1)){
		m2=min4(a,b,c,d);
		a=a-m2;
		b=b-m2;
		c=c-m2;
		d=d-m2;
	} 
	//判断第三道菜能否做及做的数量 
	if((c>=2)&&(d>=1)){
		m3=min2(c/2,d);
		c=c-m3*2;
		d=d-m3;
	} 
	//判断第四道菜能否做及做的数量 
	if(b>=3){
		m4=b/3;
		b=b-m4*3;
	}
	//判断第五道菜能否做及做的数量 
	if((a>=1)&&(d>=1)){
		m5=min2(a,d);
		a=a-m5;
		d=d-m5;
	}
	cout<<m1<<endl<<m2<<endl<<m3<<endl<<m4<<endl<<m5;
    return 0;
}














































#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n=0,i=2,product=1,k=0,isprime=0;
	cin>>n;
	//判断数字是A类型还是B类型 
	if(n%4==0){//该处的分支运算可将时间复杂度减少一半 
         for(i=2;i<=sqrt(n);i=i+2){//将时间复杂度开平方，这在有关素数的程序设计中很重要 
		     if(n%(i*i)==0){
			 isprime=1;
			 break;
		     }
         }
	}else{
		 for(i=3;i<=sqrt(n);i=i+2){
		     if(n%(i*i)==0){
			 isprime=1;
			 break;
	         }
	     }
	} 
	if(isprime==1){
		 cout<<"B"<<endl;
	}else{
		 cout<<"A"<<endl;
	}
	//对所给数字进行分解质因数 
	k=n;
	for( i=2;i<=sqrt(n);i++){//将时间复杂度开平方，这在有关素数的程序设计中很重要 
	     if(n%i==0){
			 cout<<i<<endl;
			 n=n/i;
		   	 product=i*product;
			 i--;
	     	}
	}
	cout<<k/product<<endl;//对上述分解质因数方案的修正 
    return 0;

}

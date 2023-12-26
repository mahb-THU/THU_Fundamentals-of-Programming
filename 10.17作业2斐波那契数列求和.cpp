//写代码，与做数学题一样需要读题。虽然代码的写作很依靠与数学功底，但是解决一些特定的数学问题时，不能完全依赖于数学而脱离了计算机本身的性质，这样写出的代码是容易产生错误的，或者说你的数学思维被出题人利用了 
#include<iostream>
using namespace std;
//掌握将循环合二为一的技巧，这样会大大降低时间复杂度 
int main(){
	int sum=2,a=1,b=1,fibonacci=0,tmp=0,n=0,c=0,d=0;
	const int p=1000000007;//提前规定常量，不要因为常量过长而影响后续代码的美观度 
	cin>>n;
	//排除前两次特殊循环 
	if(n==1){
		sum=1;
	}else if(n==2){
		sum=2;
	}else{
		for(int i=3;i<=n;i++){
			fibonacci=(a+b)%p;//注意取余的位置与值，要严格遵守题中的规定  
			//做交换 
			tmp=b;
			b=fibonacci;
			a=tmp;
			//简化代码长度，避免产生歧义 
			c=sum%p;
			d=fibonacci%p;
			if(c<=d){
				sum=(sum+fibonacci)%p;//注意取余的位置与值，要严格遵守题中的规定 
			} else{
		    	sum=(sum-fibonacci)%p;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}

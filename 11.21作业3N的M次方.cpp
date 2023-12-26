#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
//the array is too huge;preventing the array from exceeding the range
//otherwise it might cause "runtime error" 
int input[100001][3];
int main(){
	int T;
	cin>>T;//T groups of exprimental examples 
	for(int i=1;i<=T;i++){
    	for(int j=1;j<=2;j++){
    		//using "scanf" but not "cin" to prevent "time limit exceeded"
			scanf("%d",&input[i][j]);//when j=1,it indicates "N"(BASE);when j=2,it indicates "M"(EXPONENT) 
    	}
    }
	for(int i=1;i<=T;i++){
	    double base,power;
	    double number;
		base=input[i][1];
		power=input[i][2];
		//calculating logarithm:for calculating the top three places of the "big number"
		number=power*log10(base);
		//when the example is less than 100,it'll be processed paticularly
		if(number<2){
			int sum=1;
			for(int i=1;i<=power;i++){
				sum*=base;
			}
			//special outputing form
			if(sum<10){
				cout<<"0"<<"0"<<sum<<" "<<"0"<<"0"<<sum<<endl;
			} 
			//special outputing form
			if((sum>=10)&&(sum<=99)){
				cout<<"0"<<sum<<" "<<"0"<<sum<<endl;
			}
		}
		//when the example is more than 100,it should be processed normally
		if(number>=2){
		    double front=0;
		    double outputfront=0;
			//we need the fractional part of the logarithm,because the integer part of the logarithm has nothing to do with the result
			front=number-(int)number;
			outputfront=pow(10,front)*100;
			int result=1;
			int base2,power2;
			//coverting "double" to "int"
			base2=(int)base%1000;//the base MUST be as base mod1000,otherwise,it might have exceeded the range of the"int"
			power2=(int)power;
			//FAST EXPINENNT(it should be remembered)
			while(power2>0){
				if((power2%2)==0){
					power2=power2/2;
					base2=base2*base2%1000;
				}
				else if((power2%2)!=0){
					power2=power2-1;
					result=result*base2%1000;
					power2=power2/2;
					base2=base2*base2%1000;
				}
		    }
			//equation:(a*b)%p=[(a%p)*(b%p)]%p
			result=result%1000;
			cout<<(int)outputfront<<" ";
			//special outputing form
			if(result<10){
				cout<<"0"<<"0"<<result<<endl;
			} 
			if((result>=10)&&(result<=99)){
				cout<<"0"<<result<<endl;
			}
			if((result>=100)&&(result<=999)){
				cout<<result<<endl;
			}
		} 
	} 
	return 0;
}

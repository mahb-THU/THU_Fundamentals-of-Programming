#include<iostream>
using namespace std;
//ȷ��λ������ 
int digit(int n){
	int ret=0;
    do{
    	n/=10;
    	ret++;
    }while(n>0);
    return ret;
}
//�ж���������ż�������� 
int isprime(int m){
	int beprime=1;
	for(int i=3;i*i<=m;i=i+2){
		if(m%i==0){
			beprime=0;
			break;
		}
	}
	return beprime;
}
//��λ��,��λ��������
int change(int f){
	int f1=0;
	if(digit(f)==2){
		f1=10*(f%10)+f/10;
	}else{
		f1=100*(f%100%10)+10*((f/10)%10)+f/100;
	}
	return f1;
} 
//��ȡ���������飬��Ϊһ�ڸ����ֺ�����һ���ڱ������������Ҫ��Ϊ������ר��������
//ͬʱ����������������Ҫ�����ʣ���ֻ��11��һ��ż��λ�Ļ�������������֤��������ż��λ�Ļ����������Ա�11���� 
int main(){
	int palind[9993];
	palind[0]=5;
	palind[1]=7;
	palind[2]=11;//0+2
	for(int i=1;i<=9;i++){
		for(int j=0;j<=9;j++){
			palind[10*(i-1)+j+1+2]=101*i+10*j;
		}
	}//2+90,digit=3
	for(int p=10;p<=99;p++){
		for(int q=0;q<=9;q++){
			palind[10*(p-10)+q+1+2+90]=1000*p+100*q+change(p);
		}
	}//2+90+900,digit=5
	for(int s=100;s<=999;s++){
		for(int t=0;t<=9;t++){
			palind[10*(s-100)+t+1+2+90+900]=10000*s+1000*t+change(s);
		}
	}//2+90+900+9000,digit=7
//���������ж��Ƿ�������,�Ƿ��ڷ�Χ�ڲ���� ��ͬʱ�ų�ż���Ļ�������Ϊ���ǲ����������� 
    int a=0,b=0;
	cin>>a>>b;
	//int cnt=0;
	for(int z=0;z<9993;z++){
    	if((palind[z]>=a)&&(palind[z]<=b)&&(palind[z]%2!=0)&&(isprime(palind[z])==1)){
    		cout<<palind[z]<<endl;
			//cnt++; 
    	}
	}
	//cout<<cnt<<endl; 
	return 0;
} 









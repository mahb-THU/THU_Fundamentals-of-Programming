#include<iostream>
using namespace std;
bool isprime[11000001];
int mat[726518]={0};
int main(){
	 //��ɸ���11000000�ڵ�������������������ϵı��
	int count=0;
	for(int i=2;i<=11000000;i++){
		isprime[i]=true;
	}
	for(int i=2;i*i<=11000000;i++){
		if(isprime[i]==true){
			for(int j=i*i;j<=11000000;j+=i){
				isprime[j]=false;
			}
		}
	}
	for(int i=2;i<=11000000;i++){
		if(isprime[i]==true){
			count++;
			mat[count]=i;
		}
	}
    //�������ݶ� 
	int T=0,r=0;
	cin>>T>>r;
    int judge[T+1];
	for(int i=1;i<=T;i++){
		cin>>judge[i];
	}
	//��11000000�ڹ���ȡ��726517���������������ǰ���С˳�����������mat�У���ʱ��ʱԼΪ70ms
	//���۰��ȡ�ķ�ʽȡ����ӽ������� 
	for(int i=1;i<=T;i++){
		int low=1,high=726517,middle=0,anw=0,sign=0;
		//�ȼ������������������ڼ�����ͬʱ����Χ��С 
		while(low<=high){
			middle=(high+low)/2;
			if(judge[i]==mat[middle]){
				if((judge[i]-mat[middle-1])<=(mat[middle+1]-judge[i])){
					anw=mat[middle-1];
					sign=1;
					break;
				}else{
					anw=mat[middle+1];
					sign=1;
					break;
				}
			}else if(judge[i]<mat[middle]){
				high=middle-1;
			}else{
				low=middle+1;
			}
		} 
		if(sign==1){
			if(((anw-judge[i])>=-r)&&((anw-judge[i])<=r)){//ע����ȡ���ȡ֮����߼���ϵ 
				cout<<"T"<<endl;
			}else{
				cout<<"F"<<endl;
			}
		}
		//��ӽ�����ֻ�����ֿ��ܣ���middle-1������middle������middle+1�� 
		if(sign!=1){//ע����ȡ���ȡ֮����߼���ϵ 
			if((((mat[middle-1]-judge[i])>=-r)&&((mat[middle-1]-judge[i])<=r))||(((mat[middle]-judge[i])>=-r)&&((mat[middle]-judge[i])<=r))||(((mat[middle+1]-judge[i])>=-r)&&((mat[middle+1]-judge[i])<=r))){
				cout<<"T"<<endl;
			}else{
				cout<<"F"<<endl;
			}
		}
	} 
	return 0; 
}

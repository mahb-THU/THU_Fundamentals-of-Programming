#include<iostream>
using namespace std;
int main(){
	//���벿�֣������������ 
	int n=0;
	cin>>n;
	int carpet[n][4];
	for(int i=0;i<n;i++){
		for(int j=0;j<4;j++){
			cin>>carpet[i][j];
		}
	}
	int loc[2];
	for(int k=0;k<2;k++){
		cin>>loc[k];
	}
	//�������������
	int num=-1;
	//ע������ı�����⣬�ӡ�0����ʼ�ǹؼ� 
	for(int p=0;p<n;p++){
		if((loc[0]>=carpet[p][0])&&(loc[0]<=(carpet[p][0]+carpet[p][2]))&&(loc[1]>=carpet[p][1])&&(loc[1]<=(carpet[p][1]+carpet[p][3]))){
			num=p+1;
		}
	} 
	cout<<num<<endl;
	return 0;
}

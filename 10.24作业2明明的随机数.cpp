#include<iostream>
using namespace std;
int main(){
	int N=0,num=0;//�������� 
	cin>>N;
    int input[N];
	for(int i=0;i<N;i++){
		cin>>input[i];
	}
    //��Ϊ��������㷽ʽ�����������е����ݽ���ͳ�ƣ������Ҫ��Ҳ�����ʣ��������Ƕ������������ĵ�һ˼ά�ǽ����ǽ��д��� 
	int count[1001]={0};
	for(int j=0;j<N;j++){
		int k=1;
		k=input[j];
		count[k]++;
	} 
	//�����ظ����Ĺ��̣�������ͳ�ƵĻ������Եø���� 
	num=N;
	for(int h=1;h<=1000;h++){
		if(count[h]>1){
			num=num-count[h]+1;
		}
	}
	//����������Ĺ��̣�����������������ͳ�ƺ�ѭ�������Ļ����ϣ��ԵñȽϼ� 
	int output[num],cnt=-1;
	for(int g=1;g<=1000;g++){
	    if(count[g]>0){
			cnt++;
			output[cnt]=g;
		}
	}
	//���һ�����������ֵĹ��̣���Ҫ��ѭ��������� 
	cout<<num<<endl;
	for(int f=0;f<num;f++){
		cout<<output[f]<<" ";
	}
	return 0;

}

#include<iostream>
#include<cstring>
using namespace std;
int main(){
	//����ˣ�ע������ַ��������� 
	char str1[11];//ע���ַ���ĩ�ˡ�/0���Ĵ��ڣ��ڿ��ַ���ʱ���࿪Ϊ�� 
	char str2[11];
	cin>>str1;
   	cin>>str2;
    //��ʼ���ж����ַ����ȵ��ж�
	int count1=0,count2=0;
	if(strlen(str1)!=strlen(str2)){
		cout<<1<<endl;
	}else{//��ʼ���еڶ������͵��ж� 
		for(int i=0;i<strlen(str1);i++){
			if(str1[i]==str2[i]){
				count1++;
			}
		}
		if(count1==strlen(str1)){
			cout<<2<<endl;
		}else{//��ʼ���е��������͵��ж� 
			for(int j=0;j<strlen(str1);j++){
				if((str1[j]==str2[j])||(str1[j]==(str2[j]+32))||(str1[j]==(str2[j]-32))){
					count2++;
				}
			}
			if(count2==strlen(str1)){
				cout<<3<<endl;
			}else{//�����е��������͵��ж� 
				cout<<4<<endl;
			}
		}
	}
	//��Ϊ�������͹����˼����ȫ����ͬʱ�����������־��в��ݽ��Ĺ�ϵ�����Բ���Ƕ����ʽ��if���ȥ��� 
    return 0;
}

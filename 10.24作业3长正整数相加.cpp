#include<iostream>
#include<string.h>
using namespace std;
//���뺯������ȡ���ߵļ���ֵ 
int max(int a,int b){
	if(a>=b){
		return a;
	}else{
		return b;
	}
}
int main(){
	int length1=0,length2=0,lengthmax=0;
	//ע���������֮���ת����Ϊ������ָ��������������á�char�����͵ĺ���������ٽ���char��ת��Ϊ��int���ĺ��� 
	char str1[100];
	char str2[100];
	char str3[100];
	//���뵹����ַ�����������Ӳ���ȷ����������ȫ���Խ�������֮����ͨ�����������������
	//ע������ķ�����ѭ�����д���ģ�������±�Ҳ���д���ģ����߾��д��򣬱��������һ�㣬�������������� 
	char abstr1[100];
	char abstr2[100];
    //ע�����룺%s���ַ����ı�׼����ģʽ 
	scanf("%s %s",&str1,&str2);
	length1=strlen(str1);
	length2=strlen(str2);
    lengthmax=max(length1,length2);
    //���ɣ��ַ������� 
	for(int i=0;i<length1;i++){
    	abstr1[i]=str1[length1-1-i]-'0';
    }
	//���ɣ��ַ������� 
	for(int j=0;j<length2;j++){
    	abstr2[j]=str2[length2-1-j]-'0';
    }
    int carry=0;
	for(int k=0;k<=lengthmax;k++){
    	str3[k]=(abstr1[k]+abstr2[k]+carry)%10;
        carry=(abstr1[k]+abstr2[k]+carry)/10;	
    }
    if(str3[lengthmax]=='1'){
    	for(int f=lengthmax;f>=0;f--){
    		cout<<int(str3[f]);//ע������ת�� 
    	}
    }else{
    	for(int f=lengthmax-1;f>=0;f--){
    		cout<<int(str3[f]);//ע������ת�� 
    	}
    }
    return 0;
}
//strcpy���ַ������� 
//strcmp���ַ����Ƚ� 
//strcat���ַ�������
//strlen: �ַ�������
//ע��Ҫ��������#include<cstring> 


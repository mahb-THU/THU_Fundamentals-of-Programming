#include<iostream>
#include<cstring>
using namespace std; 
int main(){
	//�����ж�ģʽ����Ҫ�жϵ��ַ���������ˣ� 
	int judge[4];
	char input[101]; //ע�⣺��Ϊ��\0���Ĵ��ڣ�����char���͵ı���һ��Ҫ����101�� 
	for(int i=1;i<=3;i++){
		cin>>judge[i];
	}
	cin>>input;
	//���в��֣����и����ж�
	//ע�����������ж�֮����߼���ϵ��������������֮��仯�����ι�ϵ
	//���ڶ�������⣬����е�����ѧ�е����ƣ��̶�һ���������仯�����ģ����ϵع̶����Ӷ��ɹ��������е����
	//����������һ�ֲַ�ν��з������۵ķ��� 
	for(int i=0;i<strlen(input);i++){
		if((input[i]=='-')&&((input[i-1]-'a')>=0)&&((input[i+1]-'a')<=25)&&((input[i-1]-'a')<(input[i+1]-'b'))){//Ϊ���ţ������ΪСд��ĸ����� 
			if(judge[3]==1){
				for(int j=1;j<=((input[i+1]-'b')-(input[i-1]-'a'));j++){
					if(judge[1]==1){
						for(int k=1;k<=judge[2];k++){
							cout<<char(int(input[i-1])+j);
						}
					}else if(judge[1]==2){
						for(int k=1;k<=judge[2];k++){
							cout<<char(int(input[i-1])+j-32);
					    }
					}else{
						for(int k=1;k<=judge[2];k++){
							cout<<"*";
				    	}
				    }
			    }
			}
			if(judge[3]==2){
				for(int j=((input[i+1]-'b')-(input[i-1]-'a'));j>=1;j--){
					if(judge[1]==1){
						for(int k=1;k<=judge[2];k++){
							cout<<char(int(input[i-1])+j);
						}
					}else if(judge[1]==2){
						for(int k=1;k<=judge[2];k++){
							cout<<char(int(input[i-1])+j-32);
			            }
					}else{
						for(int k=1;k<=judge[2];k++){
							cout<<"*";
					    }
			    	}
			    }
		    }
		}else if((input[i]=='-')&&((input[i-1]-'0')>=0)&&((input[i+1]-'0')<=9)&&((input[i-1]-'0')<(input[i+1]-'1'))){//Ϊ���ţ������Ϊ���ֵ���� 
			if(judge[3]==1){
				for(int j=1;j<=((input[i+1]-'b')-(input[i-1]-'a'));j++){
					if((judge[1]==1)||(judge[1]==2)){
						for(int k=1;k<=judge[2];k++){
							cout<<char(int(input[i-1])+j);
						}
					}else{
						for(int k=1;k<=judge[2];k++){
							cout<<"*";
					    }
				    }
			    }
		    }
			if(judge[3]==2){
				for(int j=((input[i+1]-'b')-(input[i-1]-'a'));j>=1;j--){
					if((judge[1]==1)||(judge[1]==2)){
						for(int k=1;k<=judge[2];k++){
							cout<<char(int(input[i-1])+j);
						}
					}else{
						for(int k=1;k<=judge[2];k++){
							cout<<"*";
					    }  
				    }
			    }
        	}
		}else if((input[i]=='-')&&((input[i-1]-'0')+1==(input[i+1]-'0'))){//Ϊ���ţ��Ҳ��ַ�Ϊ���ĺ�� 
			continue;
		}else if((input[i]=='-')&&((input[i-1]-'0')>=(input[i+1]-'0'))){//Ϊ���ţ��Ҳ��ַ���ASC��С�ڵ������ 
			cout<<"-";
		}else{//��Ϊ���ţ�������� 
			cout<<input[i];
		}
    }
    return 0;
}

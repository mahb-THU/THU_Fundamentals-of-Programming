#include<iostream>
#include<cstring>
using namespace std;
int main(){
	//输入端，注意对于字符串的输入 
	char str1[11];//注意字符串末端“/0”的存在，在开字符串时，多开为宜 
	char str2[11];
	cin>>str1;
   	cin>>str2;
    //开始进行对于字符长度的判断
	int count1=0,count2=0;
	if(strlen(str1)!=strlen(str2)){
		cout<<1<<endl;
	}else{//开始进行第二种类型的判断 
		for(int i=0;i<strlen(str1);i++){
			if(str1[i]==str2[i]){
				count1++;
			}
		}
		if(count1==strlen(str1)){
			cout<<2<<endl;
		}else{//开始进行第三种类型的判断 
			for(int j=0;j<strlen(str1);j++){
				if((str1[j]==str2[j])||(str1[j]==(str2[j]+32))||(str1[j]==(str2[j]-32))){
					count2++;
				}
			}
			if(count2==strlen(str1)){
				cout<<3<<endl;
			}else{//最后进行第四种类型的判断 
				cout<<4<<endl;
			}
		}
	}
	//因为四种类型构成了集体的全部，同时后三种类型又具有层层递进的关系，所以采用嵌套形式的if语句去描绘 
    return 0;
}

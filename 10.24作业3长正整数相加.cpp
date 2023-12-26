#include<iostream>
#include<string.h>
using namespace std;
//引入函数：求取两者的极大值 
int max(int a,int b){
	if(a>=b){
		return a;
	}else{
		return b;
	}
}
int main(){
	int length1=0,length2=0,lengthmax=0;
	//注意变量类型之间的转换，为避免用指针混淆出错，建议用“char”类型的函数到最后，再将“char”转换为“int”的函数 
	char str1[100];
	char str2[100];
	char str3[100];
	//引入倒序的字符串，正序相加不能确定个数，完全可以将其逆序，之后最通过遍历将其逆序回来
	//注意逆序的方法：循环是有次序的，数组的下标也是有次序的，两者均有次序，便可利用这一点，进行逆序及逆逆序 
	char abstr1[100];
	char abstr2[100];
    //注意输入：%s是字符串的标准输入模式 
	scanf("%s %s",&str1,&str2);
	length1=strlen(str1);
	length2=strlen(str2);
    lengthmax=max(length1,length2);
    //技巧：字符串倒序 
	for(int i=0;i<length1;i++){
    	abstr1[i]=str1[length1-1-i]-'0';
    }
	//技巧：字符串倒序 
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
    		cout<<int(str3[f]);//注意最后的转化 
    	}
    }else{
    	for(int f=lengthmax-1;f>=0;f--){
    		cout<<int(str3[f]);//注意最后的转化 
    	}
    }
    return 0;
}
//strcpy：字符串复制 
//strcmp：字符串比较 
//strcat：字符串连接
//strlen: 字符串长度
//注意要引函数库#include<cstring> 


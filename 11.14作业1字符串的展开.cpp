#include<iostream>
#include<cstring>
using namespace std; 
int main(){
	//输入判断模式及需要判断的字符串（输入端） 
	int judge[4];
	char input[101]; //注意：因为“\0”的存在，所以char类型的变量一定要开到101个 
	for(int i=1;i<=3;i++){
		cin>>judge[i];
	}
	cin>>input;
	//运行部分：进行各种判断
	//注意搞清楚三个判断之间的逻辑关系，明白三个变量之间变化的主次关系
	//对于多变量问题，编程中的与数学中的类似，固定一个变量，变化其他的，不断地固定，从而成功遍历所有的情况
	//此题体现了一种分层次进行分类讨论的方法 
	for(int i=0;i<strlen(input);i++){
		if((input[i]=='-')&&((input[i-1]-'a')>=0)&&((input[i+1]-'a')<=25)&&((input[i-1]-'a')<(input[i+1]-'b'))){//为减号，两侧均为小写字母的情况 
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
		}else if((input[i]=='-')&&((input[i-1]-'0')>=0)&&((input[i+1]-'0')<=9)&&((input[i-1]-'0')<(input[i+1]-'1'))){//为减号，两侧均为数字的情况 
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
		}else if((input[i]=='-')&&((input[i-1]-'0')+1==(input[i+1]-'0'))){//为减号，右侧字符为左侧的后继 
			continue;
		}else if((input[i]=='-')&&((input[i-1]-'0')>=(input[i+1]-'0'))){//为减号，右侧字符按ASC码小于等于左侧 
			cout<<"-";
		}else{//不为减号，正常输出 
			cout<<input[i];
		}
    }
    return 0;
}

#include<iostream>
#include<cstring>
using namespace std;
	//数组要尽可能地多开，避免因为某种复杂原因造成“runtime error”，多开的标准为：在估计得的最大范围之上再加5-10个，这样基本可以能避免数组溢出造成的错误。 
	//数组开的过大时，要将局部变量化为全局变量，避免出现运行错误。 
	//注意本题的输入模式，体现了一种在线操作的特点 
	char op[5][30];
    char openorder[5][30];
    char FileName[1005][30];
   	char FileType[1005][30];
   	char FileInfo[1005][30];
   	char output[1005][30];
int main(){
   	int count=1;
	int number=0;	
	//共有三条执行命令，其中“exit”只作为判断条件出现，实际上，有操作效力的命令只有“create”和“open” 
	while(strcmp(op[0],"exit")!=0){
		cin>>op[0];
	    //判断命令行，此处为命令“create” 
		if(strcmp(op[0],"create")==0){
		    //此处可以认为运用count与数组实现了一种特殊的数据结构
			//该处数据结构的目的：实现对于“create”输入的累积，并对重复的用新的将之前的覆盖掉 
			cin>>FileName[count]>>FileType[count]>>FileInfo[count]; 
			for(int i=1;i<count;i++){
				if(strcmp(FileName[count],FileName[i])==0){
					//关于strcpy函数，可以认为是字符串的一种快速的赋值操作，相当于“int”之中的“=” 
					strcpy(FileType[i],FileType[count]);
					strcpy(FileInfo[i],FileInfo[count]);
				}
			}
		    count++;
		}
		//判断命令行，此处为命令“open” 
		if(strcmp(op[0],"open")==0){
			cin>>openorder[0];
			char judge[2]="1";
		    //定义判断符号，以判断是否最终找到“数据块”（之前找到的都是“快捷方式”） 
			while(strcmp(judge,"1")==0){
				for(int i=1;i<count;i++){
				    //查找成功，之后更新数据，再进行进一步的查找 
					if(strcmp(FileName[i],openorder[0])==0){
				    	strcpy(judge,FileType[i]);
				    	strcpy(openorder[0],FileInfo[i]);
				    	//查找成功一次之后，就进行退出
						//防止因为openorder的变化而导致查找错误
						//关于break的使用：能用则用，一来节省时间，二来避免产生了混淆错误 
						break;
					}
			    } 
			}	
			strcpy(output[number],openorder[0]);
			number++;
		}
	}
	for(int i=0;i<number;i++){
		cout<<output[i]<<endl;
	}
	return 0;
}

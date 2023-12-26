#include<iostream>
#include<cstring>
//但凡是涉及到字符串的题应该直接提前引用好<cstring>头文件，因为这种情况下一般都会用到 
using namespace std;
int main(){
	char operation[2][20];
	char enlisttype[2000][15];
	char enlistname[2000][15];
	int exceptance[2000];
	char removename[2][15];
	char refinetype[2][15];
	char cleanuptype[2][15];
	int T=0;
	int count=1;
	//注意本题的输入方式，每输入一句操作一次，体现一种在线操作的感觉 
	cin>>T;
	//由T确定的最终的命令行数，即在一道题中首先明确循环进行的次数或循环的终止条件 
	for(int i=1;i<=T;i++){
		cin>>operation[0];
		//根据输入的operation的不同，来通过if分支语句确定其分别对应的命令行 
	    //对应ENLIST的命令行，对于“书堆”中的书进行累积 
		if(strcmp(operation[0],"ENLIST")==0){
			cin>>enlisttype[count]>>enlistname[count]>>exceptance[count];
			count++;
		}
	    //对应REMOVE的命令行，对于“书堆”中某个书名的书进行删除
		//表达删除的方式：统一将即将被删除的书的期望值调为“-1”，以表示其被删除 
		if(strcmp(operation[0],"REMOVE")==0){
			cin>>removename[0];
			for(int i=1;i<count;i++){
				if(strcmp(removename[0],enlistname[i])==0){
					exceptance[i]=-1;
				}
			} 
		}
	    //对应REFINE的命令行，对于“书堆”中某个类型的书进行精炼，即只留下一本期望值最高的书
		//处理思路：在已有数组的最后另开一个位置，将期望值最高的书挑选出来并将它的全部信息置于这个位置，同时，将其他此类别的书期望值置为“-1” 
		if(strcmp(operation[0],"REFINE")==0){
			cin>>refinetype[0];
			int existtype=0;
			exceptance[count]=-1;
			for(int i=1;i<count;i++){
				if(strcmp(refinetype[0],enlisttype[i])==0){
					existtype=1;
					if(exceptance[i]>exceptance[count]){
						exceptance[count]=exceptance[i];
						strcpy(enlisttype[count],enlisttype[i]);
						strcpy(enlistname[count],enlistname[i]);
					}
					exceptance[i]=-1;
				}
			}
			if(existtype==1){
				count++;
			}
		}
		//对应CLEANUP的命令行，对于“书堆”中某个类型的书进行全部的删除，然后将其他剩下的书进行排序
		//处理思路。先进行删除（使其期望值为-1），再进行书的排序 
		if(strcmp(operation[0],"CLEANUP")==0){
			cin>>cleanuptype[0];
			int midexceptance=-1;
			char midenlisttype[20]="AAAAAAAAAAAAAAA";
			char midenlistname[20]="AAAAAAAAAAAAAAA";
			for(int i=1;i<count;i++){
				if(strcmp(cleanuptype[0],enlisttype[i])==0){
					exceptance[i]=-1;
				}
			}
			//冒泡排序法加上结构体的同步复制 
			for(int i=1;i<=count-2;i++){
		        for(int j=1;j<=count-1-i;j++){
		        	if(exceptance[j]>exceptance[j+1]){
				        midexceptance=exceptance[j];
				        exceptance[j]=exceptance[j+1];
				        exceptance[j+1]=midexceptance;
				        strcpy(midenlisttype,enlisttype[j]);
				        strcpy(enlisttype[j],enlisttype[j+1]);
				        strcpy(enlisttype[j+1],midenlisttype);
				        strcpy(midenlistname,enlistname[j]);
				        strcpy(enlistname[j],enlistname[j+1]);
				        strcpy(enlistname[j+1],midenlistname);
			        }
		        }
        	}
		}
	}
    int number=0;
	char outputtype[2000][15];
	char outputname[2000][15];
	int outputexceptance[2000];		
	//将期望大于0的书集中在一个数组之中 
	for(int i=count-1;i>=1;i--){
		if(exceptance[i]>0){
			strcpy(outputtype[number],enlisttype[i]);
		    strcpy(outputname[number],enlistname[i]);
		    outputexceptance[number]=exceptance[i];
		    number++;
		}
	}
	//输出端，根据上文整理后的进行输出 
	char judge[10]="NULL";
	if(number==0){
		cout<<judge;
	} 
	if((number>0)&&(number<3)){
		for(int i=0;i<number;i++){
			cout<<outputtype[i]<<" "<<outputname[i]<<" "<<outputexceptance[i]<<endl;
		}
	}
	if(number>=3){
		for(int i=0;i<=2;i++){
			cout<<outputtype[i]<<" "<<outputname[i]<<" "<<outputexceptance[i]<<endl;
		}
	}
	return 0; 
}

#include<iostream>
#include<cstring>
//�������漰���ַ�������Ӧ��ֱ����ǰ���ú�<cstring>ͷ�ļ�����Ϊ���������һ�㶼���õ� 
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
	//ע�Ȿ������뷽ʽ��ÿ����һ�����һ�Σ�����һ�����߲����ĸо� 
	cin>>T;
	//��Tȷ�������յ���������������һ������������ȷѭ�����еĴ�����ѭ������ֹ���� 
	for(int i=1;i<=T;i++){
		cin>>operation[0];
		//���������operation�Ĳ�ͬ����ͨ��if��֧���ȷ����ֱ��Ӧ�������� 
	    //��ӦENLIST�������У����ڡ���ѡ��е�������ۻ� 
		if(strcmp(operation[0],"ENLIST")==0){
			cin>>enlisttype[count]>>enlistname[count]>>exceptance[count];
			count++;
		}
	    //��ӦREMOVE�������У����ڡ���ѡ���ĳ�������������ɾ��
		//���ɾ���ķ�ʽ��ͳһ��������ɾ�����������ֵ��Ϊ��-1�����Ա�ʾ�䱻ɾ�� 
		if(strcmp(operation[0],"REMOVE")==0){
			cin>>removename[0];
			for(int i=1;i<count;i++){
				if(strcmp(removename[0],enlistname[i])==0){
					exceptance[i]=-1;
				}
			} 
		}
	    //��ӦREFINE�������У����ڡ���ѡ���ĳ�����͵�����о�������ֻ����һ������ֵ��ߵ���
		//����˼·������������������һ��λ�ã�������ֵ��ߵ�����ѡ������������ȫ����Ϣ�������λ�ã�ͬʱ��������������������ֵ��Ϊ��-1�� 
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
		//��ӦCLEANUP�������У����ڡ���ѡ���ĳ�����͵������ȫ����ɾ����Ȼ������ʣ�µ����������
		//����˼·���Ƚ���ɾ����ʹ������ֵΪ-1�����ٽ���������� 
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
			//ð�����򷨼��Ͻṹ���ͬ������ 
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
	//����������0���鼯����һ������֮�� 
	for(int i=count-1;i>=1;i--){
		if(exceptance[i]>0){
			strcpy(outputtype[number],enlisttype[i]);
		    strcpy(outputname[number],enlistname[i]);
		    outputexceptance[number]=exceptance[i];
		    number++;
		}
	}
	//����ˣ��������������Ľ������ 
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

#include<iostream>
#include<cstring>
using namespace std;
	//����Ҫ�����ܵض࿪��������Ϊĳ�ָ���ԭ����ɡ�runtime error�����࿪�ı�׼Ϊ���ڹ��Ƶõ����Χ֮���ټ�5-10�����������������ܱ������������ɵĴ��� 
	//���鿪�Ĺ���ʱ��Ҫ���ֲ�������Ϊȫ�ֱ���������������д��� 
	//ע�Ȿ�������ģʽ��������һ�����߲������ص� 
	char op[5][30];
    char openorder[5][30];
    char FileName[1005][30];
   	char FileType[1005][30];
   	char FileInfo[1005][30];
   	char output[1005][30];
int main(){
   	int count=1;
	int number=0;	
	//��������ִ��������С�exit��ֻ��Ϊ�ж��������֣�ʵ���ϣ��в���Ч��������ֻ�С�create���͡�open�� 
	while(strcmp(op[0],"exit")!=0){
		cin>>op[0];
	    //�ж������У��˴�Ϊ���create�� 
		if(strcmp(op[0],"create")==0){
		    //�˴�������Ϊ����count������ʵ����һ����������ݽṹ
			//�ô����ݽṹ��Ŀ�ģ�ʵ�ֶ��ڡ�create��������ۻ��������ظ������µĽ�֮ǰ�ĸ��ǵ� 
			cin>>FileName[count]>>FileType[count]>>FileInfo[count]; 
			for(int i=1;i<count;i++){
				if(strcmp(FileName[count],FileName[i])==0){
					//����strcpy������������Ϊ���ַ�����һ�ֿ��ٵĸ�ֵ�������൱�ڡ�int��֮�еġ�=�� 
					strcpy(FileType[i],FileType[count]);
					strcpy(FileInfo[i],FileInfo[count]);
				}
			}
		    count++;
		}
		//�ж������У��˴�Ϊ���open�� 
		if(strcmp(op[0],"open")==0){
			cin>>openorder[0];
			char judge[2]="1";
		    //�����жϷ��ţ����ж��Ƿ������ҵ������ݿ顱��֮ǰ�ҵ��Ķ��ǡ���ݷ�ʽ���� 
			while(strcmp(judge,"1")==0){
				for(int i=1;i<count;i++){
				    //���ҳɹ���֮��������ݣ��ٽ��н�һ���Ĳ��� 
					if(strcmp(FileName[i],openorder[0])==0){
				    	strcpy(judge,FileType[i]);
				    	strcpy(openorder[0],FileInfo[i]);
				    	//���ҳɹ�һ��֮�󣬾ͽ����˳�
						//��ֹ��Ϊopenorder�ı仯�����²��Ҵ���
						//����break��ʹ�ã��������ã�һ����ʡʱ�䣬������������˻������� 
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
